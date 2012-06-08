#define F_CPU 16000000UL // CM-510 runs at 16 MHz.

#include <avr/io.h>
#include <avr/interrupt.h>

#include "serial.h"
#include "zigbee.h"
#include "robot.h"
#include "sensor.h"
#include "adc.h"

// Inicialize time interrupts used to sense
int timeint_init(void){

	TCCR1B = (1<<CS12);     //256 Prescaler
	//(1<<CS11)|(1<<CS10); 	//64 Prescaler

	OCR1A = 1240; // high freq for IR and DMS
	//OCR1B = 5000; // middle freq for Touch
	//OCR1C = 10000;// low freq for gyro

	TIMSK1 = (1<<OCIE1A);                      //Enable Output Compare Match Interrupt
	//TIMSK1 = (1<<OCIE1A)|(1<<OCIE1B)|(1<<OCIE1C);
	TCNT1 = 0; 							          //reset timer/counter 1

	return 1;
}

/*--------------------------------------------------------------------
int zigbee_init(){

	PORTD &= ~0x80;	//PORT_LINK_PLUGIN = 0;   // no pull up
	PORTD &= ~0x20;	//PORT_ENABLE_RXD_LINK_PC = 0;
	PORTD |= 0x40;	//PORT_ENABLE_RXD_LINK_ZIGBEE = 1;

	zgb_initialize( 0 ); // Not using device index
	return 1;
}
*/

/*--------------------------------------------------------------------
// Initialize the ports for all sensors connected to the micro controller
// Possible pecific initializations depending on type of sensor
void init_sensors (CONFIG){

	for( i=0; i<=5; i++){         // i = port
		switch( CONFIG(i) ){      // CONFIG(i) = type
		    case 0:   // Do nothing

		    	break;
			case 1:   // initialize IR

				break;
			case 2:   // initialize dms

				break;
			case 3:   // initialize touch

				break;
			case 4:   // initialize gyro

				break;
		}
	}
}
*/

