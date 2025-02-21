/*
 * main.c
 *
 *  Created on: Feb 21, 2025
 *      Author: Admin
 */

#include "board.h"


int main(void){

	board_hardware_init_ex();

	delay_ms(20);

	PWM_TIMER->CCR1 = 0.2*PWM_TIMER_TOP_COUNTER;
	PWM_ENABLE_CHANNEL;
	PWM_ENABLE_OUTPUT;
	while(1){

	}
}
