
#include <inttypes.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void myputchar(char i){
  UDR=i;
  while(!(UCSRA&(1<<UDRE)));
}

ISR(UART_RXC)
{
  char a;
  a=UDR;
  if( 1){
    PORTB = 0b00100000;
  }
  else
    PORTB = 0b00000000;
}


int main(){                          // The main function
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
}
