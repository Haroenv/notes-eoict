int r = 0;
const byte ledArray[] = {2,3,4,5};

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(1));
  for (int x = 0; x < sizeof(ledArray); x++) {
    pinMode(ledArray[x],OUTPUT);
  }
}
  

void loop() {
  r = random(0,15);
  Serial.println(r);
  for (int t = 0; t < 4; t++) {
    digitalWrite(ledArray[t],bitRead(r,t));
  }
  delay(2000);
}
