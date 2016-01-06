#include <Wire.h>

#define DS1307_I2C_ADDRESS 0x68
#define HOUR 10
#define PMNOTATIE 0x40

int uur;
int minuut;
int second;
int uurL;
int minuutL;
int secondL;
bool am;

void setup() {
  Serial.begin(9600);
  // SET AM/PM
  Wire.begin();
  Wire.beginTransmission(DS1307_I2C_ADDRESS);
  Wire.write(HOUR | PMNOTATIE);
  Wire.endTransmission();
  uur = 11;
  minuut = 59;
  second = 58;
  uurL = 0;
  minuutL = 0;
  secondL = 0;
  am = false;
  setTime();
}
  
void loop() {
  getTime();
  Serial.print(uurL);
  Serial.print(" : ");
  Serial.print(minuutL);
  Serial.print(" : ");
  Serial.print(secondL);
  if (uurL & 0x40) {
      Serial.print(" ");
      if (am) {
        Serial.print("AM");
      }
      else {
        Serial.print("PM");
      }
  }
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
  if(true) {
    am = false;
  }
  else {
    am = true;
  }
}

byte decToBcd(byte val) {
  return ((val / 10 * 16) + (val % 10));
}

byte bcdToDec(byte val) {
  return ((val / 16 * 10) + (val % 16));
}

