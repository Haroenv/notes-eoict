#include <Wire.h>

#define DS1307_I2C_ADDRESS 0x68
#define K1 9
#define K2 10
#define K3 11

int uur;
int minuut;
int second;

volatile int vlag = 0; // synchroniseren, kan in 2 methodes aangepast worden

void pciSetup(byte pin) {
  *digitalPinToPCMSK(pin) |= bit (digitalPinToPCMSKbit(pin)); // enable pin
  PCIFR |= bit (digitalPinToPCICRbit(pin)); // clear any outstanding interrupt
  PCICR |= bit (digitalPinToPCICRbit(pin)); // enable interrupt for the group
}

void setup() {
  pinMode(K1, INPUT_PULLUP);
  pinMode(K2, INPUT_PULLUP);
  pinMode(K3, INPUT_PULLUP);
  pciSetup(K1); // interrupt K1 inschakelen
  pciSetup(K2); // interrupt K2 inschakelen
  pciSetup(K3); // interrupt K3 inschakelen
  Serial.begin(9600);
  Wire.begin();
  uur = 0;
  minuut = 0;
  second = 0;
}
  
void loop() {
  if (vlag == 1) {
    setTime();
    vlag = 0;
  }
  getTime();
  Serial.print(uur);
  Serial.print(" : ");
  Serial.print(minuut);
  Serial.print(" : ");
  Serial.print(second);
  Serial.println();
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
    if (digitalRead(K1) == LOW) {
      if (uur < 23) {
        uur++;
      }
      else {
        uur = 0;
     }
    }
    if (digitalRead(K2) == LOW) {
      if (minuut < 60) {
        minuut++;
      }
      else {
        minuut = 1;
      }
    }
    if (digitalRead(K3) == LOW ) {
      if (second < 59) {
        second++;
      }
      else {
        second = 0;
      }
    }
    if (second < 59) {
      second++;
    }
    else {
      second = 0;
    }
  }
  vlag = 1;
}

