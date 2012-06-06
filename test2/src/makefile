
SOURCES=main.c dxl_hal.c zgb_hal.c test.c manblink.c readbutton.c blinktimer.c gserialtest.c serial.c dynamixel.c zigbee.c

local:
	#gcc -std=gnu99 -Wall $(SOURCES) -I ../include -lm -o Mycontroller.exe
	avr-gcc -mmcu=atmega2561 -std=gnu99 -Wall -I ../include $(SOURCES) -o main.elf
	
	avr-objcopy -O ihex -R .eeprom -R .fuse -R .lock -R .signature main.elf main.hex
	
	avr-size -C --mcu=atmega2561 main.elf
clean: 
	rm -f *.o *.out *.gch *.a *.hex *.elf *.exe