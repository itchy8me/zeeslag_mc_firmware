/*
*	strobe_status.h
*/

#include "../includes/strobe_status.h"

static volatile int strobe_sequence_IDLE[14] = {LED_YELLOW, LED_BLACK, LED_BLACK, LED_YELLOW, LED_BLACK, LED_BLACK, LED_YELLOW, LED_BLACK, LED_BLACK, LED_YELLOW, LED_BLACK, LED_BLACK, LED_YELLOW, LED_BLACK}; //{LED_R, LED_BLACK, LED_B};
static volatile int strobe_sequence_SUPERSYS[14] = {LED_R, LED_BLACK, LED_G, LED_BLACK, LED_B, LED_BLACK, LED_WHITE, LED_BLACK, LED_YELLOW, LED_BLACK, LED_PURPLE, LED_BLACK, LED_CYAN, LED_BLACK}; //{LED_R, LED_BLACK, LED_B};

//static * strobe_sequence = strobe_sequence_A;
static volatile int LED = 0;

void strobe_pattern(int pattern_num){
	switch (pattern_num){
		case 0:
			if(LED == STROBE_SEQ_LEN){LED = 0;}
			STROBE(strobe_sequence_IDLE[LED]);
			LED++;
			break;
		case 1:
			if(LED == STROBE_SEQ_LEN){LED = 0;}
			STROBE(strobe_sequence_SUPERSYS[LED]);
			LED++;
			break;
	}
}