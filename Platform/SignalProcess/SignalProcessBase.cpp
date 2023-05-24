//
// Created by Whisky on 2023/5/23.
//

#include "SignalProcessBase.h"
#include "retarget.h"

SignalProcessBase& SignalProcessBase::init(My_Adc& Adc) {
    for (int i = 0; i < SIGNAL_BUFF_SIZE; ++i) {
        signal[i] = Adc.adc_buf[i];
    }
    samplerate = (float32_t)(Adc._f_in)/(Adc._htim->Instance->PSC + 1)/(Adc._htim->Instance->ARR + 1);
    return *this;
}

void SignalProcessBase::debug()
{
    for(u32 i = 0; i < SIGNAL_BUFF_SIZE; i++)
    {
        printf("%lu,%f\n", i, signal[i]);
    }
}

void SignalProcessBase::read() {
    debug();
}

u32 convert_to_analog_mv(float32_t num) {
    u32 volt = 3300 * num;
    volt = volt >> 12;
    return volt;
}