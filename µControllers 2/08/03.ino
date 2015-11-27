#include <TM1636.h>
TM1636 disp(7,8);
const byte MAX = 25;
const byte MIN = 23;
const byte leds[] = {2, 3, 4, 5};
int8_t pr [] = {17,0,0,12};
byte temp = 0;

void setup() {
  Serial.begin(9600);
  pinMode(14,INPUT);
  for (byte i = 0; i < sizeof(leds) / sizeof(byte); i++) {
    pinMode(leds[i], OUTPUT);
  }
  disp.init();
  disp.display(pr);
}

int8_t getTemperature()
{
  float temperature,resistance;
  int a;
  a = analogRead(14);
  resistance   = (float)(1023-a)*10000/a;
  temperature  = 1/(log(resistance/10000)/3975+1/298.15)-273.15;
  return (int8_t)temperature;
}

void printTemp(int8_t t) {
  pr[1] = t/10;
  pr[2] = t % 10 ;
  Serial.println(pr[2]),
  disp.display(pr);
}

void thermostate(int8_t t) {
  if (t < 23) {
    digitalWrite(leds[0],HIGH);
  } else if (t > 25) {
    digitalWrite(leds[1],HIGH);
  } else {
    digitalWrite(leds[0],LOW);
    digitalWrite(leds[1],LOW);
  }
}

void loop() {
  temp = getTemperature();
  thermostate(temp);
  printTemp(temp);
  delay(100);
}
