#include "BindingAVR.h"
void SetPort(char port, char values){
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
	}
	#ifndef ARDUINO
	PrintDDR();
	#endif
}

void SetPin(uint8_t pinNumber, bool value){
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
	}
	#ifndef ARDUINO
	PrintPort();
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

		}else if(16<=i && i<24){
			pins[i].port='C';
			pins[i].number=(1 << (i-16));
		}
		#ifndef ARDUINO
		PrintPins(i);
		#endif
	}
}

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

void PrintDDR(){
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

void PrintPort(){
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
