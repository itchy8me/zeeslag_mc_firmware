/*
 *	stepping_motor.h 
 */

#include "../includes/system_init.h"

#define STP_MTRA_PHASE1_PORT 0x00000008
#define STP_MTRA_PHASE2_PORT 0x00000004
#define STP_MTRC 0x00000004
#define STP_MTRD 0x00000008

#define STEPPING_MOTOR_EN(x)

#define STP_MOTORA_PHASE1 ((SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R1) \
			| (SYSCTL_RCGCTIMER_R |= SYSCTL_RCGCTIMER_R3) \
			| (GPIO_PORTB_DEN_R |= STP_MTRA_PHASE1_PORT) \
			| (GPIO_PORTB_AFSEL_R |= STP_MTRA_PHASE1_PORT) \
			| (GPIO_PORTB_PCTL_R |= GPIO_PCTL_PB3_T3CCP1) \
			| (GPIO_PORTB_LOCK_R |= GPIO_LOCK_KEY) \
			| (GPIO_PORTB_CR_R |= STP_MTRA_PHASE1_PORT) \
			| (TIMER3_CTL_R &= ~TIMER_CTL_TBEN) \
			| (TIMER3_CTL_R |= (TIMER_CTL_TBEVENT_POS))\
			| (TIMER3_CFG_R |= TIMER_CFG_16_BIT) \
			| (TIMER3_TBMR_R |= (TIMER_TBMR_TBAMS | TIMER_TBMR_TBMR_PERIOD | TIMER_TBMR_TBPWMIE)) \
			| (TIMER3_IMR_R |= TIMER_IMR_TBMIM) \
			)
			// enable pwm interrupt for premature/virtual counting of pulses
			
#define STP_MOTORA_PHASE1_EN(freq_reg, delta_reg) ((TIMER3_CTL_R &= ~TIMER_CTL_TBEN) \
			| (TIMER3_TBILR_R = 0x0000FFFF) \
			| ((TIMER3_TBMATCHR_R = 0x00008000)) \
			| (TIMER3_CTL_R |= TIMER_CTL_TBEN) \
			)

#define STP_MOTORA_PHASE2 ((SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R1) \
			| (SYSCTL_RCGCTIMER_R |= SYSCTL_RCGCTIMER_R3) \
			| (GPIO_PORTB_DEN_R |= STP_MTRA_PHASE2_PORT) \
			| (GPIO_PORTB_AFSEL_R |= STP_MTRA_PHASE2_PORT) \
			| (GPIO_PORTB_PCTL_R |= GPIO_PCTL_PB2_T3CCP0) \
			| (GPIO_PORTB_LOCK_R |= GPIO_LOCK_KEY) \
			| (GPIO_PORTB_CR_R |= STP_MTRA_PHASE2_PORT) \
			| (TIMER3_CTL_R &= ~TIMER_CTL_TAEN) \
			| (TIMER3_CTL_R |= (TIMER_CTL_TAPWML)) \
			| (TIMER3_CFG_R |= TIMER_CFG_16_BIT) \
			| (TIMER3_TAMR_R |= (TIMER_TAMR_TAAMS | TIMER_TAMR_TAMR_PERIOD)) \
			)
			// enable pwm interrupt for premature/virtual counting of pulses
			
#define STP_MOTORA_PHASE2_EN(freq_reg, delta_reg) ((TIMER3_CTL_R &= ~TIMER_CTL_TAEN) \
			| (TIMER3_TAILR_R = 0x0000FFFF) \
			| ((TIMER3_TAMATCHR_R = 0x00008000)) \
			| (TIMER3_CTL_R |= TIMER_CTL_TAEN) \
			)
	

void stp_motor_init(void);
void stp_motor_ctrl(int direction, float deflection_percent);
int calc_deflection_steps(float deflection_percent, struct step_motor motor);