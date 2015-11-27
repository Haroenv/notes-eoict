const byte leds[] = {2, 3, 4, 5};
short cand = 0;
void setup() {
  Serial.begin(9600);
  pinMode(15,INPUT);
  for (byte i = 0; i < sizeof(leds) / sizeof(byte); i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  cand = analogRead(15);
  Serial.println(cand);
  for (int i = 0; i < 5; i++) {
    digitalWrite(leds[i],LOW);
  }
  if (cand > 180) {
    digitalWrite(leds[0],HIGH);
  }
  if (cand > 360) {
  digitalWrite(leds[1],HIGH);
  }
  if (cand > 540) {
  digitalWrite(leds[2],HIGH);
  }
  if (cand > 720) {
  digitalWrite(leds[3],HIGH);
  }
}
