#include <math.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>

#include "adc.h"
#include "sensor.h"
#include "serial.h"
//#include "robot.h"      Sure we need to include it??
//#include "zigbee.h"
#include "led.h"
#include "motor.h"

// Thresholds for IR wall following
#define CLOSE    10
#define FAR      3
#define DIFF     20

// States
#define FOLLOWL   0b01
#define FOLLOWR   0b10
#define CORRIDOR  0b11

// Sensor identifiers
#define IR_LEFT   3
#define IR_RIGHT  2
#define IR_CENTER 0

// Global variable to store the sensed data for each port
int sensordata[6] = {0,0,0,0,0,0};
int CONFIG[6] = {1,0,1,1,0,0};
int farl = 0;
int farr = 0;

void robot_init(void){

	serial_initialize(57600);	             // USART Initialize
	sei();                                   // Interrupt enable
	//dxl_initialize( 0, DEFAULT_BAUDNUM );    // initialize motors

	if ( timeint_init() ){}
	else{
		printf("error initializing time interrupt \n");
	}

	// initialize zigbee
	//if ( zigbee_init() ){}
	//else{
	//	printf('error initializing zigbee');
	//}


	/*/ initialize sensors distribution
	if (sensors_init(CONFIG)){}
	else{
		printf('error initializing sensors');
	}
	*/

	// initializing ADC converters (after init_sensor)
	if ( adc_init() ){}
	else{
		printf("error initializing adc \n");
	}

	//leds_init
    //motors_init
}
/*------------------------------------------------------------------*/
int robot_sensor(int s){
	return sensordata[s];
}
/*------------------------------------------------------------------*/
void robot_sense(int s){
	sensordata[s] = adc(s+1);
}
/*------------------------------------------------------------------*/
// Wall following behaviours
void robot_followl(void){
	if (robot_sensor(IR_LEFT)>CLOSE){
	    	motor_turnr();
	    }
	    else if(robot_sensor(IR_LEFT)<FAR){
	    	motor_turnl();
	    }
	    else{
	    	motor_fwd_slow();
	    }
}
/*--------------------------------------------------------------------*/
void robot_followr(void){
	if (robot_sensor(IR_RIGHT)>CLOSE){
	    	motor_turnl();
	    }
	    else if(robot_sensor(IR_RIGHT)<FAR){
	    	motor_turnr();
	    }
	    else{
	    	motor_fwd_slow();
	    }
}
/*--------------------------------------------------------------------*/
void robot_corridor(void){
	if ((robot_sensor(IR_RIGHT)-robot_sensor(IR_LEFT))>DIFF){
	    	motor_turnl();
	    }
	    else if((robot_sensor(IR_RIGHT)-robot_sensor(IR_LEFT))>DIFF){
	    	motor_turnr();
	    }
	    else{
	    	motor_fwd_slow();
	    }
}
/*--------------------------------------------------------------------*/
void robot_actuate(void){
	//The program
	int i;

	for ( i=0 ;i <= 5 ; i++){
		printf("S %d: %d   ",i+1,sensordata[i]);
	}
	printf(" \r\n");

    /*if ((robot_sensor(IR_LEFT)>CLOSE)&&(robot_sensor(IR_RIGHT)<CLOSE)){
    	motor_rotl_slow();
    }
    else if((robot_sensor(IR_LEFT)<CLOSE)&&(robot_sensor(IR_RIGHT)>CLOSE)){
    	motor_rotr_slow();
    }
    else if((robot_sensor(IR_LEFT)>CLOSE)&&(robot_sensor(IR_RIGHT)>CLOSE)){
    	motor_fwd_slow();
    }
    else{
    	motor_stop();
    }*/

	if (robot_sensor(IR_CENTER)>FAR){
		motor_stop();
	}
	else{
		robot_followl();
	}

	_delay_ms(1000);
}
/*------------------------------------------------------------------*/
void robot_destroy(void){
	//void zgb_terminate(void);
	//void dxl_terminate();
}
/*--------------------------------------------------------------------*/
// Interruptions

ISR(TIMER1_COMPA_vect) {

	int reading, i;

	for( i=0; i<=5; i++){         // i = port - 1

		if (CONFIG[i] != 0){        // if a sensor is connected...

			reading = adc(i+1);      // Read sensor

					switch( CONFIG[i] ){      // CONFIG(i) = type

					case 1:   // initialize IR
						sensordata[i] = reading;
						//robot_sense(i);
						//sensordata(i) = 685/sqrt(reading+4);
						break;
					case 2:   // initialize dms
						//sensordata(i) = conversiondms(reading);
						break;
					case 3:   // initialize touch
						//sensordata(i) = conversiontouch(reading);
						break;
					case 4:   // initialize gyro
						//sensordata(i) = conversiongyro(reading);
						break;
					}
		}
	}
	OCR1A += 1240;
}

