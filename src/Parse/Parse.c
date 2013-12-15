#include "Parse.h"

void write(char i){
#ifdef ARDUINO
  UDR=i;
  while(!(UCSRA&(1<<UDRE)));
#else
  fprintf(stdout,"j'ecris : %c\n",i);
  fflush(stdout);
#endif
}
