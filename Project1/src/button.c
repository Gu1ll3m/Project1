#define F_CPU 16000000UL

#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

/* READ BUTTON
 * Button "pin" is set to input
 * Reads the button "pin"   (possible 4,5,6 and 7)
 * Returns : zero if pressed
 *
 * READKEY
 * returns a key pressed in the keyboard
 */

int readbutton(int pin){
	DDRE &= ~(1<<pin);                // set button "pin" as input
	PORTE |= 1<<pin;				  // pull-up resistor button U
	int bit = PINE & (1<<pin);
	return bit;
}

unsigned char readkey() {
	unsigned char ReceivedData = getchar();
	return ReceivedData;
}
