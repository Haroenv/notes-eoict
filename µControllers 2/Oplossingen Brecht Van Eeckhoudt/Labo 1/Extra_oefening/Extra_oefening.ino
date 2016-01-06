const byte patroon[5][3] = {{0,0,0,1},{0,0,1,1},{0,1,1,1},{1,1,1,1},{0,0,0,0}};
const byte ledArray[] = {2,3,4,5};

void setup() {
  for (int x = 0; x < sizeof(ledArray); x++) {
    pinMode(ledArray[x],OUTPUT);
  }
}

void loop() {
  for (int x = 0; x < sizeof(patroonArray); x++) {
    for (int x = 0; x < sizeof(patroonArray); x++) {
      
    }
  }
}
