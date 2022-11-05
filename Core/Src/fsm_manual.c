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
				setTimer1(100);
				status_3 = MANUAL;
		break;

		case MANUAL:  //maual
			// TODO:
			if(timer1_flag == 1){
				setTimer1(100);
				if(index < 0 ) index = 9;
				led1Update(index--);
			}

			if(is_button_pressed(0) == 1){ //reset
				index = 0;
			}

			if(is_button_pressed(1) == 1){
				clearTimer1(); //increase
				led1Update(index+1);
				status_3 = WAITING_FOR_SET;
			}

			if(is_button_pressed(2) == 1){
				clearTimer1();  //increase
				led1Update(index-1);
				status_3 = WAITING_FOR_SET;
			}

		break;

		case WAITING_FOR_SET:
			//led1Update(index);
			if(is_button_pressed(1) == 1) index++;
			if(is_button_pressed(2) == 1) index--;

			if(is_button_pressed_1s(1) == 1) index++;

			if(is_button_pressed_1s(2) == 1) index--;

			if(is_button_pressed(0) == 1){
				status_3 = MANUAL;
			}
			if(index > 9) index = 0;
			if(index < 0) index = 9;
			led1Update(index);
			break;


		default:
			break;
	}
}
