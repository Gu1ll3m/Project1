/*
 * led.h
 *
 *  Created on: 06/06/2012
 *      Author: willy
 */

#ifndef LED_H_
#define LED_H_

// Led identifier
#define MANAGE	4
#define PROGRAM	5
#define PLAY	6

void led_init(void);
void led_toggle(int led);
void led_on(int led);
void led_off(int led);

#endif /* LED_H_ */
