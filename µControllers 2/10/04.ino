#include <avr/pgmspace.h>
const char progmemString[] PROGMEM  = {"TEKST HIER ;) ;)"};
int k;
char myChar;

void setup() {
  Serial.begin(9600);

  int len = strlen_P(progmemString);
  for (k = 0; k < len; k++) {
    myChar =  pgm_read_byte_near(progmemString + k);
    Serial.print(myChar);
  }

  Serial.println();
}

void loop() {
}
