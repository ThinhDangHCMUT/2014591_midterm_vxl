/*
 * fsm_manual.c
 *
 *  Created on: Oct 7, 2022
 *      Author: phucd
 */

#include "fsm_manual.h"

void fsm_manual_run(){
	switch(status){
		case INIT:
			if(timer1_flag == 1){
				flagForButtonPressed[0] = 0;
				flagForButtonPressed[1] = 0;
				flagForButtonPressed[2] = 0;
				led1Update(10);
				status = AUTO;
				setTimer1(100);
			}
		break;

		case AUTO:
			// TODO:
			if(timer1_flag == 1){
				setTimer1(20);
				led1Update(counter);
				if(counter == 0){
					clearTimer1();
					led1Update(0);
				}
				counter--;
			}

			//RESET
			if(flagForButtonPressed[0] == 1) {
				counter = 0;
				flagForButtonPressed[0] = 0;
			}
			//CHANGE TO WAITING FOR SET
			//INC
			if(flagForButtonPressed[1] == 1){
			    clearTimer1();
			    setTimer3(500);
			    flagForButtonPressed[1] = 0;
				led1Update(counter+1);
				wait = counter;
				status = WAITING_FOR_SET;
			}
			//DEC
			if(flagForButtonPressed[2] == 1){
				clearTimer1();
				setTimer3(500);
				flagForButtonPressed[2] = 0;
				led1Update(counter-1);
				wait = counter;
				status = WAITING_FOR_SET;
			}

		break;

		case WAITING_FOR_SET:
			if(timer3_flag == 1){
				counter = wait;
				status = AUTO;
				setTimer1(1);
			}
			if(flagForButtonPressed[1] == 1) {
				wait++;
				flagForButtonPressed[1] = 0;
				setTimer3(500);
			}
			if(flagForButtonPressed[2] == 1) {
				wait--;
				flagForButtonPressed[2] = 0;
				setTimer3(500);
			}

			if(flagForButtonPressed1s[1] == 1) {
				wait++;
				flagForButtonPressed1s[1] = 0;
				setTimer3(500);
			}

			if(flagForButtonPressed1s[2] == 1) {
				wait--;
				flagForButtonPressed1s[2] = 0;
				setTimer3(500);
			}

			if(flagForButtonPressed[0] == 1){
				flagForButtonPressed[0] = 0;
				counter = wait;
				status = AUTO;
				setTimer1(1);
			}
			if(wait > 9) wait = 0;
			if(wait < 0) wait = 9;
			led1Update(wait);
			break;


		default:
			break;
	}
}
