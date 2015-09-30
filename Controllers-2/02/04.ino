byte randnr;
const byte ledArray [] = {2, 3, 4, 5};

void setup() {
  pinMode(1,INPUT);
  randomSeed(analogRead(1));
  for (int i = 0; i < 5; i++) {
    pinMode(ledArray[i],OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  randnr = byte(random(0,15));
  Serial.println(randnr);
  for (int i = 0; i < 5; i++) {
    digitalWrite(ledArray[i],bitRead(randnr,i));
  }
  delay(50);
}
