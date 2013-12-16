#include "BindingAVR.h"

void setPortB(char values){
#ifdef ARDUINO
  DDRB = values;
#else
  int i =0;
  for(;i < 8; i++)
    if(values & (1 << i))
      fprintf(stdout, "ACTIVATE PIN %d\n", i);
#endif
}

