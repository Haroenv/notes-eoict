// By Lode Allaert

#include <TM1636.h>
#include <TimerOne.h>
#include <Wire.h>

#define DS1307_ID 0x68

#define K1 9
#define K2 10
#define K3 11

TM1636 scherm(7, 8);
int8_t pr [] = {0, 0, 0, 0};

byte seconds;
byte minutes;
byte hours;

// dubbelpunt
boolean dp;

// aangepaste uur/min
byte nieuwUur;
byte nieuweMinuten;

// anti dender
int vlag = 0;

void setup() {

  Serial.begin(9600);
  Wire.begin();

  pinMode(2, INPUT);
  digitalWrite(2, HIGH);

  // tijd instellen
  setTime(15, 55, 00);

  pinMode(14, INPUT);
  scherm.init();
  scherm.display(pr);

  pinMode(K1, INPUT_PULLUP);
  pinMode(K2, INPUT_PULLUP);
  pinMode(K3, INPUT_PULLUP);

  pciSetup(K1);
  pciSetup(K2);
  pciSetup(K3);
}

void loop() {
  getTime();

  toonTijdOpDisplay();

  // dubbelpunt aan/uit
  scherm.point(dp);
  delay(500);
  dp = !dp;


  Serial.print(hours);
  Serial.print(":");
  Serial.print(minutes);
  Serial.print(":");
  Serial.println(seconds);

  // enkel tijd veranderen als er een knop is ingedrukt
  if (vlag == 1) {
    hours = nieuwUur;
    minutes = nieuweMinuten;

    setTime(hours, minutes, seconds);

  } else {
    nieuwUur = hours;
    nieuweMinuten = minutes;
  }
  // anti dender
  vlag = 0;
}

// functie setTime
void setTime(byte hours, byte minutes, byte seconds) {

  Wire.beginTransmission(DS1307_ID);
  Wire.write(0x00);
  Wire.write(decToBcd(seconds));
  Wire.write(decToBcd(minutes));
  Wire.write(decToBcd(hours));

  Wire.endTransmission();
}

// functie getTime
void getTime() {

  Wire.beginTransmission(DS1307_ID);
  Wire.write((byte)0x00);
  Wire.endTransmission();
  Wire.requestFrom(DS1307_ID, 7);

  // bit 7 skippen
  seconds = bcdToDec(Wire.read() & 0x7f);
  minutes = bcdToDec(Wire.read());
  hours = bcdToDec(Wire.read() & 0x3f);
}

byte decToBcd ( byte val )
{
  return ( ( val / 10 * 16) + ( val % 10) ) ;
}

byte bcdToDec ( byte val )
{
  return ( ( val / 16 * 10) + ( val % 16) ) ;
}

void toonTijdOpDisplay() {
  getTime();

  byte uren = 0;
  byte minuten = 0;
  byte rest = 0;

  //De eerste 2 cijfers van het uur opsplitsen
  if (hours > 9) {
    uren = hours / 10;      // eerste getal
    rest = hours % 10;      // tweede getal (de rest)

    pr[0] = uren;
    pr[1] = rest;
  } else {
    pr[0] = 0;
    pr[1] = hours;
  }

  if (minutes > 9) {
    minuten = minutes / 10;
    rest = minutes % 10;

    pr[2] = minuten;
    pr[3] = rest;
  } else {
    pr[2] = 0;
    pr[3] = minutes;
  }
  scherm.display(pr);
}

void pciSetup(byte pin) {
  * digitalPinToPCMSK(pin) |= bit (digitalPinToPCMSKbit(pin));
  PCIFR |= bit (digitalPinToPCICRbit(pin));
  PCICR |= bit (digitalPinToPCICRbit(pin));
}

ISR (PCINT0_vect) {

  // uren aanpassen
  if (digitalRead(K3) == LOW) {
    if (vlag == 0) {
      nieuwUur++;

      if (nieuwUur > 23) {
        nieuwUur = 0;
      }
    }
    vlag = 1;
  }

  // minuten aanpassen
  if (digitalRead(K2) == LOW) {
    if (vlag == 0) {
      nieuweMinuten++;

      if (nieuweMinuten > 59) {
        nieuweMinuten = 0;
        nieuwUur++;
      }
    }
    vlag = 1;
  }
}