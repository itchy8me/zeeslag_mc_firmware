/*
 *	dc_motor.c 
 */

#include "../includes/dc_motor.h"

typedef struct dc_motor{
  struct motor_status{
    float voltage;
    float current;
  }motor_status;

  struct motor_constants{
    float max_voltage;
    float max_current;
  }motor_constants;
}dc_motor;

void dc_motor_init(){
  DC_MOTORA_THROTTLE_INIT;
  //DC_MOTORA_CLKWISE_INIT;
  //DC_MOTORA_ACLKWISE_INIT;
  
  //DC_MOTORB_THROTTLE_INIT;
  //DC_MOTORB_SIG_CLKWISE_INIT;
  //DC_MOTORB_SIGACLKWISE_INIT;
  
  
}

/*
 * 	Param:
 * 	direction : 	
 * 		off 		- 	0x1
 * 		clockwise 	-	0x2
 *		anticlockwise	-	0x3
 *	throttle :
 * 		[0 - 100] %
 * 
 */

void dc_motor_ctrl(int direction, int throttle, int enable){
	int throttleA = throttle;
	int throttleB = throttle;
	DC_MOTORA_THROTTLE((throttleA),(throttleB));
;}