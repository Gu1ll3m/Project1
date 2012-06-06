#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
// Farid added comment
int readbutton(int pin){
<<<<<<< HEAD
	DDRE &= ~(1<<pin); // set button pin as input
	int bit = PINE & (1<<pin);
=======
	//DDRE &= ~(1<<pin); // set button pin as input
	int bit = PINE & (1<<pin);//this is the comment i added, Balint:)!!!
>>>>>>> 1c31f118829cd037da4c605db1be661284dc62db
	return bit;
}
