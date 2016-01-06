const byte ledArray[] = {2,3,4,5};

void setup() {
 for (int x = 0; x < sizeof(ledArray); x++) {
          pinMode(ledArray[x],OUTPUT);
      }
}

void loop() {
      for (int x = 0; x < sizeof(ledArray); x++) {
          digitalWrite(ledArray[x],HIGH);
          delay(500);
          digitalWrite(ledArray[x],LOW);
     }
}

