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

char rx[MAXBUFFERSIZE] = {0};
int rxn = 0;

void initiateParse(void){
  if(rxn == 0 || rxn == 1){
  }
  else if(1 <= rxn && rxn < MAXBUFFERSIZE){
    int size = (rx[1] << 8) | (rx[2] << 0);
    if(rxn == size+4){
      write('P');
      write('A');
      write('R');
      write('S');
      write('E');
      int i = 0;
      //for(; i < size+4; i++) //DEBUG
      //x[i] = 0;
      rxn = 0;
    }
    else{
      int i = 0;
      for(;i<size+4;i++)
	write(rx[i]);
      write('\n');
    }
  }
  else{
    write(0xFF);
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

void set_PC(void){
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
  setPortB(0b11111111);
#else
  set_PC();
#endif

  while(true){
    //while(rxn == 0);
    //write(rx[rxn]);
    //rx[rxn] = 0;
    //rxn = (rxn-1) % MAXBUFFERSIZE;
  }
}
