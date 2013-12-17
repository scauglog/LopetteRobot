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

#ifndef ARDUINO
uint8_t DDRB;
uint8_t DDRD;
uint8_t PORTB;
uint8_t PORTD;
#endif

char rx[MAXBUFFERSIZE] = {0};
int rxn = 0;
struct Pin pins[PINSNUMBER]; 


#ifdef ARDUINO
//maybe 16-1 for other baudrate than 115200
void USART_init (unsigned int ubrr) { 
  UBRRH = (unsigned char)(ubrr >> 8); // Load upper 8-bits of the baud rate value into the high byte of the UBRR register 
  UBRRL = (unsigned char)(ubrr&0xff); // Load lower 8-bits of the baud rate value into the low byte of the UBRR register 
}

/**
 * Manage interruptions filling the command's queue
 **/
ISR(USART_RXC_vect){
  rx[rxn] = UDR;//store the receive char in: a
  rxn = (rxn+1) % MAXBUFFERSIZE;
}
#else

void* routine (void* parma){
  while(true){
    char c;
    while((c = fgetc(stdin)) == EOF);
    fprintf(stdout, "je lis %c\n", c);
    rx[rxn] = c;
    rxn = (rxn + 1) % MAXBUFFERSIZE;
  }
  return NULL;
}

void Set_PC(void){
  fprintf(stdout, "Listenning...\n");
  pthread_t thread;
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  pthread_create(&thread, &attr, &routine, NULL);
}
#endif

int main(void){
#ifdef ARDUINO
  // Definitions 
  USART_init(BAUD_PRESCALE);
  
  UCSRB = (1<<RXCIE)|(1<<RXEN)|(1<<TXEN);
  sei();//system enable interrupt
  SetPortB(0b11111111);
  SetPortD(0b11111111);
#else
  Set_PC();
#endif
  PORTB=(0b00000000);
  PORTD=(0b00000000);
  InitPins();
  uint8_t PWM8=0;
  uint16_t PWM16=0;
  SetPin(0,true);
  SetPin(8,true);
  SetPin(0,false);
  while(true){
    CheckPWM(PWM8,PWM16);
    PWM8++;
    PWM16++;
  }
}


