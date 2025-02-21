/*
 * pwm.c
 *
 *  Created on: Feb 22, 2025
 *      Author: Admin
 */

#include "pwm.h"

static void pwm_start(TIM_TypeDef*tim, uint32_t Channel){

	LL_TIM_EnableCounter(tim);
	LL_TIM_CC_EnableChannel(tim, Channel);
	LL_TIM_EnableAllOutputs(tim);
}

static void pwm_set_duty_for_adc_trig(uint32_t duty){

	PWM_TIMER->CCR4 = duty;
	pwm_start(PWM_TIMER,ADC_TRIG_CHANNEL);
}

void pwm_init_ex(void){

	pwm_set_frq(1000);
	PWM_SET_DUTY(0);
	PWM_DISABLE_OUTPUT;
	LL_TIM_EnableCounter(PWM_TIMER);
}
void pwm_set_frq(uint32_t frq){

	uint32_t result = 0;

	result = (PWM_FRQ_HZ/frq/2) - 1;
	PWM_TIMER->ARR = result;
}

