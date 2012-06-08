/*
 * led.c
 *
 *  Created on: 06/06/2012
 *      Author: willy
 */

#define F_CPU 16000000UL // CM-510 runs at 16 MHz.

#include <avr/io.h>
#include <avr/interrupt.h>

// Led identifier
#define MANAGE	4
#define PROGRAM	5
#define PLAY	6

void led_init(void){
	DDRC |= 1<<MANAGE; 						// set Manage LED as output
	DDRC |= 1<<PROGRAM; 					// set Program LED as output
	DDRC |= 1<<PLAY; 						// set Play LED as output
}

void led_toggle(int led){
	PORTC ^= 1 << led; // toggle LED;
}

void led_off(int led){
	PORTC |= 1 << led; // LED on;
}

void led_on(int led){
	PORTC &= ~(1 << led); // LED off;
}
