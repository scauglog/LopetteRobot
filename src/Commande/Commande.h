/**
 * 
 **/
/* Arduino Receptionning commands */

/**
 *@param minSupported minimal version supported by the Raspberry
 *@param maxSupported minimal version supported by the Raspberry
 *@return version in which Raspberry and Arduino will communicate
 **/
char getProtocolVersion(char minSupported, char maxSupported);
/**
 *@param type of reset (see definition in PROTOCOLE)
 *@return ok (see definition in PROTOCOLE)
 **/
char reset(char type);
/**
 *@param
 **/
int failSafe(char states[6], char *values);

int setMode();
int setHeartBeat();
int heartBeat();
int setState();
int getState();
int read();
int write();
int monitorRead();


/* Arduino Answering commands */
int error();
int ok();
int protocolVersion();
int statesValues();
int pinsValues();
