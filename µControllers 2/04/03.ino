#define K1 9
#define K2 10
#define K3 11

const byte ledArray [] = {2, 3, 4, 5};

void pciSetup(byte pin) {
  * digitalPinToPCMSK(pin) |= bit (digitalPinToPCMSKbit(pin));
  PCIFR |= bit (digitalPinToPCICRbit(pin));
  PCICR |= bit (digitalPinToPCICRbit(pin));
}

void setup() {
  pinMode(K1,INPUT_PULLUP);
  pinMode(K2,INPUT_PULLUP);
  pinMode(K3,INPUT_PULLUP);
  for (int i = 0; i < 5; i++) {
    pinMode(ledArray[i],OUTPUT);
  }
  pciSetup(K1);
  pciSetup(K2);
  pciSetup(K3);
}

ISR (PCINT0_vect) {
  if (digitalRead(K1) == LOW) {

  }

  if (digitalRead(K2) == LOW) {

  }

  if (digitalRead(K3) == LOW) {

  }
}
