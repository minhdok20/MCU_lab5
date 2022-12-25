/*
 * software_timer.h
 *
 *  Created on: Nov 18, 2022
 *      Author: HP PV
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "global.h"

extern int timer1_flag; //Setup 1s for blinking RED LED to signal that the system is operating normally, not hanging.
extern int timer2_flag; //Setup 3s for ADC_Value packet sending process

void setTimer1(int duration);
void setTimer2(int duration);

void clearTimer1();
void clearTimer2();

void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
