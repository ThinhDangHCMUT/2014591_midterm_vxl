/*
 * INC_BUTTON.h
 *
 *  Created on: Sep 24, 2022
 *      Author: thinhdang
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NO_OF_BUTTONS		3

extern int flagForButtonPressed[NO_OF_BUTTONS];
extern int flagForButtonPressed1s[NO_OF_BUTTONS];


void getKeyInput();
unsigned char is_button_pressed(unsigned char button_number);
unsigned char is_button_pressed_1s(unsigned char button_number);

#endif /* INC_BUTTON_H_ */

