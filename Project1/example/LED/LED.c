//##########################################################
//##                      R O B O T I S                   ##
//## CM-510 (Atmega2561) Example code for LED.            ##
//##                                           2009.11.10 ##
//##########################################################


#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRC  = 0x7F;
	PORTC = 0x7E;

	while (1)
	{
		int i;
		for(i = 0; i <= 6; i++)
		{
			PORTC = ~(1<<i);
			_delay_ms(250);
		}
	}
	return 1;
}
