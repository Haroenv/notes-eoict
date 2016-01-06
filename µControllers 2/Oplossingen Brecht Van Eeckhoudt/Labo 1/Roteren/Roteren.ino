void setup() {
  for (int x = 2; x <= 5; x++) {
    pinMode(x,OUTPUT);
  }
}

void loop() {
  for (int x=2; x <= 5; x++) {
    digitalWrite(x-1,LOW);
    digitalWrite(x,HIGH);
    delay(500);
  }
  digitalWrite(5,LOW);
}
