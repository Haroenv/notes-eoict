const byte ledArray[] = {2,3,4,5};
int richting = 1;
int teller = 0;

void setup() {
  for (int x = 0; x < sizeof(ledArray); x++) {
    pinMode(ledArray[x],OUTPUT);
  }
}

void loop() {
  digitalWrite(ledArray[teller],HIGH);
  delay(500);
  digitalWrite(ledArray[teller],LOW);
  teller += richting;
  if (teller == 3) {
    richting = -1;
  }
  if (teller == 0) {
    richting = 1;
  }
}
