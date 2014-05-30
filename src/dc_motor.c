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

void dc_motor_init(int port){
  DC_MOTOR_INIT(port);
}
void dc_motor_ctl(int direction, int throtlle, int enable){;}