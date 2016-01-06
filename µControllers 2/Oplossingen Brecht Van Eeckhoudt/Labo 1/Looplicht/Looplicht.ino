int LED1 = 2;
int LED2 = 3;
int LED3 = 4;
int LED4 = 5;

void setup() {
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  pinMode(LED4,OUTPUT);
  digitalWrite(LED1,HIGH);
}

void loop() {
  delay(500);
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,HIGH);
  delay(500);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,HIGH);
  delay(500);
  digitalWrite(LED3,LOW);
  digitalWrite(LED4,HIGH);
  delay(500);
  digitalWrite(LED4,LOW);
  digitalWrite(LED1,HIGH);
}
