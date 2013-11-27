/**
 * @File   Commande.h
 * @Author classerre, lleclech, rsagean
 *
 * Created on 27/11/2013, 14:29
 **/

#include <inttypes.h>
#ifdef ARDUINO
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#else
#include <stdio.h>
#include <stdlib.h>
#include "Commande/Commande.h"
#include "common.h"
#endif

#ifdef ARDUINO
void myputchar(char i){
  UDR=i;
  while(!(UCSRA&(1<<UDRE)));
}

ISR(UART_RXC){
  char a;
  a=UDR;
  if( 1){
    PORTB = 0b00100000;
  }
  else
    PORTB = 0b00000000;
}
#endif

int main(void){                         // The main function

#ifdef ARDUINO
  DDRB = 0b11111111;// Set all the pins of PORTB as output
  UCSRB=(1<<RXCIE)|(1<<RXEN)|(1<<TXEN);
  sei();
  
while (1) {                        // Set up an infinite loop                   
  
  PORTB = 0b11111111;
    
  myputchar('H');
  myputchar('E');
  myputchar('L');
  myputchar('L');
  myputchar('O');
  myputchar(' ');
  myputchar('W');
  myputchar('O');
  myputchar('R');
  myputchar('L');
  myputchar('D'); 
  _delay_ms(100); 
  PORTB = 0b00000000; 
  _delay_ms(1000);  
  }
#else
  printf("OK : %d\n",reset('a'));
#endif
}
