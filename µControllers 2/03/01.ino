#define K1 9
#define K2 10
#define K3 11

void setup() {
  pinMode(K1,INPUT_PULLUP);
  pinMode(K2,INPUT_PULLUP);
  pinMode(K3,INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  int k1 = digitalRead(K1);
  int k2 = digitalRead(K2);
  int k3 = digitalRead(K3);
  if (k1 == LOW || k2 == LOW || k2 == LOW ) {
    Serial.println("a button is pressed.");
    delay(1000);
  }
}
