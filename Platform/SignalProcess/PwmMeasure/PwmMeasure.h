//
// Created by Whisky on 2023/5/23.
//

#ifndef HELLOWORLD_PWMMEASURE_H
#define HELLOWORLD_PWMMEASURE_H
#ifdef __cplusplus
extern "C" {
#include "delay.h"
#endif
/*---------------------------- C Scope ---------------------------*/
#include "SignalPeripheral.h"
#include "arm_math.h"
#ifdef __cplusplus
}
/*---------------------------- C++ Scope ---------------------------*/

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim);
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

class PwmMeasure: public SignalPeripheral{
public:
    PwmMeasure(TIM_HandleTypeDef* htim, uint8_t channel) :
            SignalPeripheral(htim) , _channel(channel){ }
    ~PwmMeasure() = default;
    PwmMeasure& init(uint32_t f_out, uint64_t f_in) override;

    void start() override;
    void stop() override;
    bool is_finished();
    uint32_t get_time_high();
    uint32_t get_cycle_high();
    float32_t get_duty();
    float32_t get_freq();
private:
    bool pwm_is_finished = false;
    uint32_t high;
    uint32_t cycle;
    float32_t duty;
    float32_t freq;
    void calc_tim_arr_psc() override;
    uint8_t _channel = TIM_CHANNEL_1;
    void debug();

public:
    friend void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim);
    friend void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
};



#endif
#endif //HELLOWORLD_PWMMEASURE_H
