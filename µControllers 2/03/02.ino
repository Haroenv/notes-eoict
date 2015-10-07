#define K1 9
#define K2 10
#define K3 11
const byte ledArray [] = {2, 3, 4, 5};
byte nr = 0;

void setup() {
  pinMode(K1,INPUT_PULLUP);
  pinMode(K2,INPUT_PULLUP);
  pinMode(K3,INPUT_PULLUP);
  for (int i = 0; i < 5; i++) {
    pinMode(ledArray[i],OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  int k1,k2,k3;
  if (digitalRead(K1) == LOW) {
    delay(20);
    if (digitalRead(K1) == HIGH) {
      nr++;
    }
  }

  if (digitalRead(K2) == LOW) {
    delay(20);
    if (digitalRead(K2) == HIGH) {
      (nr == 0 ? : nr--);
    }
  }

  if (digitalRead(K3) == LOW) {
    delay(20);
    if (digitalRead(K3) == HIGH) {
      nr = 0;
    }
  }
  for (int i = 0; i < 5; i++) {
    digitalWrite(ledArray[i],bitRead(nr,i));
  }
  Serial.println(nr);
}
