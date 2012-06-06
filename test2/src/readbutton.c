#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int readbutton(int pin){
	DDRE &= ~(1<<pin); // set button pin as input
	int bit = PINE & (1<<pin);
	return bit;
}
