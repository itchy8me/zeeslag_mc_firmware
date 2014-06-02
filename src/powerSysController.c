/*
* powerSysController.c
*/
#include "../includes/powerSysController.h"

int main(void) {
	
	unsigned long i = 0;
	unsigned long ulLoop = 0;
	CLOCK_CFG;
	STROBE_ENABLE;

	dc_motor_init();
	dc_motor_ctrl(0,0x00800000,0);
	while(1){
		strobe_pattern(0);
		//STROBE(LED_CYAN);
		for(ulLoop = 0; ulLoop < 500000; ulLoop++);
	}
		//return(0);
}
