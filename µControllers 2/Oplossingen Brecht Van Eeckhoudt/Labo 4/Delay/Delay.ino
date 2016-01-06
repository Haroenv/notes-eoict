#include <TimerOne.h>

long t1 = 0;
long t2 = 0;

void setup() {
  Serial.begin(9600);
  Timer1.initialize(1000);
  Timer1.attachInterrupt(timerISR);
} 

void loop() {
 t1++;
 if ((t1 % 1000) == 0) {
  Serial.print("delay: ");
  Serial.print(t1);
  Serial.println();
 }
 delay(1);
}

void timerISR() {
  t2++;
  if ((t2 % 1000) == 0) {
   Serial.print("timer: ");
   Serial.print(t2);
   Serial.println();
  }
}

