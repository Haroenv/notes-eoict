#include <EEPROM.h>

byte SRAM[1024];

void setup() {
  Serial.begin(9600);
  // Schrijven
  //for (int i = 0; i < 10; i++) {
  //  EEPROM.write(i,i + 1);
  //}
  //for (int i = 0; i < 10; i++) {
  //  SRAM[i] = i + 1;
  //}
  //EEPROM.write(1030,100);
  //SRAM[2054] = 100;


  // Lezen
  for (int i = 0; i < 10; i++) {
    Serial.print("EEPROM ");
    Serial.print(i);
    Serial.print(": ");
    Serial.print(EEPROM.read(i));
    Serial.println();
  }
  for (int i = 0; i < 10; i++) {
    Serial.print("SRAM ");
    Serial.print(i);
    Serial.print(": ");
    Serial.print(SRAM[i]);
    Serial.println();
  }
  Serial.print("EEPROM 1030: ");
  Serial.print(EEPROM.read(1030));
  Serial.println();
  Serial.print("SRAM 2054: ");
  Serial.print(SRAM[2054]);
  Serial.println();
}
  
void loop() {
  
}
