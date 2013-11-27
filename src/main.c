
#include <inttypes.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void myputchar(char i){
  UDR=i;
  while(!(USR&(1<<TXC)));
}

ISR(UART_RXC)
{
  char a;
  a=UDR;
  if( a=='o'){
    PORTB = 0b00100000;
  }
  else
    PORTB = 0b00000000;
}


int main(){                          // The main function
  DDRB = 0b11111111;// Set all the pins of PORTB as output
  UCR=(1<<RXCIE)|(1<<RXEN)|(1<<TXEN);
  sei();
  
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

while (1) {                        // Set up an infinite loop                   
  //PORTB = 0b00000001;
  //  _delay_ms(50);
    
    
    
  }
}
