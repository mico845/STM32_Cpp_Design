//
// Created by Whisky on 2023/5/23.
//

#include "My_Pwm.h"

void My_Pwm::start() {
    calc_tim_arr_psc();
    set_duty(_duty);
    HAL_TIM_PWM_Start(_htim, _channel);
}

void My_Pwm::stop() {
    HAL_TIM_PWM_Stop(_htim, _channel);
}

void My_Pwm::set_duty(float duty) {
    _duty = duty;
    _htim->Instance->CCR1 = (_htim->Instance->ARR)*(_duty);
}


