#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>

#include "dynamixel.h"
#include "serial.h"
#include "led.h"

// Speeds (directions defined for Right wheel, opposite for Left wheel)
#define STOP		0
#define FWD_SLOW	200
#define FWD_FAST	400
#define BWD_SLOW	1024+FWD_SLOW
#define BWD_FAST	1024+FWD_FAST

/// Control table address
#define P_CW_ANGLE_LIMIT_L       6 // Lower bit of minimum goal pos
#define P_CW_ANGLE_LIMIT_H       7 // Set to 0 by default
#define P_CCW_ANGLE_LIMIT_L      8 // Lower bit of maximum goal pos
#define P_CCW_ANGLE_LIMIT_H      9 // Set to 1023 by default
#define P_GOAL_POSITION_L		30
#define P_GOAL_POSITION_H		31
#define P_SPEED                 32
#define P_PRESENT_POSITION_L	36
#define P_PRESENT_POSITION_H	37
#define P_MOVING				46

// Motor ids
#define WHEEL_R                  1
#define WHEEL_L                  2
#define JOINT_1          		 3
#define JOINT_2         		 4
#define JOINT_3                  5
#define JOINT_4                  6
#define JOINT_5	                 7
#define JOINT_6  				 8


// Defulat setting
#define DEFAULT_BAUDNUM		1 // 1Mbps ... CHANGE to 57.6 Kbps????
#define DEFAULT_ID			1

//int position[8];

/*static void motor_set_pos(int id, int pos){
	position[id-1] = pos;
}*/

/* Initialize motor in wheel mode setting the initial speed*/
void motor_wheel_init(int id, int initspeed){
	dxl_write_word( id, P_CCW_ANGLE_LIMIT_L, 0 );
	dxl_write_word( id, P_CCW_ANGLE_LIMIT_H, 0 );
	dxl_write_word( id, P_SPEED, initspeed );

	return 0;
}

/* Initialize motor in joint mode setting the angle limit and initial position*/
void motor_joint_init(int id, int anglim, unsigned short initpos){
	dxl_write_word( id, P_CCW_ANGLE_LIMIT_L, anglim );
	dxl_write_word( id, P_GOAL_POSITION_L, initpos );

	return 0;
}

/* Change the speed of the motor
 * Joint mode: Only 0~1023
 * Wheel mode: Full 0~2047 to control rotation direction
 * 				Move CCW: 0~1023
 * 				Move CW: 1024~2047
 * */
void motor_speed(int id, int speed){
	dxl_write_word( id, P_SPEED, speed );
}

/* Change goal position of motor*/
void motor_pos(int id, unsigned short pos){
	dxl_write_word( id, P_GOAL_POSITION_L, pos );
}

/* Check if motor is stopped (has reached goal position)
 * Returns true if stopped, false if moving and -1 if communication failed
 * */
int motor_check_stop(int id){
	int moving;
	moving = dxl_read_byte( id, P_MOVING );
	if (motor_received()){
		return moving==0;
	}
	else{
		return -1;
	}
}

/* Read current position of the motor*/
int motor_check_pos(int id){
	int pos;
	pos = dxl_read_word( id, P_PRESENT_POSITION_L );
	return pos;
}

/* Check if communication is correctly received from motor*/
int motor_received(){
	int com;
	com = dxl_get_result();
	return  com == COMM_RXSUCCESS;
}

void motor_stop(void){
	motor_speed(WHEEL_L, STOP);
	motor_speed(WHEEL_R, STOP);
}

void motor_fwd_slow(void){
	motor_speed(WHEEL_L, FWD_SLOW);
	motor_speed(WHEEL_R, BWD_SLOW);
	led_off(MANAGE);
	led_on(PROGRAM);
	led_off(PLAY);
}

void motor_bwd_slow(void){
	motor_speed(WHEEL_L, BWD_SLOW);
	motor_speed(WHEEL_R, FWD_SLOW);
}

void motor_fwd_fast(void){
	motor_speed(WHEEL_L, FWD_FAST);
	motor_speed(WHEEL_R, BWD_FAST);
}

void motor_bwd_fast(void){
	motor_speed(WHEEL_L, BWD_FAST);
	motor_speed(WHEEL_R, FWD_FAST);
}

void motor_rotr_slow(void){
	motor_speed(WHEEL_L, FWD_SLOW);
	motor_speed(WHEEL_R, FWD_SLOW);
}

void motor_rotl_slow(void){
	motor_speed(WHEEL_L, BWD_SLOW);
	motor_speed(WHEEL_R, BWD_SLOW);
}

void motor_rotr_fast(void){
	motor_speed(WHEEL_L, FWD_FAST);
	motor_speed(WHEEL_R, FWD_FAST);
}

void motor_rotl_fast(void){
	motor_speed(WHEEL_L, BWD_FAST);
	motor_speed(WHEEL_R, BWD_FAST);
}

void motor_turnr(void){
	motor_speed(WHEEL_L, FWD_FAST);
	motor_speed(WHEEL_R, BWD_SLOW);
	led_off(MANAGE);
	led_off(PROGRAM);
	led_on(PLAY);
}

void motor_turnl(void){
	motor_speed(WHEEL_L, FWD_SLOW);
	motor_speed(WHEEL_R, BWD_FAST);
	led_on(MANAGE);
	led_off(PROGRAM);
	led_off(PLAY);
}
