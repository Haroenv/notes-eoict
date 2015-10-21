byte MAX = 3;
byte i = 0;
float avg = 0;
byte stables = 0;
String val[] = {"17.89;9.38E-3;STABLE;","17.94;9.28E-3;STABLE;","17.32;9.29E-2;UNSTABLE;"};

void setup() {
    Serial.begin(9600);

    for (int i = 0; i < MAX; i++) {
        Serial.println(getVoltage(val[i]),1);
        if(getStable(val[i])) {
            avg += getCurrent(val[i]);
            stables++;
        }
    }
    avg /= stables;
    Serial.println(avg,5);
    i++;
}

void loop() {

}

float getVoltage(String toParse) {
    return toParse.substring(0,5).toFloat();
}

float getCurrent(String toParse) {
    return toParse.substring(6,13).toFloat();
}

boolean getStable(String toParse) {
    if(toParse.charAt(14) == 'S') return true;
    return false;
}