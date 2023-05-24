//
// Created by Whisky on 2023/5/23.
//

#ifndef HELLOWORLD_MY_PWM_H
#define HELLOWORLD_MY_PWM_H
#include "SignalPeripheral.h"

class My_Pwm: public SignalPeripheral{
public:
    My_Pwm(TIM_HandleTypeDef* htim, uint8_t channel) :
                                        SignalPeripheral(htim) , _channel(channel){ }
    ~My_Pwm() = default;

    void start() override;
    void stop() override;
    void set_duty(float duty);

private:
    float _duty = 0.5;
    uint8_t _channel = TIM_CHANNEL_1;
};
#endif //HELLOWORLD_MY_PWM_H
