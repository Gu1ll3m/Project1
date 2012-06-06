#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <util/delay.h>

/*
 * SERIALINIZILISE must be done
 *
 * Initializing ADC converter, clock 1/64 div.
 * The ADC port is activated according which port we read.
 * 12 us delay is implemented for the sensor rising time.
 * After the ADC conversion, the Port is switched off, and we return the value of the ADC.
 *
 */
void adc_init(void){
	DDRA  = 0xFC;
	PORTA = 0xFC;

	sei();

	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1);	// ADC Enable, Clock 1/64div.
	return 0;
}

int adc(int a){
	    ADMUX = a; // ADC Port  Select
	    switch(a) {
			case1:
				PORTA &= ~0x80;			// ADC Port 1 IR ON
				break;
			case2:
				PORTA &= ~0x40;			// ADC Port 2 IR ON
				break;
			case3:
				PORTA &= ~0x20;			// ADC Port 3 IR ON
				break;
			case4:
				PORTA &= ~0x10;			// ADC Port 4 IR ON
				break;
			case5:
				PORTA &= ~0x08;			// ADC Port 5 IR ON
				break;
			case6:
				PORTA &= ~0x04;			// ADC Port 6 IR ON
				break;
	    }

		_delay_us(12);				// Short Delay for rising sensor signal
		ADCSRA |= (1 << ADIF);		// AD-Conversion Interrupt Flag Clear
		ADCSRA |= (1 << ADSC);		// AD-Conversion Start

		while( !(ADCSRA & (1 << ADIF)) );	// Wait until AD-Conversion complete

		PORTA = 0xFC;				         // IR-LED Off

		return ADC;
}



