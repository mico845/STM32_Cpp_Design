//
// Created by Whisky on 2023/5/23.
//

#ifndef HELLOWORLD_ADVANCEDMEASURE_H
#define HELLOWORLD_ADVANCEDMEASURE_H

#include "BasicMeasure.h"
#include "SignalSystem.h"

class AdvancedMeasure : public BasicMeasure
{
public:
    AdvancedMeasure& init(My_Adc& Adc) override;
    AdvancedMeasure& apply_windows() override;

    AdvancedMeasure& fft() override;
    AdvancedMeasure& filter(Filter_Type type) override;

    float32_t get_freq();

    float32_t get_THD(u8 range);
    float32_t get_THD();

    Waveform_Type fft_recognize_wave(u8 range);
    Waveform_Type fft_recognize_wave();

    float32_t read_freq();
private:
    float32_t _freq = 0;
};


#endif //HELLOWORLD_ADVANCEDMEASURE_H
