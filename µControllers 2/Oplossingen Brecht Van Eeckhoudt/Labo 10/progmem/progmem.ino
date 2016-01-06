#include <avr/pgmspace.h>

const char myString[] PROGMEM  = {"Hallo ik ben Brecht"};
char myChar;


void setup() {
  Serial.begin(9600);
  // length of the string
  int leng = strlen_P(myString);
  // read the string
  for (int i = 0; i < leng; i++) {
    myChar =  pgm_read_byte_near(myString + i);
    Serial.print(myChar);
  }
  Serial.println();
}

void loop() {

}
