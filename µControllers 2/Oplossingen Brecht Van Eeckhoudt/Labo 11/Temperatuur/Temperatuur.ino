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
int secondsToTemp;

int gelezen = 0;
int berekend = 0;
int berekendeTemperatuur = 0;
int cijfer = 0;

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
  pinMode(14,INPUT);
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
  if (vlag == 1) {
      setTime();
      vlag = 0;
    }
    
  if (secondsToTemp == 4) {
    secondsToTemp = 0;
    disp[2] = 18;
    disp[3] = 12;
    //TM1636.cpp:
    //static int8_t TubeTab[] = {0x3f,0x06,0x5b,0x4f,
    //                           0x66,0x6d,0x7d,0x07,
    //                           0x7f,0x6f,0x77,0x7c,
    //                           0x39,0x5e,0x79,0x71,
    //                           0x40,0x00,0x63};//0~9,A,b,C,d,E,F,"-","°"  
    gelezen = analogRead(14);
    berekend = ((long)(1023 - gelezen) * 10000) / gelezen;
    berekendeTemperatuur = (gelezen / 1024.0) * 50;
    disp[0] = berekendeTemperatuur / 10;
    disp[1] = (berekendeTemperatuur - (int)(berekendeTemperatuur / 10) * 10);
    point = false;
    tm1636.point(point);
    tm1636.display(disp);
  }
  else {
    //flash the colon
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
    
    getTime();
    
    disp[0] = uur / 10;
    disp[1] = uur % 10;
    disp[2] = minuut / 10;
    disp[3] = minuut % 10;
    tm1636.display(disp);
  }

  secondsToTemp++;
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


