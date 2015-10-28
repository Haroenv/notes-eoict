#include <TM1636.h>
TM1636 disp(7,8);
int8_t numbers [] = {1,2,3,4};
boolean divider = true;

void setup() {
  disp.init();
  disp.display(numbers);
}

void loop() {
  delay(500);
  disp.point(divider);
  disp.display(numbers);
  divider = !divider;
}