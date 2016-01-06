#include <Licht.h>

void setup() {
  Licht LED1(2);
  Licht LED2(3);
  Licht LED3(4);
  LED1.aan();
  LED2.uit();
  LED3.dim(50);
}

void loop() {
  // put your main code here, to run repeatedly:

}
