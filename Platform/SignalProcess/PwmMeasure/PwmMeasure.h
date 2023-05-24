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
class PwmMeasure: public SignalPeripheral{
public:
    PwmMeasure(TIM_HandleTypeDef* htim, uint8_t channel) :
            SignalPeripheral(htim) , _channel(channel){ }
    ~PwmMeasure() = default;
    PwmMeasure& init(uint32_t f_out, uint64_t f_in) override;
    void calc_tim_arr_psc() override;

    void start() override;
    void stop() override;

private:
    uint8_t _channel = TIM_CHANNEL_1;
    void debug(uint32_t high, uint32_t cycle,  float32_t duty_ratio, float32_t freq);
};

#endif
#endif //HELLOWORLD_PWMMEASURE_H
