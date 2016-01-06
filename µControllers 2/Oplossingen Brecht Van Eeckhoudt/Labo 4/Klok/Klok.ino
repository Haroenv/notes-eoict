#include <TimerOne.h>

int minuut = 0;
int seconde = 0;
volatile bool vlag = false;

void setup() {
  Serial.begin(9600);
  Timer1.initialize(200000);
  Timer1.attachInterrupt(timerISR);
} 

void loop() {
  if (vlag) {
    if (minuut < 10) {
     Serial.print(0);
    }
    Serial.print(minuut);
    Serial.print(":");
    
    if (seconde < 10) {
     Serial.print(0);
    }
    Serial.print(seconde);
    Serial.println();
    vlag = false;
  }
}

void timerISR() {
  if (seconde == 59) {
    minuut++;
    seconde = 0;
  }
  else {
    seconde++;
  }
  vlag = true;
}

