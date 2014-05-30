/*
 *	stepping_motor.c 
 */

#include "../includes/stepping_motor.h"

typedef struct stp_motor{
  struct motor_status{
    float voltage;
    float current;
    float position_angle;
    float position_steps;
  }motor_status;

  struct motor_constants{
    float max_voltage;
    float deflection_anticlk_max;
    float deflection_clk_max;
    float rotation_steps;
    float step_angle;
    float holding_current;
  }motor_constants;
}stp_motor;

void step_motor_ctl(void);