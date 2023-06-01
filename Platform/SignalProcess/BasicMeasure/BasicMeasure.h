//
// Created by Whisky on 2023/5/23.
//

#ifndef HELLOWORLD_BASIC_MEASURE_H
#define HELLOWORLD_BASIC_MEASURE_H
#include "SignalProcessBase.h"

class BasicMeasure : public SignalProcessBase
{
public:
    float32_t get_max() override;
    float32_t get_min() override;
    float32_t get_peak_to_peak();
    float32_t get_rms();
    float32_t get_average(u32 n);
    float32_t get_average();
private:

};

#endif //HELLOWORLD_BASIC_MEASURE_H
