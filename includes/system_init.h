/*
 *	system_init.h 
 */

//#include "inc/hw_gpio.h"
#include <inc/lm4f120h5qr.h>
#include <inc/hw_types.h>
#include <inc/hw_ints.h>
#include <driverlib/interrupt.h>

#define CLOCK_CFG (SYSCTL_RCC_R = 0x02400540)	// Set clock divider

#define BITF0 0x00000001
#define BITF1 0x00000002
#define BITF2 0x00000004
#define BITF3 0x00000008

#define LED_R BITF1
#define LED_B BITF2
#define LED_G BITF3
#define LED_PURPLE (LED_R | LED_B & ~LED_G)
#define LED_CYAN (LED_B | LED_G & ~LED_R)
#define LED_YELLOW (LED_R | LED_G & ~LED_B)
#define LED_WHITE (LED_R | LED_B | LED_G)
#define LED_BLACK ~(LED_WHITE)

void system_init(void);