#include <Licht.h>
Licht LED1(1);
Licht LED2(2);
Licht LED3(3);
Licht LED4(4);

void setup() {
  LED1.aan();
  LED2.uit();
  LED3.dim(50);
  LED4.dim(10);
}

void loop() {

}