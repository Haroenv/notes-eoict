const char progmemString[] PROGMEM  = {"TEKST HIER ;) ;)"};
char myChar;

void setup() {
  Serial.begin(9600);

  int len = strlen_P(progmemString);
  for (int i = 0; i < len; i++) {
    myChar =  pgm_read_byte_near(progmemString + i);
    Serial.print(myChar);
  }

  Serial.println();
}
void loop(){}
