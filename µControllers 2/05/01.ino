byte i;

void setup() {
    Serial.begin(9600);
    i = 33;
}

void loop() {
    if(i <= 122){
        Serial.print("char: ");
        Serial.write(i);
        Serial.print(" hex: ");
        Serial.print(i,HEX);
        Serial.print(" dec: ");
        Serial.print(i,DEC);
        Serial.print("\n");
        i++;
    }
}