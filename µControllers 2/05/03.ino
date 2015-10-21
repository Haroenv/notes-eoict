byte LEN = 5;
word temperatuur[]={0x3B47,0x0C87,0x000F,0x0007,0xF387};

void setup() {
    Serial.begin(9600);
    for (int i = 0; i < LEN; i++) {
        Serial.println(temperatuur[i]);
    }
}
