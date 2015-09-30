void setup() {
  pinMode(1,INPUT);
  Serial.begin(9600);
  randomSeed(analogRead(1));
}

void loop() {
  for (int i = 0; i < 5; i++) {
    Serial.println(random(0, 20));
  }
  while(true);
}
