#define K3 11

const byte ledArray[] = {2,3,4,5};
int teller = 0;

void setup() {
  pinMode(K3, INPUT_PULLUP);
  for (int x = 0; x < sizeof(ledArray); x++) {
    pinMode(ledArray[x],OUTPUT);
  }
}
  
void loop() {
  if (digitalRead(K3) == LOW) {
    teller++;
  }
  delay(100);
  if (teller > 0) {
    
  }
}
