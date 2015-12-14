#define DS1307_ID 0x68
#include <Wire.h>
#define DS1307_I2C_ADRES 0x68
uint8_t second =      00; //0-59
uint8_t minute =      41; //0-59
uint8_t hour =        20; //0-23
uint8_t dow =          3; //1-7
uint8_t day =          2; //1-31
uint8_t month =       12; //1-12
uint8_t year  =       15; //0-99

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();
  setTime();
}

void loop() {
  // put your main code here, to run repeatedly:
  getTime();
  Serial.print(dow);
  Serial.print(" ");
  Serial.print(hour);
  Serial.print(":");
  Serial.print(minute);
  Serial.print(":");
  Serial.print(second);
  Serial.println();
  
  delay(1000);
}

byte decToBcd(byte val) {
  return ((val/10*16) + ( val%10));
}

byte bcdToDec(byte val) {
  return ((val/16*10) + (val%16));
}

void getTime()
{
  Wire.beginTransmission(DS1307_ID);
  Wire.write((uint8_t)0x00);
  Wire.endTransmission();
  Wire.requestFrom(DS1307_ID, 7);       // request secs, min, hour, dow, day, month, year
  second = bcdToDec(Wire.read() & 0x7f);// aquire seconds...
  minute = bcdToDec(Wire.read());     // aquire minutes
  hour = bcdToDec(Wire.read());       // aquire hours
  dow = bcdToDec(Wire.read());        // aquire dow (Day Of Week)
  dow--;  //  correction from RTC format (1..7) to lib format (0..6). Useless, because it will be overwritten
  day = bcdToDec(Wire.read());       // aquire day
  month = bcdToDec(Wire.read());      // aquire month
  year = bcdToDec(Wire.read());       // aquire year...
  year = year + 2000;                   // ...and assume that we are in 21st century!
}

void setTime()
{
  Wire.beginTransmission(DS1307_I2C_ADRES);
  Wire.write((byte) 0x00);
  Wire.write(decToBcd(second));
  Wire.write(decToBcd(minute));
  Wire.write(decToBcd(hour));
   Wire.write(decToBcd(dow));
  Wire.write(decToBcd(day));
  Wire.write(decToBcd(month));
  Wire.write(decToBcd(year-2000));
  Wire.write(0x00); //start 
  Wire.endTransmission();
}
