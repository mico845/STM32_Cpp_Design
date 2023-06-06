//
// Created by Whisky on 2023/6/2.
//

#ifndef HELLOWORLD_DAC_HRTIM_H
#define HELLOWORLD_DAC_HRTIM_H

#ifdef __cplusplus
extern "C" {
#endif
/*---------------------------- C Scope ---------------------------*/
#include "hrtim.h"
#include "opamp.h"
#ifdef __cplusplus
}

/*---------------------------- C++ Scope ---------------------------*/
#include "Dac/My_Dac.h"
typedef enum
{
    Timer_A = 0,
    Timer_B,
    Timer_C,
    Timer_D,
    Timer_E,
    Timer_F,
}Hrtim_Timer;

class Dac_Hrtim
{
public:
    Dac_Hrtim(DAC_HandleTypeDef *hdac, Dac_Channel channel, HRTIM_HandleTypeDef *hrtim, Hrtim_Timer timer)
            :_hrtim(hrtim), _channel(channel), _hdac(hdac), _timer(timer) { }
    void calc_tim_arr_psc();
    Dac_Hrtim& init(uint32_t f_out, uint64_t f_in, WaveformProperties &wave);
    void start();
    void stop();
private:
    uint32_t _f_out;
    uint64_t _f_in;
    DAC_HandleTypeDef *_hdac;
    Dac_Channel _channel = Dac_Channel_1;
    HRTIM_HandleTypeDef* _hrtim;
    Hrtim_Timer _timer;
    uint16_t buf[2][DAC_BUFF_SIZE_MAX] = {0};
    uint32_t sample_size = DAC_BUFF_SIZE;
    void select_wave(WaveformProperties &wave);
};

#endif

#endif //HELLOWORLD_DAC_HRTIM_H
