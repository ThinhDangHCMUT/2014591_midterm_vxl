/*
 * fsm_manual.c
 *
 *  Created on: Oct 7, 2022
 *      Author: phucd
 */

#include "fsm_manual.h"

void fsm_manual_run(){
	switch(status_3){
		case INIT:
				led1Update(10);
				flagForButtonPressed[0] = 0;
				flagForButtonPressed[1] = 0;
			    flagForButtonPressed[2] = 0;
				status_3 = AUTO;
		break;

		case AUTO:  //maual
			// TODO:
			if(timer1_flag == 1){
				setTimer1(100);
				if(index < 0 ) index = 9;
				led1Update(index--);
			}

			if(flagForButtonPressed[0] == 1) {
				index = 0;
				flagForButtonPressed[0] = 0;
			}

			if(flagForButtonPressed[1] == 1){
			    clearTimer1();      //increase
			    flagForButtonPressed[1] = 0;
				led1Update(index+1);
				status_3 = WAITING_FOR_SET;
			}

			if(flagForButtonPressed[2] == 1){
				clearTimer1();      //increase
				flagForButtonPressed[2] = 0;
				led1Update(index-1);
				status_3 = WAITING_FOR_SET;
			}

		break;

		case WAITING_FOR_SET:
			led1Update(index);
			if(flagForButtonPressed[1] == 1) {
				index++;
				flagForButtonPressed[1] = 0;
			}
			if(flagForButtonPressed[2] == 1) {
				index--;
				flagForButtonPressed[2] = 0;
			}

			if(flagForButtonPressed1s[1] == 1) {
				index++;
				flagForButtonPressed1s[1] = 0;
			}

			if(flagForButtonPressed1s[2] == 1) {
				index--;
				flagForButtonPressed1s[2] = 0;
			}

			if(flagForButtonPressed[0] == 1){
				flagForButtonPressed[0] = 0;
				status_3 = AUTO;
				setTimer1(1);
			}
			if(index > 9) index = 0;
			if(index < 0) index = 9;
			led1Update(index);
			break;


		default:
			break;
	}
}
