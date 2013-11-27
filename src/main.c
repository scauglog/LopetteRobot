/**
 * @File   Commande.h
 * @Author classerre, lleclech, rsagean
 *
 * Created on 27/11/2013, 14:29
 **/

#include "common.h"

int main(void){
#ifdef ARDUINO
  // Definitions 
  UCSRB = (1<<RXCIE)|(1<<RXEN)|(1<<TXEN);
  //sei();
#endif
  setPortB(0b11001111);
  
  while (1) {
  	break;
  }
}

