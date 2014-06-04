/*
* powerSysController.c
*/
#include "../includes/powerSysController.h"


/*
 * 	Function:
 * 	Description :
 * 	Param:
 * 
 */

int main(void) {
	
	unsigned long i = 0;
	unsigned long ulLoop = 0;
	float throttlew = 0.33;
	system_init();
	CLOCK_CFG;
	STROBE_ENABLE;

	dc_motor_init();
	dc_motor_ctrl(0,throttlew,0);
	stp_motor_init();
	while(1){
		//STROBE(LED_CYAN);
		for(ulLoop = 0; ulLoop < 500000; ulLoop++);
	}
		//return(0);
}
