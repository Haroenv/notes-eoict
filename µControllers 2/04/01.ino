#include <TimerOne.h>

long counter1 = 0;
long counter2 = 0;

void setup() {
  Timer1.initialize(1000);
  Timer1.attachInterrupt(timerIsr);
  Serial.begin(9600);
}

void loop() {
  if (counter1 % 1000 == 0) {
    Serial.print("timer: ");
    Serial.println(counter1);
  }
  if (counter2 % 1000 == 0) {
    Serial.print("delay: ");
    Serial.println(counter2);
  }
  counter2++;
  delay(1);
}

void timerIsr() {
  counter1++;
}