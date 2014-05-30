/*
 *	dc_motor.h 
 */
#include "../includes/system_init.h"

#define DC_MTRA 0x00000040
#define DC_MTRB 0x00000020
#define DC_MTRC 0x00000040
#define DC_MTRD 0x00000080

#define DC_MOTOR_INIT(x) ((SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R1) | (SYSCTL_RCGCTIMER_R |= SYSCTL_RCGCTIMER_R0) | (GPIO_PORTB_DEN_R |= x) | (GPIO_PORTB_AFSEL_R |= x) | (GPIO_PORTB_PCTL_R |= GPIO_PCTL_PB6_T0CCP0) | (GPIO_PORTB_LOCK_R |= GPIO_LOCK_KEY) | (GPIO_PORTB_CR_R |= x) | (TIMER0_CFG_R |= TIMER_CFG_16_BIT) | (TIMER0_TAPR_R) | (TIMER0_TAILR_R) | (TIMER0_TAMATCHR_R) | (TIMER0_TAMR_R |= (TIMER_TAMR_TAAMS | TIMER_TAMR_TAMR_PERIOD & ~TIMER_TAMR_TACMR)) | (TIMER0_CTL_R &= ~TIMER_CTL_TAEN))//)

void dc_motor_init(int port);
void motor_ctl(int direction, int throtlle, int enable);