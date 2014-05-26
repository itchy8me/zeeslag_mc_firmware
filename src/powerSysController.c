/*
 * powerSysController.c
 */
#include "../includes/system_init.h"

int main(void) {
	CLOCK = 0x02400540;

	ENABLE_STROBE;
	ENABLE_STEPPINGMOTOR();
	//LED1_OUT |= 0x0A; //0x0E;
	LED1_DEN |= 0x0A; //0x0E;
	//LED1OUTT = 0x00000002;
	//LED1UNLOCK = 0x4C4F434B;
	//LED1COMMIT = 0x00000002;

	unsigned long i = 0;
	unsigned long ulLoop = 0;
	while(1){
		LED1_ON = i++;
		for(ulLoop = 0; ulLoop < 500000; ulLoop++);
	}
		//return(0);
}
