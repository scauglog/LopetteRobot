/**
 * @File   Commande.h
 * @Author classerre, lleclech, rsagean
 *
 * Created on 27/11/2013, 14:29
 **/

#include <inttypes.h>
#ifdef ARDUINO
#include <avr/io.h>
#include <util/delay.h>
#else
#include <stdio.h>
#include <stdlib.h>
#include "Commande/Commande.h"
#include "common.h"
#endif

int main(void){                         // The main function
#ifdef ARDUINO
  DDRB = 0b11111111;                    // Set all the pins of PORTB as output
  while (1) {                        // Set up an infinite loop
    PORTB = 0b10000000;                    // Turn on LED1
    _delay_ms(50);                        // Wait
    PORTB = 0b01000000;                    // Turn on LED2
    _delay_ms(50);                        // Wait
    PORTB = 0b00100000;                    // The same sequence repeats…
    _delay_ms(50);
    PORTB = 0b00010000;
    _delay_ms(50);
    PORTB = 0b00001000;
    _delay_ms(50);
    PORTB = 0b00000100;
    _delay_ms(50);
    PORTB = 0b00000010;
    _delay_ms(50);
    PORTB = 0b00000001;
    _delay_ms(50);
  }
#else
  printf("OK : %d\n",reset('a'));
#endif
}
