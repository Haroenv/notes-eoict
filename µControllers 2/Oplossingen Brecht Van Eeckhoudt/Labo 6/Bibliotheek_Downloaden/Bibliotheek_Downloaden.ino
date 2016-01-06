#include <TM1636.h>

// Declare a TM1636 Class object that control the 4-digit display
TM1636 tm1636(7,8);

int8_t disp[4];

void setup() {
  // Set the default brightness is BRIGHT_TYPICAL and clear the display
  tm1636.init();
  disp[0] = 5;
  disp[1] = 6;
  disp[2] = 7;
  disp[3] = 8;
  tm1636.display(disp);
}

void loop() {
  tm1636.point(true);
  disp[0] = 1;
  disp[1] = 2;
  disp[2] = 3;
  disp[3] = 4;
  tm1636.display(disp);
  delay(500);
  tm1636.point(false);
  disp[0] = 5;
  disp[1] = 6;
  disp[2] = 7;
  disp[3] = 8;
  tm1636.display(disp);
  delay(500);
}
