/*
 * fsm_manual.c
 *
 *  Created on: Oct 7, 2022
 *      Author: thinhdang
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
			if(timer1_flag == 1){ //AUTO STATE
				setTimer1(20);
				led1Update(counter);
				if(counter == 0){   //state STOP
					clearTimer1();
					led1Update(0);
				}
				counter--;
			}
			//RESET
			//After reset pressed, counter is set to 0 and it still in AUTO state
			if(flagForButtonPressed[0] == 1) {
				counter = 0;
				flagForButtonPressed[0] = 0;
			}
			//CHANGE TO WAITING FOR SET
			//INCREASE
			//After press increase button, it turn into WAITING_FOR_SET state
			if(flagForButtonPressed[1] == 1){
			    clearTimer1();
			    setTimer3(500);    //Set timer3 to wait for 10s if there are no button is pressed
			    flagForButtonPressed[1] = 0;
				led1Update(counter+1);
				wait = counter;
				status = WAITING_FOR_SET;
			}
			//DECREASE
			//After press increase button, it turn into WAITING_FOR_SET state
			if(flagForButtonPressed[2] == 1){
				clearTimer1();
				setTimer3(500);    //Set timer3 to wait for 10s if there are no button is pressed
				flagForButtonPressed[2] = 0;
				led1Update(counter-1);
				wait = counter;
				status = WAITING_FOR_SET;
			}

		break;

		case WAITING_FOR_SET:
			//Waiting for 10s and change to AUTO state
			if(timer3_flag == 1){  //timer3 is over and it turn into AUTO state
				counter = wait;
				status = AUTO;
				setTimer1(1);  //setTimer1 to run count down in AUTO state
			}
			//RELEASE BUTTON
			//INCREASE
			if(flagForButtonPressed[1] == 1) {
				wait++;
				flagForButtonPressed[1] = 0;
				setTimer3(500);  //Set timer3 to wait for 10s if there are no button is pressed
			}
			//DECREASE
			if(flagForButtonPressed[2] == 1) {
				wait--;
				flagForButtonPressed[2] = 0;
				setTimer3(500);   //Set timer3 to wait for 10s if there are no button is pressed
			}
			//HOLD BUTTON
			//INCREASE
			if(flagForButtonPressed3s[1] == 1) { //hold increase button in 3s and counter is increased
				wait++;
				flagForButtonPressed3s[1] = 0;
				setTimer3(500);   //Set timer3 to wait for 10s if there are no button is pressed
			}
			//DECREASE
			if(flagForButtonPressed3s[2] == 1) { //hold decrease button in 3s and counter is decreased
				wait--;
				flagForButtonPressed3s[2] = 0;
				setTimer3(500);   //Set timer3 to wait for 10s if there are no button is pressed
			}
			//RESET
			if(flagForButtonPressed[0] == 1){  //After reset pressed, counter is set to 0 and it still in AUTO state
				flagForButtonPressed[0] = 0;
				counter = wait;
				status = AUTO;
				setTimer1(1);
			}
			if(wait > 9) wait = 0;   //loop in 0 - 9
			if(wait < 0) wait = 9;   //loop in 9 - 0
			//DISPLAY
			led1Update(wait);
			break;


		default:
			break;
	}
}
