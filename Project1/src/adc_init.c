#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


void adc_init(void){


	DDRA  = 0xFC;
	PORTA = 0xFC;

	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1);	// ADC Enable, Clock 1/64div.
	return 0;	

	}

