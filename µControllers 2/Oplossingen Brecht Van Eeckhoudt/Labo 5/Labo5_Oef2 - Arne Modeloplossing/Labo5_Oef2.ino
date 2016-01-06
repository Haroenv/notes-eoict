String meetwaarden[] = {"17.89;9.38E-3;STABLE;","17.94;9.28E-3;STABLE;","17.32;9.29E-2;UNSTABLE;"};
int teller;
float stroomoptellen;
int aantal;

void setup() {
  teller = 0;
  Serial.begin(9600);
}

void loop() {
  int index = meetwaarden[teller].indexOf(';');
  float spanning = meetwaarden[teller].substring(0, index +1).toFloat();
  float stroom = meetwaarden[teller].substring(index + 1, meetwaarden[teller].indexOf(';' ,index + 1 )).toFloat();
  String stabiel = meetwaarden[teller].substring((meetwaarden[teller].indexOf(';' ,index + 1 )+1),meetwaarden[teller].lastIndexOf(';'));
  Serial.print(spanning, 1);
  Serial.print("       ");
  if(stabiel == "STABLE"){
    stroomoptellen = stroomoptellen + stroom;
    aantal++;
  }
  if(teller == 2){
    float uiteindelijkeWaarde = stroomoptellen / 3;
    Serial.println();
    Serial.print("gemiddelde stroom:   ");
    Serial.print(uiteindelijkeWaarde, 5);
    Serial.println();
    Serial.print("Aantal stabiele: "); 
    Serial.print(aantal);
    while(true);
  }
  teller++;
}
