void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(1)); //bijna-random getal instellen, truc met licht instellen
}
  

void loop() {
  for (int teller = 0; teller < 5; teller++) {
    Serial.println(random(1,20));
  }

  while (1); //opvangen
}
