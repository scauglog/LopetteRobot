#include "BindingAVR.h"

void setPortB(char values){
#ifdef ARDUINO
  DDRB = values;
#else
  int i =0;
  for(;i < 8; i++)
    if(DDRB & (1 << i))
      fprintf(stdout, "ACTIVATE PIN %d\n", i);
#endif
}

void SetPortD(char values){
	DDRD = values;
#ifndef ARDUINO
	int i =0;
	for(;i < 8; i++)
		if(DDRD & (1 << i))
			fprintf(stdout, "ACTIVATE PIN %d\n", i);
#endif
}

void SetPin(uint16_t pinNumber, bool value){
	if(pins[pinNumber].port == 'B'){
		if(value)
		  PORTB = PORTB|pins[pinNumber].number;
		else
		  PORTB = PORTB& ~pins[pinNumber].number;
	}
	if(pins[pinNumber].port == 'D'){
		if(value)
		  PORTD = PORTD|pins[pinNumber].number;
		else
		  PORTD = PORTD& ~pins[pinNumber].number;
	}
	#ifndef ARDUINO
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
	fprintf(stdout, "\n");
	#endif	
}

void InitPins(){
	int i=0;
	for(; i<PINSNUMBER;i++){
		if(i<8){
			pins[i].port='D';
			pins[i].number=(1 << i);
		}
		else if(8<=i && i<16){
			pins[i].port='B';
			pins[i].number=(1 << (i-8));

		}
		#ifndef ARDUINO
		PrintPins(i);
		#endif
	}
}

#ifndef ARDUINO
void PrintPins(uint8_t pin){
	fprintf(stdout,"pin %d | type=%d | value=%d | port=%c | number=",pin,pins[pin].type,pins[pin].value,pins[pin].port);
	int i=0;
	for(;i < 8; i++)
		if(pins[pin].number& (1 << i))
			fprintf(stdout, "1");
		else
			fprintf(stdout, "0");
	fprintf(stdout, "\n");	
}
#endif


void CheckPWM(uint8_t pwm8, uint16_t pwm16){
   int i=0;
  for(; i<PINSNUMBER;i++){
    if(pins[i].type==3){//pwm8
      if(pwm8==0)
      	SetPin(i,true);
      if(pwm8==pins[i].value)
      	SetPin(i,false);
    }
      	
    if(pins[i].type==4){//pwm16
      if(pwm16==0)
      	SetPin(i,true);
      if(pwm16==pins[i].value)
      	SetPin(i,false);
    }
  }
}

