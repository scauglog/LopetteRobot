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
  int i;
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
