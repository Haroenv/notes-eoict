int teller = 0;

void setup() {
  Serial.begin(9600);
}
  

void loop() {
  Serial.print("Een cirkel met straal ");
  Serial.print(teller);
  Serial.print(" heeft een oppervlakte van ");
  Serial.print(3.14 * teller * teller);
  Serial.println("");
  teller++;
  delay(1000);
}
