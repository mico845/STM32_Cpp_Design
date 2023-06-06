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
    AdvancedMeasure& release_windows() override;

    AdvancedMeasure& fft() override;
    AdvancedMeasure& filter(Filter_Type type) override;

    AdvancedMeasure& convert_to_mv() override;
    AdvancedMeasure& normalize(uint32_t max_value = 4096) override;
    AdvancedMeasure& deal_DC() override;

    float32_t get_freq();

    float32_t get_THD(u8 range);
    float32_t get_THD();

    Waveform_Type fft_recognize_wave(u8 range);
    Waveform_Type fft_recognize_wave();

    float32_t read_freq();
    uint32_t read_max_index();
    uint32_t read_second_index();

    float32_t get_amplitude();
    float32_t get_samplerate() override;
    uint32_t get_second_freq(uint32_t interval);

    AdvancedMeasure& convert_amplitude();

    float32_t find(uint32_t index, uint8_t range = 0);

private:
    float32_t _freq = 0;
    uint32_t _max_index = 0;
    uint32_t _second_index = 0;
    float32_t _samplerate;
};


#endif //HELLOWORLD_ADVANCEDMEASURE_H
