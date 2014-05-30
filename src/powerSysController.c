/*
* powerSysController.c
*/
#include "../includes/powerSysController.h"

int main(void) {
	CLOCK_CFG;
	STROBE_ENABLE;

	dc_motor_init(DC_MTRA);
	unsigned long i = 0;
	unsigned long ulLoop = 0;
	while(1){
		strobe_pattern(0);
		//STROBE(LED_CYAN);
		for(ulLoop = 0; ulLoop < 500000; ulLoop++);
	}
		//return(0);
}
