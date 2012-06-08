#ifndef ROBOT_H_
#define ROBOT_H_


//#define CONFIG[6] {1,1,0,0,0,0}

/* example  ----> config=[1,1,2,0,0,0]
 *
 * config is an array [] with bits showing sensor type connected in port i
 * types:
 * 0 -- noting connected
 * 1 -- IR sensor
 * 2 -- dms sensor
 * 3 -- Touch sensor
 * 4 -- Gyro sensor
 * 5 -- zigbee
 */


// Methods
void robot_init(void);
void robot_actuate(void);
void robot_destroy(void);


#endif /* ROBOT_H_ */
