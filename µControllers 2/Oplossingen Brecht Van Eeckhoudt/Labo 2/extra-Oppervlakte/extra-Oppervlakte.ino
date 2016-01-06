int teller = 1;
float r = 0;

void setup() {
  Serial.begin(9600);
  pinMode(2,OUTPUT);
}
  

void loop() {
  //hoelang duurd het voor de berekening van de straal via oscilloscoop
  digitalWrite(2,1); //via led off and on kijken hoeveel ms delay
  r = (3.14 * teller * teller);
  digitalWrite(2,0);
  r = (3.14 * teller * teller);
}
