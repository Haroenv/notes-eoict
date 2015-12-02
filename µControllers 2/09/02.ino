#include <Wire.h>
#define DS1307_ID 0x68
#define K1 9
#define K2 10
#define K3 11
uint8_t second =      00; //0-59
uint8_t minute =      41; //0-59
uint8_t hour =        20; //0-23
uint8_t dow =          3; //1-7
uint8_t day =          2; //1-31
uint8_t month =       12; //1-12
uint8_t year  =       15; //0-99
boolean edited = false;
  
void setup() {
  delay(1000);
  pinMode(K1,INPUT_PULLUP);
  pinMode(K2,INPUT_PULLUP);
  pinMode(K3,INPUT_PULLUP);
  pciSetup(K1);
  pciSetup(K2);
  pciSetup(K3);
  pinMode(2, INPUT);                    // Test of the SQW pin, D2 = INPUT
  digitalWrite(2, HIGH);                // Test of the SQW pin, D2 = Pullup on
  Serial.begin(9600);
  Wire.begin();
  startClock();
  setTime();
}

void pciSetup(byte pin) {
  * digitalPinToPCMSK(pin) |= bit (digitalPinToPCMSKbit(pin));
  PCIFR |= bit (digitalPinToPCICRbit(pin));
  PCICR |= bit (digitalPinToPCICRbit(pin));
}

ISR (PCINT0_vect) {
  if (digitalRead(K1) == LOW) {
    if (second < 59) {
      second++;     
    } else {
      second = 0;
      minute++; 
    }
    edited = true;
  }
  if (digitalRead(K2) == LOW) {
    if (minute < 59) {
      minute++;
    } else {
      minute = 0;
      hour++;
    }
    edited = true;
  }
  if (digitalRead(K3) == LOW) {
    if (hour < 23) {
      hour++;
    } else {
      hour = 0;
      day++;
    }
    edited = true;
  }
}

void setTime(){

  Wire.beginTransmission(DS1307_ID);
  Wire.write(0x00); //stop Oscillator

  Wire.write(dec2bcd(second));
  Wire.write(dec2bcd(minute));
  Wire.write(dec2bcd(hour));
  Wire.write(dec2bcd(dow));
  Wire.write(dec2bcd(day));
  Wire.write(dec2bcd(month));
  Wire.write(dec2bcd(year-2000));
  Wire.write(0x00); //start 

  Wire.endTransmission();

}

void getTime() {
  Wire.beginTransmission(DS1307_ID);
  Wire.write((uint8_t)0x00);
  Wire.endTransmission();
  Wire.requestFrom(DS1307_ID, 7);       // request secs, min, hour, dow, day, month, year
  second = bcd2dec(Wire.read() & 0x7f);// aquire seconds...
  minute = bcd2dec(Wire.read());     // aquire minutes
  hour = bcd2dec(Wire.read());       // aquire hours
  dow = bcd2dec(Wire.read());        // aquire dow (Day Of Week)
  dow--;  //  correction from RTC format (1..7) to lib format (0..6). Useless, because it will be overwritten
  day = bcd2dec(Wire.read());       // aquire day
  month = bcd2dec(Wire.read());      // aquire month
  year = bcd2dec(Wire.read());       // aquire year...
  year = year + 2000;                   // ...and assume that we are in 21st century!
}

void startClock() {
  Wire.beginTransmission(DS1307_ID);
  Wire.write((uint8_t)0x00);  // Register 0x00 holds the oscillator start/stop bit
  Wire.endTransmission();
  Wire.requestFrom(DS1307_ID, 1);
  second = Wire.read() & 0x7f;  // save actual seconds and AND sec with bit 7 (start/stop bit) = clock started
  Wire.beginTransmission(DS1307_ID);
  Wire.write((uint8_t)0x00);
  Wire.write((uint8_t)second);   // write seconds back and start the clock
  Wire.endTransmission();
}

uint8_t bcd2dec(uint8_t val)  {
// Convert binary coded decimal to normal decimal numbers
  return ( (val/16*10) + (val%16) );
}

uint8_t dec2bcd(uint8_t num){
// Convert normal decimal numbers to binary coded decimal
  return ((num/10 * 16) + (num % 10));
}

void loop() {
  if (edited) {
    setTime();
    edited = false;
  }
  getTime();
  Serial.print(day);
  Serial.print("/");
  Serial.print(month);
  Serial.print("/");
  Serial.print(year);
  Serial.print(" ");
  Serial.print(hour);
  Serial.print(":");
  Serial.print(minute);
  Serial.print(":");
  Serial.println(second);
  delay(1000);
}
