/*
 * led_control.c
 *
 *  Created on: Nov 3, 2022
 *      Author: Thinh Dang
 */


#include "led_control.h"

void setD1(){
	HAL_GPIO_TogglePin(GPIOA, D1_Pin);
}

void clearLed(int index){
	led1Update(index);
}

void led1Update(int num){
	switch(num){
		case 0:
			HAL_GPIO_WritePin(GPIOB, LED1_1_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, LED1_2_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, LED1_3_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, LED1_4_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, LED1_5_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, LED1_6_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, LED1_7_Pin, 1);
		break;
	    case 1:
				HAL_GPIO_WritePin(GPIOB, LED1_1_Pin, 1);
				HAL_GPIO_WritePin(GPIOB, LED1_2_Pin, 0);
				HAL_GPIO_WritePin(GPIOB, LED1_3_Pin, 0);
				HAL_GPIO_WritePin(GPIOB, LED1_4_Pin, 1);
				HAL_GPIO_WritePin(GPIOB, LED1_5_Pin, 1);
				HAL_GPIO_WritePin(GPIOB, LED1_6_Pin, 1);
				HAL_GPIO_WritePin(GPIOB, LED1_7_Pin, 1);
			break;
		case 2:
				HAL_GPIO_WritePin(GPIOB, LED1_1_Pin, 0);
				HAL_GPIO_WritePin(GPIOB, LED1_2_Pin, 0);
				HAL_GPIO_WritePin(GPIOB, LED1_3_Pin, 1);
				HAL_GPIO_WritePin(GPIOB, LED1_4_Pin, 0);
				HAL_GPIO_WritePin(GPIOB, LED1_5_Pin, 0);
				HAL_GPIO_WritePin(GPIOB, LED1_6_Pin, 1);
				HAL_GPIO_WritePin(GPIOB, LED1_7_Pin, 0);
			break;
		case 3:
				HAL_GPIO_WritePin(GPIOB, LED1_1_Pin, 0);
				HAL_GPIO_WritePin(GPIOB, LED1_2_Pin, 0);
				HAL_GPIO_WritePin(GPIOB, LED1_3_Pin, 0);
				HAL_GPIO_WritePin(GPIOB, LED1_4_Pin, 0);
				HAL_GPIO_WritePin(GPIOB, LED1_5_Pin, 1);
				HAL_GPIO_WritePin(GPIOB, LED1_6_Pin, 1);
				HAL_GPIO_WritePin(GPIOB, LED1_7_Pin, 0);
			break;
		case 4:
				HAL_GPIO_WritePin(GPIOB, LED1_1_Pin, 1);
				HAL_GPIO_WritePin(GPIOB, LED1_2_Pin, 0);
				HAL_GPIO_WritePin(GPIOB, LED1_3_Pin, 0);
				HAL_GPIO_WritePin(GPIOB, LED1_4_Pin, 1);
				HAL_GPIO_WritePin(GPIOB, LED1_5_Pin, 1);
				HAL_GPIO_WritePin(GPIOB, LED1_6_Pin, 0);
				HAL_GPIO_WritePin(GPIOB, LED1_7_Pin, 0);
			break;
		case 5:
				HAL_GPIO_WritePin(GPIOB, LED1_1_Pin, 0);
				HAL_GPIO_WritePin(GPIOB, LED1_2_Pin, 1);
				HAL_GPIO_WritePin(GPIOB, LED1_3_Pin, 0);
				HAL_GPIO_WritePin(GPIOB, LED1_4_Pin, 0);
				HAL_GPIO_WritePin(GPIOB, LED1_5_Pin, 1);
				HAL_GPIO_WritePin(GPIOB, LED1_6_Pin, 0);
				HAL_GPIO_WritePin(GPIOB, LED1_7_Pin, 0);
			break;
		case 6:
				HAL_GPIO_WritePin(GPIOB, LED1_1_Pin, 0);
				HAL_GPIO_WritePin(GPIOB, LED1_2_Pin, 1);
				HAL_GPIO_WritePin(GPIOB, LED1_3_Pin, 0);
				HAL_GPIO_WritePin(GPIOB, LED1_4_Pin, 0);
				HAL_GPIO_WritePin(GPIOB, LED1_5_Pin, 0);
				HAL_GPIO_WritePin(GPIOB, LED1_6_Pin, 0);
				HAL_GPIO_WritePin(GPIOB, LED1_7_Pin, 0);
			break;
		case 7:
				HAL_GPIO_WritePin(GPIOB, LED1_1_Pin, 0);
				HAL_GPIO_WritePin(GPIOB, LED1_2_Pin, 0);
				HAL_GPIO_WritePin(GPIOB, LED1_3_Pin, 0);
				HAL_GPIO_WritePin(GPIOB, LED1_4_Pin, 1);
				HAL_GPIO_WritePin(GPIOB, LED1_5_Pin, 1);
				HAL_GPIO_WritePin(GPIOB, LED1_6_Pin, 1);
				HAL_GPIO_WritePin(GPIOB, LED1_7_Pin, 1);
			break;
		case 8:
				HAL_GPIO_WritePin(GPIOB, LED1_1_Pin, 0);
				HAL_GPIO_WritePin(GPIOB, LED1_2_Pin, 0);
				HAL_GPIO_WritePin(GPIOB, LED1_3_Pin, 0);
				HAL_GPIO_WritePin(GPIOB, LED1_4_Pin, 0);
				HAL_GPIO_WritePin(GPIOB, LED1_5_Pin, 0);
				HAL_GPIO_WritePin(GPIOB, LED1_6_Pin, 0);
				HAL_GPIO_WritePin(GPIOB, LED1_7_Pin, 0);
			break;
		case 9:
				HAL_GPIO_WritePin(GPIOB, LED1_1_Pin, 0);
				HAL_GPIO_WritePin(GPIOB, LED1_2_Pin, 0);
				HAL_GPIO_WritePin(GPIOB, LED1_3_Pin, 0);
				HAL_GPIO_WritePin(GPIOB, LED1_4_Pin, 0);
				HAL_GPIO_WritePin(GPIOB, LED1_5_Pin, 1);
				HAL_GPIO_WritePin(GPIOB, LED1_6_Pin, 0);
				HAL_GPIO_WritePin(GPIOB, LED1_7_Pin, 0);
			break;
default:
				HAL_GPIO_WritePin(GPIOB, LED1_1_Pin, 1);
				HAL_GPIO_WritePin(GPIOB, LED1_2_Pin, 1);
				HAL_GPIO_WritePin(GPIOB, LED1_3_Pin, 1);
				HAL_GPIO_WritePin(GPIOB, LED1_4_Pin, 1);
				HAL_GPIO_WritePin(GPIOB, LED1_5_Pin, 1);
				HAL_GPIO_WritePin(GPIOB, LED1_6_Pin, 1);
				HAL_GPIO_WritePin(GPIOB, LED1_7_Pin, 1);
				break;

	}
}
