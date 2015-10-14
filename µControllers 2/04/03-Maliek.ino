#define K1 9
#define K2 10
#define K3 11
#define LED4 5
int previousInt;
byte helderheid = 255;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED4, OUTPUT);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pciSetup(K1);
  pciSetup(K2);
  pciSetup(K3);
  digitalWrite(LED4, HIGH);
}

void pciSetup(byte pin) {
  * digitalPinToPCMSK(pin) |= bit (digitalPinToPCMSKbit(pin));
  PCIFR |= bit (digitalPinToPCICRbit(pin));
  PCICR |= bit (digitalPinToPCICRbit(pin));
}

ISR(PCINT0_vect) {
  unsigned long now = millis();
  
  if (now - previousInt > 20) {
    if (digitalRead(K2) == LOW) {
      digitalWrite(LED4, LOW);
    }
    if (digitalRead(K1) == LOW) {
      if (helderheid > 254) {
        helderheid = 0;
      } else {
        helderheid += 25;
      }
      analogWrite(LED4, helderheid);
    }
    if (digitalRead(K3) == LOW) {
      if (helderheid < 0) {
        helderheid = 255;
      } else {
        helderheid -= 25;
      }
      analogWrite(LED4, helderheid);
    }
    }
    previousInt = now;
  }
  
void loop() {}


