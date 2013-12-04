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
ISR(USART_RXC_vect){
  char a;
  a=UDR;//store the receive char in: a
  if(a=='O'){
    PORTB = 0b00100000;
    write('A');
  }
  if(a=='C'){
    PORTB = 0b00000000;
    write('E');
  }
}
#endif
