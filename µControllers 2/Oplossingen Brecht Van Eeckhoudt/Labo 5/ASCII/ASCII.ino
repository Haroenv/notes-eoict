#define startwaarde 33
#define eindwaarde 122

int teller = 0;
String deci = "";
String hex = "";

void setup() {
  Serial.begin(9600);
}
  

void loop() {
  for (teller = startwaarde; teller <= eindwaarde; teller++) {
    deci = String(teller, DEC);
    hex = String(teller, HEX);
    Serial.write(teller);
    Serial.print("  ");
    Serial.print(deci);
    Serial.print("  ");
    Serial.print(hex);
    Serial.println();
  }
  while (1);
}
