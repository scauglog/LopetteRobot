#include "Parse.h"

void write(char i){
  
#ifdef ARDUINO
  UDR=i;
  while(!(UCSRA&(1<<UDRE)));
#else
  fprintf(stdout,"j'ecris : %c\n",i);
  fflush(stdout);
#endif
}

void parse(void){
  
  uint8_t cmd = rx[0] & 0b11110000;
  uint8_t type = rx[0] & 0b00001110;
  uint8_t isMask = rx[0] & 0b00000001;

   
  
  switch (cmd) {

  case 0b00000000:
    //getCaps();
    write('g');
    break;
  case 0b00010000:
    //reset();
    write('r');
    break;
  case 0b00100000:
    //ping(rx[3]);
    write('p');
    break;
  case 0b00110000:
    //if (isMask == 0b00000001) //read a mask
      //read(type,1,size, );
      //else              
    //read();         //read a pin
    write('r');
    break;
  case 0b01000000:
    write('w');
    break;
  case 0b01010000:
    //if(mask == 0b00000001)
      //getType();
    write('g');
    break;
  case 0b01100000:
    //setType();
    write('s');
    break;
  case 0b01110000:
    //getFailSaf();
    write('g');
    break;
  case 0b10000000:
    write('s');
    //setFailSafe();
    break;
  default:
    //ping();
    write('p');
    break;
  }
}
