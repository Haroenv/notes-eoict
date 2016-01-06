#include <Wire.h>
#include <TM1636.h>
#include <TimerOne.h>

#define DS1307_I2C_ADDRESS 0x68
#define K2 10
#define K3 11

// Declare a TM1636 Class object that control the 4-digit display
TM1636 tm1636(7,8);
int8_t disp[4];

int uur;
int minuut;
int second;
bool point;
int halfSecond;
int secondsToTemp = 1;

int gelezen = 0;
int berekend = 0;
int berekendeTemperatuur = 0;
int cijfer = 0;

volatile int vlag = 0; // synchroniseren, kan in 2 methodes aangepast worden
volatile bool vlagTimer = false;

void pciSetup(byte pin) {
  *digitalPinToPCMSK(pin) |= bit (digitalPinToPCMSKbit(pin)); // enable pin
  PCIFR |= bit (digitalPinToPCICRbit(pin)); // clear any outstanding interrupt
  PCICR |= bit (digitalPinToPCICRbit(pin)); // enable interrupt for the group
}

void setup() {
  pinMode(K2, INPUT_PULLUP);
  pinMode(K3, INPUT_PULLUP);
  pinMode(14,INPUT);
  pciSetup(K2); // interrupt K2 inschakelen
  pciSetup(K3); // interrupt K3 inschakelen
  Wire.begin();

  // Set the default brightness is BRIGHT_TYPICAL and clear the display
  tm1636.init();

  Timer1.initialize(500000);
  Timer1.attachInterrupt(timerISR);

  halfSecond = 0;
}
  
void loop() {
  // A Button was pressed
  if (vlag == 1) {
    setTime();
    delay(400);
    vlag = 0;
  }

  // Half a second passed
  if (vlagTimer) {
    if (secondsToTemp == 5) {
      secondsToTemp = 0;
      disp[2] = 18;
      disp[3] = 12;
      //TM1636.cpp:
      //static int8_t TubeTab[] = {0x3f,0x06,0x5b,0x4f,
      //                           0x66,0x6d,0x7d,0x07,
      //                           0x7f,0x6f,0x77,0x7c,
      //                           0x39,0x5e,0x79,0x71,
      //                           0x40,0x00,0x63};//0~9,A,b,C,d,E,F,"-","°"  
      gelezen = analogRead(14);
      berekend = ((long)(1023 - gelezen) * 10000) / gelezen;
      berekendeTemperatuur = (gelezen / 1024.0) * 50;
      disp[0] = berekendeTemperatuur / 10;
      disp[1] = (berekendeTemperatuur - (int)(berekendeTemperatuur / 10) * 10);
      point = false;
      tm1636.point(point);
      tm1636.display(disp);
      delay(1000);
    }
    else {
      //colon
      if (point) {
        tm1636.point(point);
        tm1636.display(disp);
        point = false;
      }
      else {
        tm1636.point(point);
        tm1636.display(disp);
        point = true;
      }
      
      getTime();
      
      disp[0] = uur / 10;
      disp[1] = uur % 10;
      disp[2] = minuut / 10;
      disp[3] = minuut % 10;
      tm1636.display(disp);
    }
  
    vlagTimer = false;
  }
}

void setTime() {
  Wire.beginTransmission(DS1307_I2C_ADDRESS);
  Wire.write((byte)0x00); // 0 in bit 7 start de klok
  Wire.write(decToBcd(second)); 
  Wire.write(decToBcd(minuut));
  Wire.write(decToBcd(uur));
  Wire.endTransmission();
}

void getTime() {
  Wire.beginTransmission(DS1307_I2C_ADDRESS);
  Wire.write((byte)0x00);
  Wire.endTransmission();
  Wire.requestFrom(DS1307_I2C_ADDRESS, 7); // 7 bytes opvragen
  second = bcdToDec(Wire.read() & 0x7f); // bit 7 skippen
  minuut = bcdToDec(Wire.read());
  uur = bcdToDec(Wire.read() & 0x3f); // am/pm
}

byte decToBcd(byte val) {
  return ((val / 10 * 16) + (val % 10));
}

byte bcdToDec(byte val) {
  return ((val / 16 * 10) + (val % 16));
}

// handle pin change interrupt for D8 -> D13 here
ISR (PCINT0_vect) { 
  if (vlag != 1) {
    if (digitalRead(K3) == LOW) {
      if (uur < 23) {
        uur++;
      }
      else {
        uur = 0;
     }
    }
    if (digitalRead(K2) == LOW) {
      if (minuut < 59) {
        minuut++;
      }
      else {
        minuut = 0;
      }
    }

    if (second < 59) {
      second++;
    }
    else {
      second = 0;
    }
  }
  vlag = 1;
}

void timerISR() {
  // Only set new time if a full second is reached
  if (halfSecond == 2) {
    secondsToTemp++;
    
    if (second == 59) {
      minuut++;
      second = 0;
    }
    else {
      second++;
    }
    
    if (minuut == 59) {
      uur++;
      minuut = 0;
    }
  
    if (uur == 23) {
      uur = 0;
    }

    halfSecond = 0;
  }
  
  halfSecond++;
  
  vlagTimer = true;
}

