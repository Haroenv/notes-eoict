#include <TM1636.h>

// Declare a TM1636 Class object that control the 4-digit display
TM1636 tm1636(7,8);

int8_t disp[4];

void setup() {
  // Set the default brightness is BRIGHT_TYPICAL and clear the display
  tm1636.init();
  disp[0] = 2;
  disp[1] = 1;
  disp[2] = 18;
  disp[3] = 12;
  tm1636.display(disp);
}

void loop() {
  
}
