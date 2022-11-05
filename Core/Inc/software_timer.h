/*
 * SOFTWARE_TIMER.h
 *
 *  Created on: Sep 24, 2022
 *      Author: hatrungquyen
 */

#ifndef __SOFTWARE_TIMER_
#define __SOFTWARE_TIMER_

/*Timer 1*/
extern int timer1_flag ;
void setTimer1(int duration);
void clearTimer1();

/*Timer 2*/
extern int timer2_flag ;
void setTimer2(int duration);
void clearTimer2();
/*Timer 3*/
extern int timer3_flag ;
void setTimer3(int duration);
void clearTimer3();
/*Timer 4*/
extern int timer4_flag ;
void setTimer4(int duration);
void clearTimer4();
/*Timer 5*/
extern int timer5_flag ;
void setTimer5(int duration);
void clearTimer5();
/*Timer 6*/
extern int timer6_flag ;
void setTimer6(int duration);
void clearTimer6();
//Count down for all timers
void TimeRun();



#endif /* __SOFTWARE_TIMER_ */
