/**
 * @File   Commande.h
 * @Author classerre
 * @Author lleclech
 *
 * Created on 27/11/2013, 14:29
 **/


// Arduino Receptionning commands

//char getProtocolVersion(char minSupported, char maxSupported);
int GetCaps(void);
int Reset(void);
int Ping(void);
/* int getState(); */
/* int setState(); */
/* int read(); */
/* int write(); */
/* int getType(); */
int SetType(void);
/* int getFailSafe(); */
/* int setFailSafe(); */



/* // Arduino Answering commands */
/* int error(); */
/* int ok(); */
/* int protocolVersion(); */
/* int statesValues(); */
/* int pinsValues(); */
