/*
 ============================================================================
 Name        : modular1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#define F_CPU 16000000UL // CM-510 runs at 16 MHz.

#include <stdio.h>
#include <stdlib.h>
#include "test.h"
#include "blink.h"
#include "manblink.h"
#include "blinktimer.h"
#include "gserialtest.h"

int main(void) {
	//cm510_init();
	//controller_init();

    // Hello World printing and using header file
	//printme();

	// LED blinking 0,5 Hz
    //blink();

	//Button controller LEDs
	//manblink();

	// Timer controlled LEDs
	//blinktimer();

	gserialtest();
	return 0;
}
