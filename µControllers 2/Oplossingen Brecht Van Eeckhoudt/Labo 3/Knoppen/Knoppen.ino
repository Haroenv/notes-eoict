#define K1 9
#define K2 10
#define K3 11

void setup() {
  pinMode(K1, INPUT_PULLUP);
  pinMode(K2, INPUT_PULLUP);
  pinMode(K3, INPUT_PULLUP);
  Serial.begin(9600);
}
  

void loop() {
  if (digitalRead(K1) == LOW && digitalRead(K2) == HIGH && digitalRead(K3) == HIGH) Serial.println("K1");
  if (digitalRead(K2) == LOW && digitalRead(K1) == HIGH && digitalRead(K3) == HIGH) Serial.println("K2");
  if (digitalRead(K3) == LOW && digitalRead(K1) == HIGH && digitalRead(K2) == HIGH) Serial.println("K3");
  delay(100);
}
