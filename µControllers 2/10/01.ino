#include <EEPROM.h>
int a = 0;
int value;
byte SRAM[1024];

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 10; i++) {
    //EEPROM.write(i,i+1);
  }
  //EEPROM.write(1030,100); // mag niet xd
  //SRAM[2054] = 100; // mag ook al niet ;)
  Serial.println(SRAM[2054]);
  Serial.println(EEPROM.read(1030));
  Serial.println(SRAM[6]);
  Serial.println(EEPROM.read(6));
  Serial.println();
}

void loop() {
  value = EEPROM.read(a);

  Serial.print(a);
  Serial.print("\t");
  Serial.print(value);
  Serial.println();

  a = a + 1;

  if (a == 10)
    a = 0;

  delay(500);
}
