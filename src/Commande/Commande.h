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
 *@param states state of each pin (ex: first char -> 1-to-4 pin state) to set in safe mode
 *@param values set of default values for each pin
 *@return ok
 **/
char failSafe(char states[6], char *values);

/**
 *@param mode synchrone or asynchrone
 *@return ok
 **/
char setMode(char mode);

/**
 *@param frequency heartbeat (on the last 4b of the char)
 *@return ok
 **/
char setHeartBeat(char frequency);

/**
 *@return heartbeat on 4b
 **/
char heartBeat();

/**
 *@param state
 *@param pinId
 *@param values
 *@return ok
 **/
char setStateMask(char state, char pinId);

/**
 *@param state
 *@param mask
 *@param values
 *@return ok
 **/
char setStateNoMask(char state, char mask, char *values);


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
