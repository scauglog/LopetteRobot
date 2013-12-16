#include "Parse.h"

void write(char i){
#ifdef ARDUINO
  UDR=i;
  while(!(UCSRA&(1<<UDRE)));
#else
  fprintf(stdout,"%c ", i);
  fflush(stdout);
#endif
}
