/**
 * @File   Commande.h
 * @Author classerre, lleclech, rsagean
 *
 * Created on 27/11/2013, 17:07
 **/

#ifndef _BINDING_H_
#define _BINDING_H_

#include "../common.h"
void SetPort(char port,char values);
//void SetPortB(char values);
//void SetPortD(char values);
void SetPin(uint8_t pinNumber, bool value);
void InitPins(void);
void CheckPWM(uint8_t pwm8, uint16_t pwm16);

#ifndef ARDUINO
void PrintPins(uint8_t pin);
void PrintDDR();
void PrintPort();
#endif

#endif
