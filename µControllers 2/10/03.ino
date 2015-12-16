
#define DS1307_ID 0x68
#include <Wire.h>
#define DS1307_I2C_ADRES 0x68
#define BEGIN_NUMBERS 0x08

byte a = 0;
int value;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  for (uint8_t i = 0; i < 60; i++) {
    RTCWrite(i,i+1);
  }
}

void RTCWrite(int addr,uint8_t toWrite) {
  Wire.beginTransmission(DS1307_ID);
  Wire.write((uint8_t)(BEGIN_NUMBERS + addr));
  Wire.write(toWrite);
  Wire.write(0x00); //start 
  Wire.endTransmission();
}

int RTCRead(uint8_t toRead) {
  Wire.beginTransmission(DS1307_ID);
  Wire.write((uint8_t)(BEGIN_NUMBERS + toRead));
  Wire.endTransmission();
  Wire.requestFrom(DS1307_ID, 1);
  Wire.read();
}

void loop() {
  value = RTCRead(a);

  Serial.print(a);
  Serial.print("\t");
  Serial.print(value);
  Serial.println();

  a = a + 1;

  if (a == 60)
    a = 0;
}
