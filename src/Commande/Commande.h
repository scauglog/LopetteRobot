/**
 * @File   Commande.h
 * @Author classerre
 *
 * Created on 27/11/2013, 14:29
 **/


// Arduino Receptionning commands

char getProtocolVersion(char minSupported, char maxSupported);
char reset(char type);
/* char failSafe(char states[6], char *values); */
/* char setMode(char mode); */
/* char setHeartBeat(char frequency); */
/* char heartBeat(); */
/* char setStateMask(char state, char pinId); */
/* char setStateNoMask(char state, char mask, char *values); */

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
