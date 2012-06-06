#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void blink(void){
	//comment
	DDRC = 0x01; // set LED pin as output
	while(1){
		PORTC = 0x00; // turn on LED (PC0 high)
		_delay_ms(1000); // wait 1 second
		PORTC = 0x01; // turn off LED (PC0 low)
		_delay_ms(1000); // wait 1 second
	}
	return 0;
}
