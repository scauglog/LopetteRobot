#include "BindingAVR.h"
bool SetPort(char port, char values){
  switch(port){
  case 'B':
    DDRB = values;
    break;
  case 'C':
    DDRC = values;
    break;
  case 'D':
    DDRD = values;
    break;
  default:
    return false;
  }
#ifndef ARDUINO
  PrintDDR();
#endif
  return true;
}

bool SetPinState(uint8_t pinNumber, bool value){
  switch(pins[pinNumber].port){
  case 'B':
    if(value)
      PORTB = PORTB|pins[pinNumber].number;
    else
      PORTB = PORTB& ~pins[pinNumber].number;
    break;
  case 'C':
    if(value)
      PORTC = PORTC|pins[pinNumber].number;
    else
      PORTC = PORTC& ~pins[pinNumber].number;
    break;
  case 'D':
    if(value)
      PORTD = PORTD|pins[pinNumber].number;
    else
      PORTD = PORTD& ~pins[pinNumber].number;
    break;
  default:
  	return false;
  }
#ifndef ARDUINO
  PrintPort();
#endif
  return true;	
}
bool SetPinType(uint8_t pinNumber, uint8_t type){
	pins[pinNumber].type=type;
#ifndef ARDUINO
    PrintPins(pinNumber);
#endif
	return true;
}

bool SetPinValue(uint8_t pinNumber, uint16_t value){
	pins[pinNumber].value=value;
#ifndef ARDUINO
    PrintPins(pinNumber);
#endif
	return true;
}

bool InitPins(void){
  int i=0;
  for(; i<PINSNUMBER;i++){
    if(i<8){
      pins[i].port='D';
      pins[i].number=(1 << i);
    }
    else if(8<=i && i<16){
      pins[i].port='B';
      pins[i].number=(1 << (i-8));

    }else if(16<=i && i<24){
      pins[i].port='C';
      pins[i].number=(1 << (i-16));
    }else{
      return false;
    }
    pins[i].type=0;
    pins[i].value=0;
    pins[i].state=0;
#ifndef ARDUINO
    PrintPins(i);
#endif
  }
  PORTB=(0b00000000);
  PORTC=(0b00000000);
  PORTD=(0b00000000);
  return true;
}

void CheckPWM(uint8_t pwm8, uint16_t pwm16){
  int i=0;
  for(; i<PINSNUMBER;i++){
    if(pins[i].type==1&&(pins[i].state!=pins[i].value)){
    	pins[i].state=pins[i].value;
    	SetPinState(i,pins[i].state);
    }
    
    if(pins[i].type==3){//pwm8
      if(pwm8==0)
      	SetPinState(i,true);
      if(pwm8==pins[i].value)
      	SetPinState(i,false);
    }
      	
    if(pins[i].type==4){//pwm16
      if(pwm16==0)
      	SetPinState(i,true);
      if(pwm16==pins[i].value)
      	SetPinState(i,false);
    }
    
  }
}


#ifndef ARDUINO
void PrintPins(uint8_t pin){
  fprintf(stdout,"pin %d | state=%d | type=%d | value=%d | port=%c | number=",pin,pins[pin].state,pins[pin].type,pins[pin].value,pins[pin].port);
  int i=0;
  for(;i < 8; i++)
    if(pins[pin].number& (1 << i))
      fprintf(stdout, "1");
    else
      fprintf(stdout, "0");
  fprintf(stdout, "\n");	
}

void PrintDDR(void){
  fprintf(stdout, "DDRD= ");
  int i = 0;
  for(;i < 8; i++)
    if(DDRD& (1 << i))
      fprintf(stdout, "1");
    else
      fprintf(stdout, "0");
  fprintf(stdout, " | ");	
	
  fprintf(stdout, "DDRB= ");
  for(i =0;i < 8; i++)
    if(DDRB& (1 << i))
      fprintf(stdout, "1");
    else
      fprintf(stdout, "0");
  fprintf(stdout, " | ");	
	
  fprintf(stdout, "DDRC= ");
  for(i =0;i < 8; i++)
    if(DDRC& (1 << i))
      fprintf(stdout, "1");
    else
      fprintf(stdout, "0");
  fprintf(stdout, "\n");
}

void PrintPort(void){
  fprintf(stdout, "PORTD= ");
  int i = 0;
  for(;i < 8; i++)
    if(PORTD& (1 << i))
      fprintf(stdout, "1");
    else
      fprintf(stdout, "0");
  fprintf(stdout, " | ");	
	
  fprintf(stdout, "PORTB= ");
  for(i =0;i < 8; i++)
    if(PORTB& (1 << i))
      fprintf(stdout, "1");
    else
      fprintf(stdout, "0");
  fprintf(stdout, " | ");	
	
  fprintf(stdout, "PORTC= ");
  for(i =0;i < 8; i++)
    if(PORTC& (1 << i))
      fprintf(stdout, "1");
    else
      fprintf(stdout, "0");
  fprintf(stdout, "\n");
}
#endif
