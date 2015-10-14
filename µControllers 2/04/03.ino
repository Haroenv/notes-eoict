#define K1 9
#define K2 10
#define K3 11
byte led = 5;
byte brt;

void pciSetup(byte pin) {
  * digitalPinToPCMSK(pin) |= bit (digitalPinToPCMSKbit(pin));
  PCIFR |= bit (digitalPinToPCICRbit(pin));
  PCICR |= bit (digitalPinToPCICRbit(pin));
}

void setup() {
  pinMode(K1,INPUT_PULLUP);
  pinMode(K2,INPUT_PULLUP);
  pinMode(K3,INPUT_PULLUP);
  pinMode(led,OUTPUT);
  pciSetup(K1);
  pciSetup(K2);
  pciSetup(K3);
  analogWrite(led,255);
}

ISR (PCINT0_vect) {
  unsigned long previousInt = 0;
  unsigned long now = millis();
  if(now - previousInt >  20){
    if (digitalRead(K1) == LOW) {
      if(brt <= 230) brt += 25;
    }

    if (digitalRead(K2) == LOW) {
      brt = 0;
    }

    if (digitalRead(K3) == LOW) {
      if(brt >= 25) brt -= 25;
    }
  }
  previousInt = now;
}

void loop() {
  analogWrite(led,brt);
}
