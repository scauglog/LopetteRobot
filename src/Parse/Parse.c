#include "Parse.h"


void writeSerial(char i){
#ifdef ARDUINO
  UDR=i;
  while(!(UCSRA&(1<<UDRE)));
#else
  fprintf(stdout,"%c ", i);
  fflush(stdout);
#endif
}


void parse(void){  
  uint8_t cmd = rx[0] & 0b11110000;
  //uint8_t type = rx[0] & 0b00001110;
  //uint8_t isMask = rx[0] & 0b00000001;   
  
  switch (cmd) {
  case 0b00000000:
    //getCaps();
    writeSerial('g');
    break;
  case 0b00010000:
    //reset();
    writeSerial('r');
    break;
  case 0b00100000:
    //ping(rx[3]);
    writeSerial('p');
    break;
  case 0b00110000:
    //if (isMask == 0b00000001) //read a mask
    //read(type,1,size, );
    //else              
    //read();         //read a pin
    writeSerial('r');
    break;
  case 0b01000000:
    writeSerial('w');
    break;
  case 0b01010000:
    //if(mask == 0b00000001)
    //getType();
    writeSerial('g');
    break;
  case 0b01100000:
    //setType();
    writeSerial('s');
    break;
  case 0b01110000:
    //getFailSaf();
    writeSerial('g');
    break;
  case 0b10000000:
    writeSerial('s');
    //setFailSafe();
    break;
  default:
    //ping();
    writeSerial('p');
    break;
  }
}
