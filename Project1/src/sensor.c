
//Headers missing



/* Initialize all sensors connected to the micro controller
 *
 * config is an array [] with bits showing sensor connected in port i
 * 0 -- noting connected
 * 1 -- IR sensor
 * 2 -- dms sensor
 * 3 -- Touch sensor
 * 4 -- Gyro sensor
 * 5 -- zigbee
 *
 * example
 * config=[1,1,2,0,0,0]
 *
 */

bool init_sensors (config){
   //inicialize all the ports
	int i
	i=1;
	for(i=1;i<7;i++){
		switch(config(i)){
		    case0:   // Do nothing
		    	break;
			case1:   // initialize IR
				break;
			case2:   // initialize dms
				break;
			case3:   // initialize touch
				break;
			case4:   // initialize gyro
				break;
			case5:   // initialize zigbee
				break:
		}
	}
}

/*
 * The "sensor" is the one to start sensing at the desired frequency "freq",
 * with an independent time interrupt for each sensor
 */
bool start_sensing (config, sensor, freq){

	switch(sensor){
	case1:
	}
}

/*
 * The "sensor" is stoped
 */
bool stop_sensing (config, sensor){

}
