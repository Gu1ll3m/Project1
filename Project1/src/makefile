
SOURCES = main.c  motor.c adc.c button.c dxl_hal.c dynamixel.c led.c robot.c sensor.c serial.c
# zigbee.c zgb_hal.c 
# main_motor.c

local:
    # To compile
	#gcc -std=gnu99 -Wall $(SOURCES) -I ../include -lm -o Mycontroller.exe
	#To Cross-Compile
	avr-gcc -mmcu=atmega2561 -std=gnu99 -Wall -I ../include $(SOURCES) -o main.elf
	avr-objcopy -O ihex -R .eeprom -R .fuse -R .lock -R .signature main.elf main.hex
	avr-size -C --mcu=atmega2561 main.elf
clean: 
	rm -f *.o *.out *.gch *.a *.hex *.elf *.exe
	
