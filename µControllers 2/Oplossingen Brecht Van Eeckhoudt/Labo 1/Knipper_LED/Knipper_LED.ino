int LED1 = 2;

void setup() {
  pinMode(LED1,OUTPUT);
  digitalWrite(LED1,HIGH);
}

void loop() {
  delay(500);
  digitalWrite(LED1,LOW);
  delay(500);
  digitalWrite(LED1,HIGH);
}
