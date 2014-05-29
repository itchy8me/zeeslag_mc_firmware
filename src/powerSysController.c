/*
* powerSysController.c
*/
#include "../includes/system_init.h"
static volatile int strobe_sequence_A[] = {LED_R};
static volatile int * strobe_sequence = strobe_sequence_A;
static volatile int strobe_active = 0;

void strobe_pattern(int pattern_num){
	switch (pattern_num){
		case 0:
			if(strobe_active == (sizeof(strobe_sequence))){strobe_active = 0;}
			STROBE(strobe_sequence[strobe_active]);
			strobe_active++;
			break;
	}
}

int main(void) {
	CLOCK_CFG;
	STROBE_ENABLE;

	unsigned long i = 0;
	unsigned long ulLoop = 0;
	while(1){
		strobe_pattern(0);
		//STROBE(LED_CYAN);
		for(ulLoop = 0; ulLoop < 500000; ulLoop++);
	}
		//return(0);
}
