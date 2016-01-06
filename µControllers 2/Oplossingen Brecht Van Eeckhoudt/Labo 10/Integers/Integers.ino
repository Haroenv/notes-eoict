#include <EEPROM.h>

int val;
int addr;
byte low;
byte high;
int value;

void setup() {
  value = 1999;
  Serial.begin(9600);
  for (int i = 0; i <= 30; i += 2) {
    value++;
    writeInt(i, value);
  }
  Serial.println();
  for (int i = 0; i <= 30; i += 2) {
    Serial.print(readInt(i));
    Serial.println();
  }
}
  
void loop() {
  
}

int readInt(int addr) {
  low = EEPROM.read(addr);
  high = EEPROM.read(addr + 1);
  return high << 8 | low;
}

void writeInt(int addr, int val) {
  low = val & 0xFF;
  high = (val >> 8) & 0xFF;
  EEPROM.write(addr, low);
  EEPROM.write(addr + 1, high);
}

