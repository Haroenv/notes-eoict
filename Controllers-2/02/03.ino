void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(1));
}

void loop() {
  for (int i = 0; i < 5; i++) {
    Serial.println(random(10, 20));
  }
  while(true);
}
