//
// Created by Whisky on 2023/5/23.
//

#ifndef HELLOWORLD_SIGNALPROCESSBASE_H
#define HELLOWORLD_SIGNALPROCESSBASE_H
#include "EmbeddedSystem.h"
#include "My_Adc.h"
#include "arm_math.h"

class SignalProcessBase : public EmbeddedSystem
{
public:
    SignalProcessBase() = default;
    ~SignalProcessBase() = default;

    virtual SignalProcessBase& init(My_Adc& Adc) ;
    virtual SignalProcessBase& apply_windows();
    void read();
protected:
    float32_t signal[SIGNAL_BUFF_SIZE] = {0};
    float32_t samplerate;
    virtual void debug();
private:

};

u32 convert_to_analog_mv(float32_t num);

#endif //HELLOWORLD_SIGNALPROCESSBASE_H