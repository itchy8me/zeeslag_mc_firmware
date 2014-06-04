/*
 *	dc_motor.h 
 */
#include "../includes/system_init.h"

#define DC_MTRA_THROTTLE_PORT 0x00000040
#define DC_MTRB_THROTTLE_PORT 0x00000020
#define DC_MTRC_THROTTLE_PORT 0x00000040
#define DC_MTRD_THROTTLE_PORT 0x00000080

#define DC_MOTORA_CLKWISE_PORT 0x00000002	// mask PINn with P ORTx for more varability
#define DC_MOTORA_ACLKWISE_PORT 0x00000004

#define DC_MOTOR_FREQ 0x0008000
#define DC_MOTORA_THROTTLE ((SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R1) \
			| (SYSCTL_RCGCTIMER_R |= SYSCTL_RCGCTIMER_R0) \
			| (GPIO_PORTB_DEN_R |= DC_MTRA_THROTTLE_PORT) \
			| (GPIO_PORTB_AFSEL_R |= DC_MTRA_THROTTLE_PORT) \
			| (GPIO_PORTB_PCTL_R |= GPIO_PCTL_PB6_T0CCP0) \
			| (GPIO_PORTB_LOCK_R |= GPIO_LOCK_KEY) \
			| (GPIO_PORTB_CR_R |= DC_MTRA_THROTTLE_PORT) \
			| (TIMER0_CTL_R &= ~TIMER_CTL_TAEN) \
			| (TIMER0_CFG_R |= TIMER_CFG_16_BIT) \
			| (TIMER0_TAMR_R |= (TIMER_TAMR_TAAMS | TIMER_TAMR_TAMR_PERIOD)) \
			)
			// 
			
#define DC_MOTORA_THROTTLE_SET(delta_regA, delta_regB) ((TIMER0_CTL_R &= ~TIMER_CTL_TAEN) \
			| (TIMER0_TAILR_R = (DC_MOTOR_FREQ & 0x0000FFFF)) \
			| ((TIMER0_TAPMR_R = (delta_regA)) | ((TIMER0_TAMATCHR_R = (delta_regB)))) \
			| (TIMER0_CTL_R |= TIMER_CTL_TAEN) \
			)
			
#define DC_MOTORA_CLKWISE ((SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R3) \
			| (GPIO_PORTD_DEN_R |= DC_MOTORA_CLKWISE_PORT) \
			| (GPIO_PORTD_DIR_R |= DC_MOTORA_CLKWISE_PORT) \
			| (GPIO_PORTB_LOCK_R |= GPIO_LOCK_KEY) \
			| (GPIO_PORTD_CR_R |= DC_MOTORA_CLKWISE_PORT) \
			)
			
#define DC_MOTORA_ACLKWISE ((SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R3) \
			| (GPIO_PORTD_DEN_R |= DC_MOTORA_ACLKWISE_PORT) \
			| (GPIO_PORTD_DIR_R |= DC_MOTORA_ACLKWISE_PORT) \
			| (GPIO_PORTB_LOCK_R |= GPIO_LOCK_KEY) \
			| (GPIO_PORTD_CR_R |= DC_MOTORA_ACLKWISE_PORT) \
			)

struct motor_status{
  float voltage;
  float current;
};

struct motor_constants{
  float max_voltage;
  float max_current;
};

struct dc_motor{
};

void dc_motor_init(void);
void dc_motor_ctrl(unsigned short int direction, float throttle, unsigned short int enable);
unsigned int calc_dc_throttle_reg(float throttle_percent);