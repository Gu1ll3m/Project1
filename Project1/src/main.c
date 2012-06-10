/*
 ============================================================================
 Name        : modular1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

// System API
//#include <stdio.h>
//#include <stdlib.h>
//#include <avr/interrupt.h>
//#include <avr/io.h>
//#include <util/delay.h>

// Robitis API
//#include "serial.h"
//#include "zigbee.h"
//#include "zgb_hal.h"
//#include "dynamixel.h"
//#include "dxl_hal.h"

// OUR API
#include "robot.h"    //All the robot initializations
//#include "adc.h"
//#include "button.h"
//#include "led.h"
//#include "sensor.h"
//#include "motor.h"

//#define F_CPU 16000000UL // CM-510 runs at 16 MHz.

int main(void){

	robot_init();

	while(1){
		robot_actuate();
	}
	robot_destroy();
	return 0;
}
