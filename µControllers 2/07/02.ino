char input;
const byte leds[] = {2, 3, 4, 5};
byte number;
char mode;

void setup() {
  Serial.begin(115200, SERIAL_8O2);
  Serial.println("Toets de letter in van uw keuze:");
  Serial.println("a. alle LED's aan");
  Serial.println("b. alle LED's uit");
  Serial.println("c. individuele LED aansturen");
  for (byte i = 0; i < sizeof(leds) / sizeof(byte); i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  input = Serial.read();
  if (input == 'a') {
    for (byte i = 0; i < sizeof(leds) / sizeof(byte); i++) {
      digitalWrite(leds[i], HIGH);
    }
  } else if (input == 'b') {
    for (byte i = 0; i < sizeof(leds) / sizeof(byte); i++) {
      digitalWrite(leds[i], LOW);
    }
  } else if (input == 'c') {
    Serial.println("geef het nummer van de LED gevolgd door A (aan) of U (uit), bv. 2A:");
    while (Serial.available() == 0) {}
    number = (byte)Serial.read() - 49;
    if (number >= 0 && number < 4) {
      Serial.print(number+1);
      while (Serial.available() == 0) {}
      mode = Serial.read();
      Serial.println(mode);
      if (mode == 'U' || mode == 'A') {
        digitalWrite(leds[number], mode == 'U' ? LOW : HIGH);
      }
    } else {
      Serial.println("Deze LED bestaat niet");
    }
  }
}
