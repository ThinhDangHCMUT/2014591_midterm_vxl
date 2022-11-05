/*
 * fsm_manual.c
 *
 *  Created on: Oct 7, 2022
 *      Author: phucd
 */

#include <fsm_simple_buttons_run.h>

void fsm_simple_buttons_run(){
	switch(status){
		case INIT:
			if(timer1_flag == 1){
				//Clear All Flag Button
				flagForButtonPressed[0] = 0;
				flagForButtonPressed[1] = 0;
				flagForButtonPressed[2] = 0;
				//Clear 7 Segment
				led1Update(10);
				status = AUTO;
				setTimer1(100);
			}
		break;

		case AUTO:
			// TODO:
			//Auto Count Down
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
			//INCREASE
			if(flagForButtonPressed[1] == 1){
			    clearTimer1();
			    setTimer3(500);
			    flagForButtonPressed[1] = 0;
				led1Update(counter+1);
				wait = counter;
				status = WAITING_FOR_SET;
			}
			//DECREASE
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
			//Waiting for 10s and change to AUTO state
			if(timer3_flag == 1){
				counter = wait;
				status = AUTO;
				setTimer1(1);
			}
			//RELEASE BUTTON
			//INCREASE
			if(flagForButtonPressed[1] == 1) {
				wait++;
				flagForButtonPressed[1] = 0;
				setTimer3(500);
			}
			//DECREASE
			if(flagForButtonPressed[2] == 1) {
				wait--;
				flagForButtonPressed[2] = 0;
				setTimer3(500);
			}
			//HOLD BUTTON
			//INCREASE
			if(flagForButtonPressed3s[1] == 1) {
				wait++;
				flagForButtonPressed3s[1] = 0;
				setTimer3(500);
			}
			//DECREASE
			if(flagForButtonPressed3s[2] == 1) {
				wait--;
				flagForButtonPressed3s[2] = 0;
				setTimer3(500);
			}
			//RESET
			if(flagForButtonPressed[0] == 1){
				flagForButtonPressed[0] = 0;
				counter = wait;
				status = AUTO;
				setTimer1(1);
			}
			if(wait > 9) wait = 0;
			if(wait < 0) wait = 9;
			//DISPLAY
			led1Update(wait);
			break;


		default:
			break;
	}
}
