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
#endif

#include "Commande/Commande.h"
#include "Parse/Parse.h"
#include "BindingAVR/BindingAVR.h"
#define MAXBUFFERSIZE 50

extern char rx[MAXBUFFERSIZE];
extern int rxn;

#endif
