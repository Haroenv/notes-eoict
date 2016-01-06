// By Umut Saglam

#include "TM1636.h"
#include <TimerOne.h>
#include <Wire.h>

#define K1 9
#define K2 10
#define K3 11
TM1636 tm1636(7,8);
#define DS1307_ADDRESS 0x68

int8_t val[4];
int s, m, u;

int u1,u2,m1,m2;
int change;


void setup()
{
  tm1636.init();
  change = 0;
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
  if (change == 1){
      setTime(u,m,s);
      change = 0;
  }

  getTime();
 // Wire.endTransmission();
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
    }
  }

  while(digitalRead(K2) == LOW){
    if(digitalRead(K2) == HIGH){
      u--;
      change = 1;
    }
  }

  while(digitalRead(K3) == LOW){
    if(digitalRead(K3) == HIGH){
      m++;
      change = 1;
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
  Wire.requestFrom(DS1307_ADDRESS, 7);
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

