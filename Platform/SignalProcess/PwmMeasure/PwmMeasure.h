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
typedef enum {
    Pwm_Continuous_Capture = 0,
    Pwm_Single_Capture ,
}Pwm_Capture_Mode;

class PwmMeasure: public SignalPeripheral{
public:
    PwmMeasure(TIM_HandleTypeDef* htim, uint8_t channel) :
            SignalPeripheral(htim) , _channel(channel){ }
    ~PwmMeasure() = default;
    PwmMeasure& init(uint32_t f_out, uint64_t f_in) override;

    void start(Pwm_Capture_Mode mode);
    void stop() override;

private:
    uint32_t high;
    uint32_t cycle;
    float32_t duty;
    float32_t freq;
    void start() override { };
    void calc_tim_arr_psc() override;
    uint8_t _channel = TIM_CHANNEL_1;
    void debug();
};



#endif
#endif //HELLOWORLD_PWMMEASURE_H
