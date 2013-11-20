#define F_CPU 16000000UL                                    /* Clock Frequency = 16Mhz */

#include <inttypes.h>
#include <avr/io.h>
#include <util/delay.h>

int main(){                         // The main function
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
}
