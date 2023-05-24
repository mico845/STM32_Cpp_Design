//
// Created by Whisky on 2023/5/23.
//

#ifndef HELLOWORLD_ADVANCEDMEASURE_H
#define HELLOWORLD_ADVANCEDMEASURE_H

#include "BasicMeasure.h"
#include "SignalSystem.h"

typedef enum
{
    FIR = 0,
    IIR,
}Filter_Type;

class AdvancedMeasure : public BasicMeasure
{
public:
    AdvancedMeasure& init(My_Adc& Adc) override;
    AdvancedMeasure& apply_windows() override;

    AdvancedMeasure& fft();
    AdvancedMeasure& filter(Filter_Type type);

    float32_t get_freq();

    float32_t get_THD(u8 range);
    float32_t get_THD();

    Waveform_Type fft_recognize_wave(u8 range);
    Waveform_Type fft_recognize_wave();
private:
};


#endif //HELLOWORLD_ADVANCEDMEASURE_H
