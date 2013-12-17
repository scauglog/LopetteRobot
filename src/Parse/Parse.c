#include "Parse.h"


void writeSerial(uint8_t i){
#ifdef ARDUINO
  UDR=i;
  while(!(UCSRA&(1<<UDRE)));
#else
  fprintf(stdout,"%x ", i);
  fflush(stdout);
#endif
}


void parse(void){  
  uint8_t cmd = rx[0] & 0b11110000;
  //uint8_t type = rx[0] & 0b00001110;
  //uint8_t isMask = rx[0] & 0b00000001;   
  
  switch (cmd) {
  case 0x00:
    GetCaps();
    break;
  case 0x10:
    //reset();
    writeSerial(2);
    break;
  case 0x20:
    Ping();
    break;
  case 0x30:
    //if (isMask == 0b00000001) //read a mask
    //read(type,1,size, );
    //else              
    //read();         //read a pin
    writeSerial('r');
    break;
  case 0x40:
    writeSerial('w');
    break;
  case 0x50:
    //if(mask == 0b00000001)
    //getType();
    writeSerial('g');
    break;
  case 0x60:
    //setType();
    writeSerial('s');
    break;
  case 0x70:
    //getFailSaf();
    writeSerial('g');
    break;
  case 0x80:
    writeSerial('s');
    //setFailSafe();
    break;
  default:
    Ping();
    break;
  }
}
