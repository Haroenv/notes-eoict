#define K1 9
#define K2 10
#define K3 11

boolean t = false;
const byte ledArray[] = {2,3,4,5};
volatile int vlag = 0; // synchroniseren, kan in 2 methodes aangepast worden

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
  Serial.begin(9600);
  for (int x = 0; x < sizeof(ledArray); x++) {
    pinMode(ledArray[x],OUTPUT);
  }
}
  
void loop() {
  // delay mag niet in isr, semafoor
  if (vlag == 1) {
    if (t) {
      //looplicht hier
    }
    delay(400);
    vlag = 0;
  }
}

// handle pin change interrupt for D8 -> D13 here
ISR (PCINT0_vect) { 
  if (vlag != 1) {
    if (digitalRead(K1) == LOW) {
      t = true;
    }
    if (digitalRead(K2) == LOW) {
      t = false;
    }
    vlag = 1;
  }
}
