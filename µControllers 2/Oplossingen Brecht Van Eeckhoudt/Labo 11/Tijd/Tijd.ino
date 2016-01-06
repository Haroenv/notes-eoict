#include <Wire.h>
#include <TM1636.h>

#define DS1307_I2C_ADDRESS 0x68
//#define K1 9
#define K2 10
#define K3 11

// Declare a TM1636 Class object that control the 4-digit display
TM1636 tm1636(7,8);
int8_t disp[4];

int uur;
int minuut;
int second;
bool point;

volatile int vlag = 0; // synchroniseren, kan in 2 methodes aangepast worden

void pciSetup(byte pin) {
  *digitalPinToPCMSK(pin) |= bit (digitalPinToPCMSKbit(pin)); // enable pin
  PCIFR |= bit (digitalPinToPCICRbit(pin)); // clear any outstanding interrupt
  PCICR |= bit (digitalPinToPCICRbit(pin)); // enable interrupt for the group
}

void setup() {
  //pinMode(K1, INPUT_PULLUP);
  pinMode(K2, INPUT_PULLUP);
  pinMode(K3, INPUT_PULLUP);
  //pciSetup(K1); // interrupt K1 inschakelen
  pciSetup(K2); // interrupt K2 inschakelen
  pciSetup(K3); // interrupt K3 inschakelen
  Wire.begin();
  
  //uur = 23;
  //minuut = 59;
  //second = 30;
  //setTime();

  // Set the default brightness is BRIGHT_TYPICAL and clear the display
  tm1636.init();
}
  
void loop() {
  //enable the colon
  if (point) {
    tm1636.point(point);
    tm1636.display(disp);
    point = false;
  }
  else {
    tm1636.point(point);
    tm1636.display(disp);
    point = true;
  }
  
  if (vlag == 1) {
    setTime();
    vlag = 0;
  }
  getTime();
  
  disp[0] = uur / 10;
  disp[1] = uur % 10;
  disp[2] = minuut / 10;
  disp[3] = minuut % 10;
  tm1636.display(disp);

  delay(1000);
}

void setTime() {
  Wire.beginTransmission(DS1307_I2C_ADDRESS);
  Wire.write((byte)0x00); // 0 in bit 7 start de klok
  Wire.write(decToBcd(second)); 
  Wire.write(decToBcd(minuut));
  Wire.write(decToBcd(uur));
  Wire.endTransmission();
}

void getTime() {
  Wire.beginTransmission(DS1307_I2C_ADDRESS);
  Wire.write((byte)0x00);
  Wire.endTransmission();
  Wire.requestFrom(DS1307_I2C_ADDRESS, 7); // 7 bytes opvragen
  second = bcdToDec(Wire.read() & 0x7f); // bit 7 skippen
  minuut = bcdToDec(Wire.read());
  uur = bcdToDec(Wire.read() & 0x3f); // am/pm
}

byte decToBcd(byte val) {
  return ((val / 10 * 16) + (val % 10));
}

byte bcdToDec(byte val) {
  return ((val / 16 * 10) + (val % 16));
}

// handle pin change interrupt for D8 -> D13 here
ISR (PCINT0_vect) { 
  if (vlag != 1) {
    if (digitalRead(K3) == LOW) {
      if (uur < 23) {
        uur++;
      }
      else {
        uur = 0;
     }
    }
    if (digitalRead(K2) == LOW) {
      if (minuut < 59) {
        minuut++;
      }
      else {
        minuut = 0;
      }
    }
    //if (digitalRead(K1) == LOW ) {
    //  if (second < 59) {
    //    second++;
    //  }
    //  else {
    //    second = 0;
    //  }
    //}
    if (second < 59) {
      second++;
    }
    else {
      second = 0;
    }
  }
  vlag = 1;
}


