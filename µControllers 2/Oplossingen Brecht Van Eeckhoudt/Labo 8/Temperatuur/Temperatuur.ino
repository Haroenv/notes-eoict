#include <TM1636.h>
// Declare a TM1636 Class object that control the 4-digit display
TM1636 tm1636(7,8);
int8_t disp[4];

int gelezen = 0;
int berekend = 0;
int berekendeTemperatuur = 0;
int cijfer = 0;

void setup() {
  Serial.begin(9600);
  pinMode(14,INPUT);
  disp[2] = 18;
  disp[3] = 12;
  Serial.println("--------------------------");
}
  
void loop() {
  // Set the default brightness is BRIGHT_TYPICAL and clear the display
  tm1636.init();
  
  gelezen = analogRead(14);
  berekend = ((long)(1023 - gelezen) * 10000) / gelezen;
  berekendeTemperatuur = (gelezen / 1024.0) * 50;
  
  Serial.print("Gelezen: ");
  Serial.print(gelezen);
  Serial.println();
  Serial.print("Berekend: ");
  Serial.print(berekendeTemperatuur);
  Serial.print("'C");
  Serial.println();
  Serial.println("--------------------------");

  disp[0] = berekendeTemperatuur / 10;
  disp[1] = (berekendeTemperatuur - (int)(berekendeTemperatuur / 10) * 10);

  
  tm1636.display(disp);
  delay(1000);
}
