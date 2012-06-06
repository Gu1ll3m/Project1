#define F_CPU 16000000UL
#include <avr/io.h>
//#include <util/delay.h>
#include <avr/interrupt.h>

void blinktimer(void){
	DDRC |= 1<<4; // set Manage LED as output
	DDRC |= 1<<5; // set Manage LED as output
	DDRC |= 1<<6; // set Manage LED as output

	TCCR1B = (1<<CS11)|(1<<CS10);		//
	OCR1A = 12400;
	//OCR1B = 1240;
	//OCR1C = 12400;

	TIMSK1 = (1<<OCIE1A);//|(1<<OCIE1B)|(1<<OCIE1C); // Enable three interrupts
	TCNT1 = 0; // Reset counter
	sei();      // enable global interrupts

	while(1) {}
	//return 0;
}


// Interrupts
IRS(TIMER1_COMPA_vect) {
	PORTC ^= 1 << 4; // swap LED
	OCR1A += 124;
}
/*
IRSB(TIMER1_COMPB_vect) {
	PORTC ^= 1 << 5; // swap LED
	OCR1B += 1240;
}

IRSC(TIMER1_COMPC_vect) {
	PORTC ^= 1 << 6; // swap LED
	OCR1C += 12400;
}
*/
