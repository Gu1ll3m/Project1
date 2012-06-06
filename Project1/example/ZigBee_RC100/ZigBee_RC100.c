//##########################################################
//##                      R O B O T I S                   ##
//## CM-510 (Atmega2561) Example code for Dynamixel.      ##
//##                                           2009.11.10 ##
//##########################################################

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <util/delay.h>

#include "zigbee.h"

#define LED_BAT 0x01
#define LED_TxD 0x02
#define LED_RxD 0x04
#define LED_AUX 0x08
#define LED_MANAGE 0x10
#define LED_PROGRAM 0x20
#define LED_PLAY 0x40

int main(void)
{
	int RcvData;

	DDRC  = 0x7F;
	PORTC = 0x7E;

	PORTD &= ~0x80;	//PORT_LINK_PLUGIN = 0;   // no pull up
	PORTD &= ~0x20;	//PORT_ENABLE_RXD_LINK_PC = 0;
	PORTD |= 0x40;	//PORT_ENABLE_RXD_LINK_ZIGBEE = 1;

	zgb_initialize( 0 ); // Not using device index
	sei();	// Interrupt Enable	
	
	while(1)
	{
		if(zgb_rx_check() == 1)
		{
			RcvData = zgb_rx_data();
			if(RcvData & RC100_BTN_1)
				PORTC &= ~LED_MANAGE;
			else
				PORTC |= LED_MANAGE;
			
			if(RcvData & RC100_BTN_2)
				PORTC &= ~LED_PROGRAM;
			else
				PORTC |= LED_PROGRAM;
				
			if(RcvData & RC100_BTN_3)
				PORTC &= ~LED_PLAY;
			else
				PORTC |= LED_PLAY;
		}
	}

	return 0;
}

