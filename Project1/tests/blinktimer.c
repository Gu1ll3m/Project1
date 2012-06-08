#define F_CPU 16000000UL // CM-510 runs at 16 MHz.

#include <avr/io.h>
#include <avr/interrupt.h>

/** Example on how to setup a timer on the CM510 (Atmega2561) */

void blinktimer() {
	DDRC |= 1<<4; 						// set Manage LED as output
	DDRC |= 1<<5; 						// set Manage LED as output
	DDRC |= 1<<6; 						// set Manage LED as output


	TCCR1B = (1<<CS12);//|(1<<CS10); 	//256 Prescaler
	OCR1A = 1240;
	OCR1B = 5000;
	OCR1C = 10000;
	TIMSK1 = (1<<OCIE1A)|(1<<OCIE1B)|(1<<OCIE1C);//Enable Output Compare Match Interrupt
	TCNT1 = 0; 							         //reset timer/counter 1
	sei(); 								         //Enables global interrupts
	while(1) {}
}

ISR(TIMER1_COMPA_vect) {
	PORTC ^= 1 << 4; // swap LED
	OCR1A += 1240; //
}

ISR(TIMER1_COMPB_vect) {
	PORTC ^= 1 << 5; // swap LED
	OCR1B += 5000;
}

ISR(TIMER1_COMPC_vect) {
	PORTC ^= 1 << 6; // swap LED
	OCR1C += 10000;
}

