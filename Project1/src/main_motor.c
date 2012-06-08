/*
 ============================================================================
 Name        : modular1.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#define F_CPU 16000000UL

#include <stdio.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>


// Robitis API
//#include "serial.h"
#include "zigbee.h"
#include "zgb_hal.h"
#include "dynamixel.h"
#include "dxl_hal.h"

// OUR API
#include "adc.h"
#include "button.h"
#include "motor.h"


int main(void) {
	//int value, butt;
	unsigned char Data, RcvData;
	int pos1, pos2, speedl, speedr, state1, state2;

	// General initialization
	//serial_initialize(57600);
	dxl_initialize( 0, DEFAULT_BAUDNUM ); // Not using device index

	PORTD &= ~0x80;	//PORT_LINK_PLUGIN = 0;   // no pull up
	PORTD &= ~0x20;	//PORT_ENABLE_RXD_LINK_PC = 0;
	PORTD |= 0x40;	//PORT_ENABLE_RXD_LINK_ZIGBEE = 1;

	sei();
	zgb_initialize( 0 );

	// Joint 1 initialization
	pos1 = 0;
	motor_joint_init(JOINT_1, 1023, pos1);
	state1 = 0;

	// Joint 2 initializtion
	pos2 = 0;
	motor_joint_init(JOINT_2, 1023, pos2);
	state2 = 0;

	// Left wheel initialization
	speedl = 0;
	motor_wheel_init(WHEEL_L, speedl);

	// Right wheel initialization
	speedr = 0;
	motor_wheel_init(WHEEL_R, speedr);

	while(1){

		if(zgb_rx_check() == 1)  {

			RcvData = zgb_rx_data();
			//zgb_tx_data(RcvData);
			//printf("RcvData");
			Data = (unsigned char)RcvData;

			//Data = readkey();

			// Move Joint 1
			if(Data == 'r'){
				motor_fwd_slow();
			}
			// Move Joint 2
			else if(Data == 't'){
				motor_fwd_fast();
			}
			else if(Data == 'c'){
				motor_bwd_slow();
			}
			else if(Data == 'v'){
				motor_bwd_fast();
			}
			else if(Data == 'd'){
				motor_rotl_slow();
			}
			else if(Data == 's'){
				motor_rotl_fast();
			}
			else if(Data == 'g'){
				motor_rotr_slow();
			}
			else if(Data == 'h'){
				motor_rotl_fast();
			}
			else if(Data == 'f'){
				motor_stop();
			}
			/*
		// Test wheels and joints
		// Move Joint 1
		if(Data == 'w'){
			state1 = motor_check_stop(JOINT_1);
			if(state1){
				if (pos1==0)
					pos1 = 512;
				else
					pos1 = 0;
			}
			motor_pos(JOINT_1, pos1);
			printf("Moving joint 1 to pos %d\r\n", pos1);
		}
		// Move Joint 2
		else if(Data == 's'){
			state2 = motor_check_stop(JOINT_2);
			if(state2){
				if (pos2==0)
					pos2 = 512;
				else
					pos2 = 0;
			}
			printf("Moving joint 2 to pos %d\r\n", pos2);
			motor_pos(JOINT_2, pos2);
		}
		// Start/stop Left wheel
		else if(Data == 'a'){
			if(speedl == 0){
				speedl = 300;
				printf("Moving left wheel\r\n");
			}
			else{
				speedl = 0;
				printf("Stopping left wheel\r\n");
			}
			motor_speed(WHEEL_L, speedl);
		}
		// Start/stop Right wheel
		else if(Data == 'd'){
			if(speedr == 0){
				speedr = 300;
				printf("Moving right wheel");
			}
			else{
				speedr = 0;
				printf("Stopping right wheel");
			}
			motor_speed(WHEEL_R, speedr);
		}*/

			_delay_ms(100);
		}
	}
	zgb_terminate();
	return 0;
}


