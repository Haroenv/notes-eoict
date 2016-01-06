#include <Wire.h>

#define DS1307_I2C_ADDRESS 0x68

int uur;
int minuut;
int second;
int uurL;
int minuutL;
int secondL;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  uur = 23;
  minuut = 59;
  second = 30;
  uurL = 0;
  minuutL = 0;
  secondL = 0;
  setTime();
}
  
void loop() {
  getTime();
  Serial.print(uurL);
  Serial.print(" : ");
  Serial.print(minuutL);
  Serial.print(" : ");
  Serial.print(secondL);
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
  secondL = bcdToDec(Wire.read() & 0x7f); // bit 7 skippen
  minuutL = bcdToDec(Wire.read());
  uurL = bcdToDec(Wire.read() & 0x3f); // am/pm
}

byte decToBcd(byte val) {
  return ((val / 10 * 16) + (val % 10));
}

byte bcdToDec(byte val) {
  return ((val / 16 * 10) + (val % 16));
}

