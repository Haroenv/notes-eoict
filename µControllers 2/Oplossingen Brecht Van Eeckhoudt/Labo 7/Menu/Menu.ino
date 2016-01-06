const byte ledArray[] = {2,3,4,5};
byte incomingByte;
byte incomingByte2;

void setup() {
  Serial.begin(115200,SERIAL_8O2);
  for (int x = 0; x < sizeof(ledArray); x++) {
    pinMode(ledArray[x],OUTPUT);
  }
  printMenu();
}

void printMenu() {
  Serial.println("Toets de letter in van uw keuze:");
  Serial.println("a. alle LED's aan");
  Serial.println("b. alle LED's uit");
  Serial.println("c. individuele LED aansturen");
}
  
void loop() {
  incomingByte = Serial.read();
  switch (incomingByte) {
    case 'a':
      for (int x = 0; x < sizeof(ledArray); x++) {
       digitalWrite(ledArray[x],HIGH);
      }
      break;
    case 'b':
      for (int x = 0; x < sizeof(ledArray); x++) {
       digitalWrite(ledArray[x],LOW);
      }
      break;
    case 'c':
      Serial.println("  geef het nummer van de LED gevolgd door A (aan) of U (uit), bv: 2A");
      while (!(Serial.available() > 0)) {
        // Wait
      }
      incomingByte = Serial.read();
      while (!(Serial.available() > 0)) {
        // Wait
      }
      incomingByte2 = Serial.read();
      if (incomingByte2 == 'a') {
        digitalWrite(incomingByte - 47,HIGH);
        incomingByte = 0;
        incomingByte2 = 0;
        printMenu();
      }
      if (incomingByte2 == 'u') {
        digitalWrite(incomingByte - 47,LOW);
        incomingByte = 0;
        incomingByte2 = 0;
        printMenu();
      }
      if (incomingByte != 0) {
        printMenu();
      }
      break;
    default: 
    break;
  }
}
