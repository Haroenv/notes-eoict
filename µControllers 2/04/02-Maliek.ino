#include <TimerOne.h>
int minuten = 0;
int seconden = 0;

void setup() {
  // put your setup code here, to run once:
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(timerIsr);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  if (minuten < 10) {
    Serial.print("0");
    Serial.print(minuten);
    Serial.print(":");
  } else {
    Serial.print(minuten);
    Serial.print(":");
  }
  if (seconden < 10) {
    Serial.print("0");
    Serial.print(seconden);
    Serial.println();
  } else {
    Serial.print(seconden);
    Serial.println();
  }
  
  /*Serial.println();
  Serial.println("Seconden   ");
  Serial.println(seconden);
  Serial.println();*/
}

void timerIsr() {
  if (seconden == 59) {
    seconden = 0;
    minuten++;
  } else {
    seconden++;
  }
}
