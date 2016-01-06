// één vd 5 bereiken
#define bereik 182

const byte ledArray[] = {2,3,4,5};
int gelezen = 0;
int berekend = 0;

void setup() {
  Serial.begin(9600);
  for (int x = 0; x < sizeof(ledArray); x++) {
    pinMode(ledArray[x],OUTPUT);
  }
  pinMode(15,INPUT);
  Serial.println("--------------------------");
}
  
void loop() {
  gelezen = analogRead(15);
  berekend = ((long)(1023 - gelezen) * 10000) / gelezen;
  Serial.print("Gelezen: ");
  Serial.print(gelezen);
  Serial.println();
  Serial.print("Berekend: ");
  Serial.print(berekend);
  Serial.println();
  Serial.println("--------------------------");

  // alles uit
  for (int x = 0; x < sizeof(ledArray); x++) {
    digitalWrite(ledArray[x],0);
  }

  switch (gelezen / bereik) {
    case 0:
      // staat al goed
      break;
    case 1:
      for (int x = 0; x < 1; x++) {
        digitalWrite(ledArray[x],1);
      }
      break;
    case 2:
      for (int x = 0; x < 2; x++) {
        digitalWrite(ledArray[x],1);
      }
      break;
    case 3:
      for (int x = 0; x < 3; x++) {
        digitalWrite(ledArray[x],1);
      }
      break;
    case 4:
      for (int x = 0; x < 4; x++) {
        digitalWrite(ledArray[x],1);
      }
      break;
    default: 
      // if nothing else matches, do the default
      // default is optional
    break;
  }
  delay(1000);
}
