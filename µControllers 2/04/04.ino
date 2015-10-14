#define K1 9
#define K2 10
#define K3 11

const byte ledArray [] = {2, 3, 4, 5};
const byte led = 2;

void setup() {
  pinMode(K1,INPUT_PULLUP);
  pinMode(K2,INPUT_PULLUP);
  pinMode(K3,INPUT_PULLUP);
  for (int i = 0; i < 5; i++) {
    pinMode(ledArray[i],OUTPUT);
  }
}

void loop() {
  if (digitalRead(K3) == LOW) {
    delay(1000);
    if(digitalRead(K3) == LOW){
      for (int i = 0; i < 5; i++) {
        digitalWrite(ledArray[i],!digitalRead(ledArray[i]));
      }
    } else {
      digitalWrite(led, !digitalRead(led));
    }
  }
}
