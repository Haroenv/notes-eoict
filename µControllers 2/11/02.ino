// veen beetje uitleg hierbij, de klok en de temperatuur zullen om de 4 seconden afwisselen,
// van het ogenblik dat K2 of K3 wordt ingedrukt stopt die lus, dan kan je de tijd aanpassen.
// Als je de tijd hebt aangepast druk je op K1, dan gaat de lus weer verder. De reden hiervoor is
// dat een interrupt geen delay kan onderbreken. Er is zal waarschijnlijk wel een betere manier zijn om
// dit te doen.
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

int temperatuurOfTijd = 1;       // 0 = tijd, 1 = temperatuur
int knopingedrukt = 0;           // 0 = neen, 1 = ja (voor onmiddelijk naar de tijd over te gaan)

int lode = 0;                    // dit is voor K1, als die wordt ingedrukt gaat de lus weer verder

void setup() {

  Serial.begin(9600);
  Wire.begin();

  pinMode(2, INPUT);
  digitalWrite(2, HIGH);

  // tijd instellen
  setTime(17, 41, 00);

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

  Serial.print("lode");
  Serial.println(lode);

  Serial.print("knop");
  Serial.println(knopingedrukt);

  Serial.print("temperatuurOfTijd");
  Serial.println(temperatuurOfTijd);

  Serial.println("");

  // als er een knop wordt ingedrukt...
  if (knopingedrukt == 1 && lode == 1) {
    Serial.println("knop ingedrukt");
    temperatuurOfTijd = 0;
    toonTijdOpDisplay();
    delay(4000);
    temperatuurOfTijd = 1;
    knopingedrukt = 0;
  }

  if (temperatuurOfTijd == 0) {
    toonTijdOpDisplay();

    if (lode == 1) {
      delay(250);
    } else {
      delay(4000);
    }

  } else {
    berekenTemperatuur();
    delay(4000);
  }

  // dubbelpunt aan/uit
  scherm.point(dp);

  if (lode == 0) {
    if (temperatuurOfTijd == 1) {
      temperatuurOfTijd = 0;
    } else {
      temperatuurOfTijd = 1;
    }
  }

  if (lode == 1){
    toonTijdOpDisplay();
    temperatuurOfTijd = 0;
  }

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
    lode = 1;
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
    vlag = 1;     // om aan te tonen dat er een knop is ingedrukt. (anti dender)
    lode = 1;     // lus stoppen
  }

  // lus weer starten na het aanpassen
  if (digitalRead(K1) == LOW) {
    lode = 0;
  }
}

void berekenTemperatuur() {
  float temperatuurSensor = analogRead(A0);
  float weerstandNTC = ((1023 - temperatuurSensor) * 10000) / temperatuurSensor;
  float temperatuur = (1 / ((log(weerstandNTC / 10000) / 3975) + (1 / 298.15))) - 273.15;

  int temp = (int)temperatuur;
  int eersteGetal = temp / 10;
  int tweedeGetal = temp % 10;

  pr[0] = 'leeg';        // zal niets op het scherm tonen
  pr[1] = eersteGetal;
  pr[2] = tweedeGetal;
  pr[3] = 12;            // 12 hex = C

  scherm.display(pr);
}
