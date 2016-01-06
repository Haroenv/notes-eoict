// By Umut Saglam

#include "TM1636.h"
#include <TimerOne.h>
#include <Wire.h>

#define K1 9
#define K2 10
#define K3 11
TM1636 tm1636(7,8);
#define DS1307_ADDRESS 0x68


int8_t waarde[4];
float sensorReading;//analog pin reading
float weerstandNTC;
float temp;


int8_t val[4];
int s, m, u;
int u1,u2,m1,m2;
int change;

int mode; //0 = time 1 = temperature
int secondsMode;

void setup()
{
  tm1636.init();
  change = 0;
  secondsMode = 4;
  mode = 0; //0 = time
  u = 6;
  m = 5;
  s = 55;
  Wire.begin();
  setTime(u,m,s);
 // Wire.endTransmission();

  // initialize the button pin as a input and enable the internal pull-up resistor:
  pinMode(K1, INPUT_PULLUP);
  pinMode(K2, INPUT_PULLUP);
  pinMode(K3, INPUT_PULLUP);
  // interrupt init
  pciSetup(K1); // interrupt op K1
  pciSetup(K2); // interrupt op K2
  pciSetup(K3); // interrupt op K3
}
void loop()
{
  if(mode == 1 && (secondsMode > 0)){
    sensorReading = analogRead(A0);  //get analog reading
    weerstandNTC = ((1023 - sensorReading) * 10000)/sensorReading;
    temp = (1/((log((weerstandNTC/10000))/3975)+(1/298.15)))-273.15;
    waarde[0] = (int) temp/10;
    waarde[1] = (int) temp%10;
    waarde[2] = 0;
    waarde[3] = 0;
    tm1636.display(waarde);
    secondsMode--;
    if (secondsMode == 0){
      mode = 0;
      secondsMode = 4;
    }
  }

  if(mode == 0 && (secondsMode > 0)){
    if (change == 1){
        setTime(u,m,s);
        change = 0;
    }

    getTime();
    if(u%10 > 0){
      u1 = u/10;
      u2 = u%10;
    } else{
      u1 = 0;
      u2 = u;
    }

    if(m%10 > 0){
      m1 = m/10;
      m2 = m%10;
    } else{
      m1 = 0;
      m2 = m;
    }
    val[0] = u1;
    val[1] = u2;
    val[2] = m1;
    val[3] = m2;
    tm1636.display(val);
    secondsMode--;
    if (secondsMode == 0){
      mode = 1;
      secondsMode = 4;
    }
  }
  delay (1000);
}


void pciSetup (byte pin)
{
  *digitalPinToPCMSK(pin) |= bit (digitalPinToPCMSKbit(pin)); // enable pin
  PCIFR |= bit(digitalPinToPCICRbit(pin));  // clear any outstanding interrupt
  PCICR |= bit (digitalPinToPCICRbit(pin)); // enable interrupt for the group
}

ISR (PCINT0_vect){
 // handle pin change
 // interrupt for D8 - D13 here
  while(digitalRead(K1) == LOW){
    if(digitalRead(K1) == HIGH){
      u++;
      change = 1;
      mode = 0;
      secondsMode = 4;
    }
  }

  while(digitalRead(K2) == LOW){
    if(digitalRead(K2) == HIGH){
      u--;
      change = 1;
      mode = 0;
      secondsMode = 4;
    }
  }

  while(digitalRead(K3) == LOW){
    if(digitalRead(K3) == HIGH){
      m++;
      change = 1;
      mode = 0;
      secondsMode = 4;
    }
  }
}


void setTime(byte uur, byte minuut, byte second){
  Wire.beginTransmission(DS1307_ADDRESS);
  Wire.write(0);
  Wire.write(decToBcd(second));
  Wire.write(decToBcd(minuut));
  Wire.write(decToBcd(uur));
  Wire.endTransmission();
}


void getTime(){
  Wire.beginTransmission(0x68);
  Wire.write((byte)0x00);
  Wire.endTransmission();
  Wire.requestFrom(DS1307_ADDRESS, 3);
  // 7 bytes opvragen
  s = bcdToDec(Wire.read() & 0x7f);
  // bit 7 skippen
  m = bcdToDec(Wire.read());
  u = bcdToDec(Wire.read() & 0x3f);
  // am/pm
}

byte decToBcd ( byte val ){
  return ( ( val /10*16) + ( val %10) ) ;
}

byte bcdToDec ( byte val ){
  return ( ( val /16*10) + ( val %16) ) ;
}

