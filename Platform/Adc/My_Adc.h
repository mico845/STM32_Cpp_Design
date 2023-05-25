//
// Created by Whisky on 2023/5/23.
//

#ifndef HELLOWORLD_MY_ADC_H
#define HELLOWORLD_MY_ADC_H

#include "SignalPeripheral.h"
#include <stdbool.h>
#include "Config.h"


class SignalProcessBase;

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc);

class My_Adc: public SignalPeripheral {
public:
    My_Adc(ADC_HandleTypeDef* hadc, TIM_HandleTypeDef* htim) : SignalPeripheral(htim), _hadc(hadc) { }
    ~My_Adc() = default;

    My_Adc& init(uint32_t f_out, uint64_t f_in) override;
    void start() override;
    void stop() override;

    void read();
    bool is_finished();
private:
    bool adc_finished = false;
    ADC_HandleTypeDef *_hadc;
    u32 adc_buf[ADC_BUFF_SIZE] = {0};
public:
    friend class SignalProcessBase;
    friend void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc);
};


#endif //HELLOWORLD_MY_ADC_H
