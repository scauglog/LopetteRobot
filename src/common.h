/**
 * @File   Commande.h
 * @Author classerre
 *
 * Created on 27/11/2013, 15:13
 **/

#ifndef _COMMON_H_
#define _COMMON_H_

#ifdef ARDUINO
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#else
#include <stdio.h>
#include <stdlib.h>
#endif

#include "Parse/Parse.h"
#include "Commande/Commande.h"
#include "BindingAVR/BindingAVR.h"

#endif
