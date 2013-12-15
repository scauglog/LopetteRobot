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

queue command;
 
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
  char a;
  a=UDR;//store the receive char in: a
  push(command, a);
}
#else
void* routine (void* parma){
  while(true){
    char c;
    while((c = fgetc(stdin)) == EOF);
    fprintf(stdout, "je lis %c\n", c);
    push(command, c);
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
  command = create_queue();

#ifdef ARDUINO
  // Definitions 
  USART_init(BAUD_PRESCALE);
  
  UCSRB = (1<<RXCIE)|(1<<RXEN)|(1<<TXEN);
  sei();//system enable interrupt
  setPortB(0b11111111);
#else
  set_PC();
#endif
  
  char c;

  while(true){
    while(is_empty(command));
    c = top(command);
    write(c);
    pop(command);
  }
  
  /*
    while (42) {
    delay()
    execute(command);
    //break;
    */
  
  delete_queue(command);
}

