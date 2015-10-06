float i = 0, surf;
const float pi = 3.1415926535;
void setup() {
  Serial.begin(9600);
}

void loop() {
 i++;
 surf = pi * pow(i,2);
 Serial.print("A circle with radius ");
 Serial.print(i);
 Serial.print(" has a surface of ");
 Serial.println(surf);
 delay(1000);
}
