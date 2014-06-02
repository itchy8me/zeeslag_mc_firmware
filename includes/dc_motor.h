/*
 *	dc_motor.h 
 */
#include "../includes/system_init.h"

#define DC_MTRA_THROTTLE_PORT 0x00000040
#define DC_MTRB_THROTTLE_PORT 0x00000020
#define DC_MTRC_THROTTLE_PORT 0x00000040
#define DC_MTRD_THROTTLE_PORT 0x00000080

#define DC_MOTORA_THROTTLE_INIT (SYSCTL_PRTIMER_R |= SYSCTL_PRTIMER_R0) \
			| ((SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R1) \
			| (SYSCTL_RCGCTIMER_R |= SYSCTL_RCGCTIMER_R0) \
			| (GPIO_PORTB_DEN_R |= DC_MTRA_THROTTLE_PORT) \
			| (GPIO_PORTB_AFSEL_R |= DC_MTRA_THROTTLE_PORT) \
			| (GPIO_PORTB_PCTL_R |= GPIO_PCTL_PB6_T0CCP0) \
			| (GPIO_PORTB_LOCK_R |= GPIO_LOCK_KEY) \
			| (GPIO_PORTB_CR_R |= DC_MTRA_THROTTLE_PORT) \
			| (TIMER0_CFG_R |= TIMER_CFG_16_BIT) \
			| (TIMER0_CTL_R |= TIMER_CTL_TAEVENT_POS & ~TIMER_CTL_TAEN) \
			| (TIMER0_TAMR_R |= (TIMER_TAMR_TAAMS | TIMER_TAMR_TAMR_PERIOD & ~TIMER_TAMR_TACMR)) \
			)
#define DC_MOTORA_THROTTLE(delta_regA, delta_regB) ((TIMER0_CTL_R &= ~TIMER_CTL_TAEN) \
			| (TIMER0_TAPR_R |= 0X000000FF) | (TIMER0_TAILR_R |= 0x0000FFFF) \
			| (TIMER0_TAPMR_R |= (delta_regA >> 16)) | (TIMER0_TAMATCHR_R |= (delta_regB & 0x0000FFFF)) \
			| (TIMER0_CTL_R |= TIMER_CTL_TAEN) \
			)
#define DC_MOTORA_CLKWISE_INIT
#define DC_MOTORA_ACLKWISE_INIT

void dc_motor_init(void);
void motor_ctrl(int direction, int throtlle, int enable);