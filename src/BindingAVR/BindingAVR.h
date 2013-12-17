/**
 * @File   Commande.h
 * @Author classerre, lleclech, rsagean
 *
 * Created on 27/11/2013, 17:07
 **/

#include "../common.h"

void SetPortB(char values);
void SetPortD(char values);
void SetPin(uint16_t pinNumber, bool value);
void InitPins(void);
void PrintPins(uint8_t pin);
void CheckPWM(uint8_t pwm8, uint16_t pwm16);
