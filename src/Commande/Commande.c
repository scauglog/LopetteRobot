#include "Commande.h"
#include "../common.h"

/**
 *@param minSupported minimal version supported by the Raspberry
 *@param maxSupported minimal version supported by the Raspberry
 *@return version in which Raspberry and Arduino will communicate
 **/
char getProtocolVersion(char minSupported, char maxSupported){
  // FIXME
  return maxSupported;
}

/**
 *@param type of reset (see definition in PROTOCOLE)
 *@return ok (see definition in PROTOCOLE)
 **/
char reset(char type){
  return OK;
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
