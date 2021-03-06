/**
 * @File   Commande.h
 * @Author classerre
 *
 * Created on 27/11/2013, 15:13
 **/

#ifndef _COMMON_H_
#define _COMMON_H_

#include <stdint.h>
#include <stdbool.h>

#ifdef ARDUINO
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define NULL 0
#else
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
extern uint8_t DDRB;
extern uint8_t DDRC;
extern uint8_t DDRD;
extern uint8_t PORTB;
extern uint8_t PORTC;
extern uint8_t PORTD;
#endif

#define PINSNUMBER 23
// MAXBUFFERSIZE = 1+2+3+PINSNUMBER*2+1 (cf report)
#define MAXBUFFERSIZE 53
struct Pin{
  uint8_t type;
  uint16_t value;
  char port;
  uint8_t number;
  uint8_t state;
  uint16_t timeOut;
};

extern struct Pin pins[PINSNUMBER]; 
extern uint8_t rx[MAXBUFFERSIZE];
extern int rxn;
extern uint8_t wx[MAXBUFFERSIZE];
extern int wxn;
extern uint8_t replyId;

#include "Commande/Commande.h"
#include "BindingAVR/BindingAVR.h"
#include "Parse/Parse.h"

#endif


