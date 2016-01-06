#include <math.h>

#define arraygrootte 3

String meetwaarden[] = {"17.89;9.38E-3;STABLE;", "17.94;9.28E-3;STABLE;", "17.32;9.29E-3;UNSTABLE;"};
int teller = 0;
int teller2 = 0;
String waarde;
float spanning = 0;

void setup() {
  Serial.begin(9600);
}
  

void loop() {
  for (teller = 0; teller < arraygrootte; teller++) {
    spanning = meetwaarden[teller].substring(0, meetwaarden[teller].indexOf(';')).toFloat();
    Serial.print("Spanningswaarde ");
    Serial.print(teller + 1);
    Serial.print(" = ");
    Serial.print(spanning, 1);
    Serial.println();
  }

  
  while (1);
}
