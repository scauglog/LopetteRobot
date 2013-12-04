/**
 * @File   Commande.h
 * @Author classerre, lleclech, rsagean
 *
 * Created on 27/11/2013, 14:29
 **/

#include "common.h"

#define FOSC 16000000
#define USART_BAUDRATE 115200 
#define BAUD_PRESCALE (FOSC/USART_BAUDRATE/16) 
//maybe 16-1 for other baudrate than 115200
void USART_init (unsigned int ubrr) { 
   UBRRH = (unsigned char)(ubrr >> 8); // Load upper 8-bits of the baud rate value into the high byte of the UBRR register 
   UBRRL = (unsigned char)(ubrr&0xff); // Load lower 8-bits of the baud rate value into the low byte of the UBRR register 
}

int main(void){
#ifdef ARDUINO
  // Definitions 
  USART_init(BAUD_PRESCALE);
  
  UCSRB = (1<<RXCIE)|(1<<RXEN)|(1<<TXEN);
  sei();//system enable interrupt
#endif
  setPortB(0b11111111);
  
  while (1) {
  	//break;
  }
}

