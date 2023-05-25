//
// Created by Whisky on 2023/5/23.
//

#include "My_Adc.h"
#include <string.h>
#include "retarget.h"
#include "adc.h"

My_Adc* adc_instance1;
My_Adc* adc_instance2;
My_Adc* adc_instance3;

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)
{
    HAL_ADC_Stop_DMA(hadc);
    if (hadc->Instance == ADC1)
    {
        HAL_TIM_Base_Stop(adc_instance1->_htim);
        adc_instance1->adc_finished = true;
    }
    else if (hadc->Instance == ADC2)
    {
        HAL_TIM_Base_Stop(adc_instance2->_htim);
        adc_instance2->adc_finished = true;
    }
    else if (hadc->Instance == ADC3)
    {
        HAL_TIM_Base_Stop(adc_instance3->_htim);
        adc_instance3->adc_finished = true;
    }
}

My_Adc& My_Adc::init(uint32_t f_out, uint64_t f_in)
{
    SignalPeripheral::init(f_out, f_in);
    if (_hadc == &hadc1)
        adc_instance1 = this;
    else if (_hadc == &hadc2)
        adc_instance2 = this;
    else if (_hadc == &hadc3)
        adc_instance3 = this;
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

bool My_Adc::is_finished() {
    if (adc_finished)
    {
        adc_finished = false;
        return true;
    }
    else
        return false;

}
