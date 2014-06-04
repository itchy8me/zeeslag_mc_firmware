/*
 *	dc_motor.c 
 */

#include "../includes/dc_motor.h"

/*
 * 	Function:
 * 	Description :
 * 	Param:
 * 
 */

void dc_motor_init(){
  DC_MOTORA_THROTTLE;
  DC_MOTORA_CLKWISE;
  DC_MOTORA_ACLKWISE;
  
  //DC_MOTORB_THROTTLE_INIT;
  //DC_MOTORB_SIG_CLKWISE_INIT;
  //DC_MOTORB_SIGACLKWISE_INIT;  
}

/*
 * 	Function: dc_motor_ctrl :
 * 	Description : Drives the attached dc motor according to the input paameters past to the function
 * 	Param:
 * 	direction : 	
 * 		off 		- 	0x1
 * 		clockwise 	-	0x2
 *		anticlockwise	-	0x3
 *	throttle :
 * 		[0 - 100] %
 * 
 */

void dc_motor_ctrl(unsigned short int direction, float throttle_percent, unsigned short int enable){
  unsigned int throttle_reg;
  unsigned int throttleA;
  unsigned int throttleB;
  
  throttle_reg = calc_dc_throttle_reg(throttle_percent);
  throttleA = (throttle_reg >> 16);
  throttleB = (throttle_reg & 0x0000FFFF);
  DC_MOTORA_THROTTLE_SET((throttleA),(throttleB));
;}

/*
 * 	Function: dc_throttle_reg
 * 	Description : calculates the register value equivalent to a duty cycle for TIMERn for the requested power output value given as a percentage
 * 	Param: throttle_percent, the angular velocity / speed (percentage of full throttle)
 * 	returns : dc_throttle_val, the value for the match registers for a given pwm period
 * 
 */
unsigned int calc_dc_throttle_reg(float throttle_percent){
  unsigned int dc_throttle_val;
  dc_throttle_val = (unsigned short int)((DC_MOTOR_FREQ * throttle_percent));
  return(dc_throttle_val);
}