//
// Created by Whisky on 2023/5/23.
//

#include "My_Adc.h"
#include <string.h>
#include "retarget.h"

TIM_HandleTypeDef *__htim;
ADC_HandleTypeDef *__hadc;

bool adc_finished;

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)
{
    HAL_ADC_Stop_DMA(__hadc);
    HAL_TIM_Base_Stop(__htim);
    if (hadc->Instance == __hadc->Instance)
    {
        adc_finished = true;
    }
}

My_Adc& My_Adc::init(uint32_t f_out, uint64_t f_in)
{
    SignalPeripheral::init(f_out, f_in);
    __htim = _htim;
    __hadc = _hadc;
    adc_finished = false;
    return *this;
}

void My_Adc::start() {
    calc_tim_arr_psc();
    HAL_ADC_Start_DMA(_hadc, (uint32_t *)adc_buf, ADC_BUFF_SIZE);
    HAL_TIM_Base_Start(_htim);
}

void My_Adc::stop() {
    HAL_TIM_Base_Stop(_htim);
    HAL_ADC_Stop_DMA(_hadc);
    memset(adc_buf, 0, ADC_BUFF_SIZE);
}

void My_Adc::read() {
    for (int i = 0; i < ADC_BUFF_SIZE; ++i) {
        printf("%i,%lu\n", i, adc_buf[i]);
    }
}
