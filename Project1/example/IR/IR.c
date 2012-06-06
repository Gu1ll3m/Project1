//##########################################################
//##                      R O B O T I S                   ##
//## CM-510 (Atmega2561) Example code for IR Sensor.      ##
//##                                           2009.11.10 ##
//##########################################################


#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "serial.h"

#define		ADC_PORT_1	1
#define		ADC_PORT_2	2
#define		ADC_PORT_3	3
#define		ADC_PORT_4	4
#define		ADC_PORT_5	5
#define		ADC_PORT_6	6

int main(void)
{
	DDRA  = 0xFC;
	PORTA = 0xFC;

	serial_initialize(57600);
	sei();

	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1);	// ADC Enable, Clock 1/64div.
	ADMUX = ADC_PORT_1;										// ADC Port 1 Select

	printf( "\n\nIR example for CM-510\n\n" );

	while (1)
	{
		PORTA &= ~0x80;			// ADC Port 1 IR ON
//		PORTA &= ~0x40;			// ADC Port 2 IR ON
//		PORTA &= ~0x20;			// ADC Port 3 IR ON
//		PORTA &= ~0x10;			// ADC Port 4 IR ON
//		PORTA &= ~0x08;			// ADC Port 5 IR ON
//		PORTA &= ~0x04;			// ADC Port 6 IR ON

		_delay_us(12);				// Short Delay for rising sensor signal
		ADCSRA |= (1 << ADIF);		// AD-Conversion Interrupt Flag Clear
		ADCSRA |= (1 << ADSC);		// AD-Conversion Start
		
		while( !(ADCSRA & (1 << ADIF)) );	// Wait until AD-Conversion complete
		
		PORTA = 0xFC;				// IR-LED Off
		
		printf( "%d\r\n", ADC); // Print Value on USART
					
		_delay_ms(50);
	}
	return 1;
}
