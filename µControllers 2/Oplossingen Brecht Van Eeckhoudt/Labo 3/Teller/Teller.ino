#define K1 9
#define K2 10
#define K3 11

int t = 0;
const byte ledArray[] = {2,3,4,5};

void setup() {
  pinMode(K1, INPUT_PULLUP);
  pinMode(K2, INPUT_PULLUP);
  pinMode(K3, INPUT_PULLUP);
  Serial.begin(9600);
  for (int x = 0; x < sizeof(ledArray); x++) {
    pinMode(ledArray[x],OUTPUT);
  }
}
  

void loop() {
  if (digitalRead(K1) == LOW && t > 0) {
    t--;
  }
  
  if (digitalRead(K2) == LOW && t < 15) {
    t++;
  }
  
  if (digitalRead(K3) == LOW) {
    t = 0;
  }

  if (digitalRead(K1) == LOW || digitalRead(K2) == LOW || digitalRead(K3) == LOW) {
    for (int x = 0; x < 4; x++) {
      digitalWrite(ledArray[x],bitRead(t,x));
    }
  }
  
  delay(400);
}
