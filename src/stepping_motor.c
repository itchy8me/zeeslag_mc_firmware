/*
 *	stepping_motor.c 
 */

#include "../includes/stepping_motor.h"
		
struct motor_status{
  float voltage;
  float current;
  float position_angle;
  float position_steps;
};

struct motor_constants{
  float max_voltage;
  float deflection_anticlk_max;
  float deflection_clk_max;
  float rotation_steps;
  float step_angle;
  float holding_current;
};

struct step_motor{
  struct motor_status motor_statusA;
  struct motor_constants motor_constantsA;
};

extern void step_pulse_event(void){
  strobe_pattern(0);
}

void stp_motor_init(){
  struct step_motor step_motorA;
  STP_MOTORA_PHASE1;
  STP_MOTORA_PHASE2;
  STP_MOTORA_PHASE1_EN(0x0000FFFF, 0x00008000);
  STP_MOTORA_PHASE2_EN(0x0000FFFF, 0x00008000);
  IntRegister(INT_PWM0_1, step_pulse_event);
  IntEnable(INT_PWM0_1);
}

void stp_motor_ctrl(int direction, float deflection_percent){
  direction = direction;
}
