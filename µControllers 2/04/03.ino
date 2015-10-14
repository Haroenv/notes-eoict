#define K1 9
#define K2 10
#define K3 11
byte led = 5;

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
  digitalWrite(led,HIGH);
}

ISR (PCINT0_vect) {
  if (digitalRead(K1) == LOW) {
  	// vermindert helderheid met 10%
  }

  if (digitalRead(K2) == LOW) {
  	digitalWrite(led,LOW);
  }

  if (digitalRead(K3) == LOW) {
  	// vermeerdert de helderheid
  }
}

void loop() {
}
