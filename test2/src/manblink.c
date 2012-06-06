#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "readbutton.h"

// comment

void manblink(void){
	int U = 0;
	int L = 0;
	DDRE &= ~(1<<4); // set U button as input
	DDRE &= ~(1<<6); // set L button as input
	PORTE |= 1<<4;	// pull-up resistor button U
	PORTE |= 1<<6;	// pull-up resistor button L
	DDRC |= 1<<4; // set Manage LED as output
	DDRC |= 1<<6; // set Play LED as output
	//DDRC |= 0b01010000;
	while(1){
		U = readbutton(4); // read U button (low if pressed)
		L = readbutton(6); // read L button (low if pressed)
		// Toggle Manage LED
		if (U==0) {
			PORTC ^= 1 << 4;
		}
		// Turn on Play LED (clear pin)
		if (L==0) {
			PORTC &= ~(1 << 6);
		}
		// Turn off Play LED (set pin)
		else {
			PORTC |= 1 << 6;
		}
		_delay_ms(100); // wait 1 second
	}

}
