/*
 ============================================================================
 Name        : modular1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>


// Robitis API
#include "serial.h"
//#include "zigbee.h"
//#include "zgb_hal.h"
//#include "dynamixel.h"
//#include "dxl_hal.h"

// OUR API
#include "adc.h"
#include "button.h"
//#include "led.h"
//#include "irlong.h"
//#include "irshort.h"
//#include "touch.h"
//#include "gyro.h"
//#include "motor.h"


int main(void) {
	int value, butt;
	unsigned char Data;

	serial_initialize(57600);				// USART Initialize
	adc_init();

	while(1){
		butt = readbutton(4);
		Data = readkey();

		if(Data == 'u'){
			value = adc(2);
			printf("%d\r\n", value);
		}
		else if(Data == 'd'){
			printf("Hello");
		}

		_delay_ms(500);
	}
	return 0;
}
