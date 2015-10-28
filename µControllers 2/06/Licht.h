#ifndef Licht_h
#define Licht_h
#include <inttypes.h>
#include <Arduino.h>

class Licht
{
public:
  Licht(int);
  void aan(void);
  void uit(void);
  void dim(int);
private:
  int LedNum;
};
#endif
