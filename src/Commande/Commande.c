#include "Commande.h"
#include "../common.h"

/**
 *@param minSupported minimal version supported by the Raspberry
 *@param maxSupported minimal version supported by the Raspberry
 *@return version in which Raspberry and Arduino will communicate
 **/

/**
 *@param type of reset (see definition in PROTOCOLE)
 *@return ok (see definition in PROTOCOLE)
 **/
int GetCaps(void){
  int i;
  uint8_t tmp = PINSNUMBER;

  wx[0] = 0x00;
  wx[1] = 0x00;
  wx[3] = replyId;
  wx[4] = tmp;
  for(i=0;i<PINSNUMBER;i++){
    wx[i+5] = pins[i].type;
  }
  i = i+6;
  wx[i] = 0x00; 

  replyId++;
  if(replyId == 0)
    replyId = 16;
  tmp = i;
  wx[2] = tmp;
  return true;
}

int Reset(void){
  InitPins();

  wx[0] = 0x10;
  wx[1] = 0x00;
  wx[2] = 0x05;
  wx[3] = replyId;
  wx[4] = 0x00;
  
  replyId++;
  if(replyId == 0)
    replyId = 16; 
  return true;
}

int Ping(void){
  
  uint8_t vers = 0x01;
  wx[0] = 0x30;
  wx[1] = 0x00;
  wx[2] = 0x06;
  wx[3] = replyId;
  wx[4] = vers;
  wx[5] = 0x00;
  
  replyId++;
  if(replyId == 0)
    replyId = 16;
  return true;
}



int write(void){
  uint8_t type = 0b00001110 & rx[0]; 
  int i;
  if(rx[0] == 0%2){
    SetPinType(rx[3],type);
    SetPinValue(rx[3],rx[4]);
  }
  else{
	  

    }
  }
  
  
  wx[0] = 0x40;
  wx[1] = 0x00;
  wx[2] = 0x05;
  wx[3] = replyId;
  wx[4] = 0x00;
  
  replyId++;
  if(replyId == 0)
    replyId = 16;
  return true;
}

int SetType(void){
	
  if(rx[0]&0b00000001){
    SetPinType(rx[3],rx[4]);
  }else{
    //todo
  }
  return 0;
}

int GetFailSafe(void){
  if(rx[0] == 0%2){
    get
  }else{
	if(rx[0]&0b00000001){
		int i=0;
		int npa=0;
		for(;i<PINSNUMBER;i++){
			if(rx[3+i/8]&(1<<(7-(i%8)))){
				uint8_t val1=rx[3+(PINSNUMBER+npa*3)/8]&(0b10000000>>((PINSNUMBER+3*npa)%8));
				uint8_t val2=rx[3+(PINSNUMBER+npa*3+1)/8]&(0b10000000>>((PINSNUMBER+3*npa+1)%8));
				uint8_t val3=rx[3+(PINSNUMBER+npa*3+2)/8]&(0b10000000>>((PINSNUMBER+3*npa+2)%8));
				
				uint8_t val=(val1<<2)|(val2<<1)|(val3<<0);
				val=0;
				if(val1!=0)
					val=val|1<<2;
				
				if(val2!=0)
					val=val|1<<1;
				
				if(val3!=0)
					val=val|1<<0;
				if( !SetPinType(i,val))
					return 7;
				;	
				npa++;
			}
		}
	}else{
		SetPinType(rx[3],rx[4]);
	}
	wx[0]=0x70;
	wxn=3;
	// Load upper 8-bits 
	uint8_t hi = (unsigned char)((wxn) >> 8);
	// Load lower 8-bits 
	uint8_t low = (unsigned char)((wxn)&0xff);
	wx[1]=hi;
	wx[2]=low;
	int j=0;
	for(;j<wxn;j++){
		writeSerial(wx[j]);
	}
	return 0;
}

int GetType(void){
	wxn=0;
	wx[wxn++]=0x50;//ajouter reply code
	
		
	if(rx[0]&0b00000001){
		int i=0;
		int npa=0;
		for(;i<PINSNUMBER;i++){
			if(rx[3+i/8]&(1<<(7-(i%8)))){
				pins[i].type;
				wx[3+(npa*3)/8]=wx[3+(npa*3)/8]|(((pins[i].type&0b00000100)>>2)<<(7-(3*npa)%8));
				wx[3+(npa*3+1)/8]=wx[3+(npa*3+1)/8]|(((pins[i].type&0b00000010)>>1)<<(7-(3*npa+1)%8));
				wx[3+(npa*3+2)/8]=wx[3+(npa*3+2)/8]|(((pins[i].type&0b00000001))<<(7-(3*npa+2)%8));
				wxn=3+(npa*3+2)/8;
				npa++;
			}
		}
		
		// Load upper 8-bits 
		uint8_t hi = (unsigned char)((wxn) >> 8);
		// Load lower 8-bits 
		uint8_t low = (unsigned char)((wxn)&0xff);
		wx[1]=hi;
		wx[2]=low;
	}
	else
	{
		wx[wxn++]=0x00;
		wx[wxn++]=0x01;
		wx[wxn++]=(pins[rx[3]].type<<(7-3));
	}
	int j=0;
	for(;j<wxn;j++){
		writeSerial(wx[j]);
	}

}
/* /\** */
/*  *@param states state of each pin (ex: first char -> 1-to-4 pin state) to set in safe mode */
/*  *@param values set of default values for each pin */
/*  *@return ok */
/*  **\/ */
/* char failSafe(char states[6], char *values){ */
/*   return 'a'; */
/* } */

/* /\** */
/*  *@param mode synchrone or asynchrone */
/*  *@return ok */
/*  **\/ */
/* char setMode(char mode){ */
/*   return 'a'; */
/* } */

/* /\** */
/*  *@param frequency heartbeat (on the last 4b of the char) */
/*  *@return ok */
/*  **\/ */
/* char setHeartBeat(char frequency){ */
/*   return 'a'; */
/* } */
/* /\** */
/*  *@return heartbeat on 4b */
/*  **\/ */
/* char heartBeat(){ */
/*   return 'a'; */
/* } */

/* /\** */
/*  *@param state */
/*  *@param pinId */
/*  *@param values */
/*  *@return ok */
/*  **\/ */
/* char setStateMask(char state, char pinId){ */
/*   return 'a'; */
/* } */

/* /\** */
/*  *@param state */
/*  *@param mask */
/*  *@param values */
/*  *@return ok */
/*  **\/ */
/* char setStateNoMask(char state, char mask, char *values){ */
/*   return 'a'; */
/* } */

/* int getState(); */
/* int read(); */
/* int write(); */
/* int monitorRead(); */


/* // Arduino Answering commands */
/* int error(); */
/* int ok(); */
/* int protocolVersion(); */
/* int statesValues(); */
/* int pinsValues(); */
