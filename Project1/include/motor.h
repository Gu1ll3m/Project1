/*
 * motor.h
 *
 *  Created on: 06/06/2012
 *      Author: willy
 */

#ifndef MOTOR_H_
#define MOTOR_H_

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

void motor_wheel_init(int id, int initspeed);
void motor_joint_init(int id, int anglim, unsigned short initpos);
void motor_speed(int id, int speed);
void motor_pos(int id, unsigned short pos);
int motor_check_stop(int id);
int motor_check_pos(int id);
int motor_received(void);
void motor_stop(void);
void motor_fwd_slow(void);
void motor_bwd_slow(void);
void motor_fwd_fast(void);
void motor_bwd_fast(void);
void motor_rotl_slow(void);
void motor_rotr_slow(void);
void motor_rotl_fast(void);
void motor_rotr_fast(void);
void motor_turnr(void);
void motor_turnl(void);

#endif /* MOTOR_H_ */
