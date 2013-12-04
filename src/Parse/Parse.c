#include "Parse.h"

void write(char i){
#ifdef ARDUINO
  UDR=i;
  while(!(UCSRA&(1<<UDRE)));
#else
  fprintf(stdout,"%c",i);
#endif
}

#ifdef ARDUINO
//ISR(UART_RXC){
  //char a;
  //a=UDR;
//  if(1){
//    PORTB = 0b00100000;
//  }
//  else
//    PORTB = 0b00000000;
//}
#endif
