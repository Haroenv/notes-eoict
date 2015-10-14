#include <TimerOne.h>

int minute = 0;
int second = 0;

void setup() {
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(timerIsr);
  Serial.begin(9600);
}

void loop() {
  //minute < 10 ? Serial.print("0"):;
  if ( minute < 10 ) {
    Serial.print("0");
  }
  Serial.print(minute);
  Serial.print(":");
  //second < 10 ? Serial.print("0"):;
  if ( second < 10 ) {
    Serial.print("0");
  }
  Serial.println(second);
  delay(1000);
}

void timerIsr() {
  second++;
  if (second == 60 ) {
    second = 0;
    minute++;
  }
}