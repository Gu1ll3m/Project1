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
#include "test.h"
#include "blink.h"
#include "manblink.h"
#include "blinktimer.h"

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
	blinktimer();

	return 0;
}
