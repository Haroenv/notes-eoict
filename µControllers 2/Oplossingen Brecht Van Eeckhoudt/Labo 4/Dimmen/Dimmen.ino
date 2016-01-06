#define K1 9
#define K2 10
#define K3 11
// Maar op één plaats moeten veranderen
#define delta 25.5

volatile bool vlag = false; // synchroniseren, kan in 2 methodes aangepast worden
float duty = 0;

void pciSetup(byte pin) {
  *digitalPinToPCMSK(pin) |= bit (digitalPinToPCMSKbit(pin)); // enable pin
  PCIFR |= bit (digitalPinToPCICRbit(pin)); // clear any outstanding interrupt
  PCICR |= bit (digitalPinToPCICRbit(pin)); // enable interrupt for the group
}

void setup() {
  pinMode(K1, INPUT_PULLUP);
  pinMode(K2, INPUT_PULLUP);
  pinMode(K3, INPUT_PULLUP);
  pciSetup(K1); // interrupt K1 inschakelen
  pciSetup(K2); // interrupt K2 inschakelen
  pciSetup(K3); // interrupt K3 inschakelen
  pinMode(3,OUTPUT); // LED2
}
  
void loop() {
  if (vlag) {
    analogWrite(3, duty);
    delay(200);
    vlag = false;
  }
}

// handle pin change interrupt for D8 -> D13 here
ISR (PCINT0_vect) { 
  if (!vlag) {
    if (digitalRead(K1) == LOW && duty <= (255 - delta)) {
    duty += delta;
    }
    if (digitalRead(K2) == LOW) {
      duty = 0;
    }
    if (digitalRead(K3) == LOW && duty >= delta) {
      duty -= delta;
    }
    vlag = true;
  }
}
