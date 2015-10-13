/*
* Dwight Van Der Velpen
*/


#define K1  9
#define K2  10
#define K3  11

const byte ledArray [] = {2 ,3 ,4 ,5};
byte loper = 1;
byte onOff = 1; //0=stop 1=left 2=right

void setup() {
  pinMode ( K1 , INPUT_PULLUP );
  pinMode ( K2 , INPUT_PULLUP ); 
  pinMode ( K3 , INPUT_PULLUP ); 
  pciSetup(K1);
  pciSetup(K2);
  pciSetup(K3);

  for(int x=0; x<=3;x++) pinMode(ledArray[x],OUTPUT);
  
}

void pciSetup ( byte pin ){
  * digitalPinToPCMSK ( pin ) |= bit (digitalPinToPCMSKbit ( pin ) ) ; // enable pin
  PCIFR |= bit ( digitalPinToPCICRbit ( pin ) ) ; // clear any outstanding interrupt
  PCICR |= bit ( digitalPinToPCICRbit ( pin ) ) ; // enable interrupt for the group
}

ISR ( PCINT0_vect ){    
    if((!digitalRead(K1)) && (digitalRead(K2))&&(digitalRead(K3))){
      while(!digitalRead(K1)){//antiDender
      }
      onOff=1;
    }
    else if((digitalRead(K1)) && (!digitalRead(K2))&&(digitalRead(K3))){
      while(!digitalRead(K2)){//antiDender
      }
      onOff=2;
    }
    else if((digitalRead(K1)) && (!digitalRead(K2))&&(!digitalRead(K3))){
      while(!digitalRead(K3)){//antiDender
      }
      onOff=0;
    }
}

void loop() {      
  for(int i = 0; i < 4; i++) digitalWrite(ledArray[i], bitRead(loper,i));

  if((loper == 1) && onOff == 2) loper = 8;
  else if((loper == 8) && onOff == 1) loper = 1;    
  else if(onOff != 0){
    if(onOff == 1) loper*=2;
    else loper/=2;
  }
  
  delay(500);
}
