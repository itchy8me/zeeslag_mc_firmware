#include "inc/lm4f120h5qr.h"
//#include "inc/hw_gpio.h"

#define CLOCK_CFG (SYSCTL_RCC_R = 0x02400540)	// Set clock divider

#define BITF0 0x00000001
#define BITF1 0x00000002
#define BITF2 0x00000004
#define BITF3 0x00000008

#define LED_R BITF1
#define LED_B BITF2
#define LED_G BITF3
#define LED_YELLOW (LED_R | LED_B & ~LED_R)
#define LED_WHITE (LED_R | LED_B | LED_G)

#define STROBE_ENABLE ((SYSCTL_RCGCGPIO_R = SYSCTL_RCGCGPIO_R5) & (GPIO_PORTF_DIR_R = LED_WHITE) & (GPIO_PORTF_DR4R_R = LED_WHITE) & (GPIO_PORTF_DEN_R = LED_WHITE) & (GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY) & (GPIO_PORTF_CR_R = LED_WHITE))	//Enable port F1-F3 for strobe status
#define STROBE(x) ((GPIO_PORTF_DATA_R ^= x))



#define MOTORA 0x00000001
#define MOTORB 0x00000002
#define MOTORC 0x00000004
#define MOTORD 0x00000008
#define STEPPING_MOTOR_EN(x)