/*
 *	strobe_status.h 
 */

#include "../includes/system_init.h"

#define STROBE_SEQ_LEN 14

#define STROBE_ENABLE ((SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R5) | (GPIO_PORTF_DIR_R |= LED_WHITE) | (GPIO_PORTF_DR2R_R |= LED_WHITE) | (GPIO_PORTF_DEN_R |= LED_WHITE) | (GPIO_PORTF_LOCK_R |= GPIO_LOCK_KEY) | (GPIO_PORTF_CR_R |= LED_WHITE))	//Enable port F1-F3 for strobe status
#define STROBE(x) ((GPIO_PORTF_DATA_R = x))

void strobe_pattern(int pattern_num);