#include <EEPROM.h>
int a = 0;
int value;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 16; i++) {
    EEWrite(i,i+2000);
  }
}

void EEWrite(int addr,int toWrite) {
  addr *= 2;
  byte valLow = toWrite;
  byte valHigh = toWrite >> 8;
  EEPROM.write(addr,valHigh);
  EEPROM.write(addr+1,valLow);
}

int EERead(int toRead) {
  toRead *= 2;
  return EEPROM.read(toRead)*256 + EEPROM.read(toRead+1);
}

void loop() {
  value = EERead(a);

  Serial.print(a);
  Serial.print("\t");
  Serial.print(value);
  Serial.println();

  a = a + 1;

  if (a == 15)
    a = 0;

  delay(500);
}
