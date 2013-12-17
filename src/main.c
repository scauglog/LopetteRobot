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
uint8_t DDRC;
uint8_t DDRD;
uint8_t PORTB;
uint8_t PORTC;
uint8_t PORTD;
#endif

char rx[MAXBUFFERSIZE] = {0};
int rxn = 0;
struct Pin pins[PINSNUMBER]; 

void initiateParse(void){
  if(rxn == 0 || rxn == 1){
  }
  else if(1 <= rxn && rxn < MAXBUFFERSIZE){
    int size = (rx[1] << 8) | (rx[2] << 0);
    if(rxn == size+4){
      parse();
      int i = 0;
      for(; i < size+4+1; i++) //DEBUG
        rx[i] = 0x00;
      rxn = 0;
    }
    else{
      int i = 0;
      for(;i<size+4;i++)
		writeSerial(rx[i]);
      writeSerial('\n');
    }
  }
  else{
    writeSerial(0xFF);
  }
  rxn = (rxn + 1) % MAXBUFFERSIZE;
}


#ifdef ARDUINO
//maybe 16-1 for other baudrate than 115200
void USART_init (unsigned int ubrr){
  // Load upper 8-bits of the baud rate value into the high byte of the UBRR register 
  UBRRH = (unsigned char)(ubrr >> 8);
  // Load lower 8-bits of the baud rate value into the low byte of the UBRR register 
  UBRRL = (unsigned char)(ubrr&0xff);
}

/**
 * Manage interruptions filling the command's queue
 **/
ISR(USART_RXC_vect){
  rx[rxn] = UDR; //store the receive char in: a
  initiateParse();
}
#else

void* routine (void* parma){
  while(true){
    char c;
    while((c = fgetc(stdin)) == EOF);
    rx[rxn] = c;
    initiateParse();
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
  SetPort('B',0b11111111);
  SetPort('C',0b11111111);
  SetPort('D',0b11111111);

#else
  Set_PC();
#endif
  PORTB=(0b00000000);
  PORTC=(0b00000000);
  PORTD=(0b00000000);
  InitPins();
  uint8_t PWM8=0;
  uint16_t PWM16=0;
  /*TEST UNITAIRE SetPIN :
  SetPin(2,true);
  SetPin(2,false);
  SetPin(12,true);
  SetPin(12,false);
  SetPin(22,true);
  SetPin(22,false);
  SetPin(21,true);
  SetPin(20,true);
  SetPin(19,true);
  SetPin(20,false);
  */
  while(true){
    CheckPWM(PWM8,PWM16);
    PWM8++;
    PWM16++;
  }

  /* TEST UNITAIRE PARSE :
     rx[0]=0b00010000;
     parse();
  */
}


