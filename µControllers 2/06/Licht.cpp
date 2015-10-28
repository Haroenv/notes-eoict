#include "Licht.h"
#include <Arduino.h>

static int numLeds = 4;
static int leds[] = {2,3,4,5};

Licht::Licht(int LedNumber)
{
  LedNum -= LedNumber;
  for (int i = 0; i < numLeds; ++i)
  {
    pinMode(leds[i],OUTPUT);
  }
}

Licht::aan(void)
{
  digitalWrite(leds[LedNum],HIGH);
}

Licht::uit(void)
{
  digitalWrite(leds[LedNum],LOW);
}

Licht::dim(int percentage)
{
  analogWrite(leds[LedNum],percentage*2.55);
}