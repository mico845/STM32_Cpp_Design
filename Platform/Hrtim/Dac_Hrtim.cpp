//
// Created by Whisky on 2023/6/2.
//

#include "Dac_Hrtim.h"
#include "retarget.h"


void Dac_Hrtim::calc_tim_arr_psc() {
    if(_f_out == 0) {
        printf("Output frequency cannot be zero.\n");
        return;
    }
    // 进行浮点数除法
    float arr_float = _f_in / _f_out;
    while (arr_float > UINT16_MAX/2) {
        arr_float /= 2;
        sample_size *= 2;
        if (sample_size >= DAC_BUFF_SIZE_MAX)
            sample_size = DAC_BUFF_SIZE_MAX;
    }
    uint16_t arr = (uint16_t)round(arr_float);
    __HAL_HRTIM_SETPERIOD(_hrtim, _timer, arr);
}

Dac_Hrtim &Dac_Hrtim::init(uint32_t f_out, uint64_t f_in, WaveformProperties &wave) {
    _f_out = f_out;
    _f_in = round((float)f_in/sample_size);

    calc_tim_arr_psc();

    if (_channel == Dac_Channel_1)
        select_wave(wave);
    else if (_channel == Dac_Channel_2)
        select_wave(wave);
    return *this;
}

void Dac_Hrtim::start() {
    stop();

    if (_channel == Dac_Channel_1)
    {
        HAL_DAC_Start_DMA(_hdac, DAC_CHANNEL_1, (uint32_t *)buf[Dac_Channel_1], sample_size, DAC_ALIGN_12B_R);
        HAL_OPAMP_Start(&hopamp1);
    }

    else if (_channel == Dac_Channel_2)
    {
        HAL_DAC_Start_DMA(_hdac, DAC_CHANNEL_2, (uint32_t *)buf[Dac_Channel_2], sample_size, DAC_ALIGN_12B_R);
        HAL_OPAMP_Start(&hopamp3);
    }

    if (_timer == Timer_A)
        HAL_HRTIM_WaveformCountStart(_hrtim, HRTIM_TIMERID_TIMER_A);
}


void Dac_Hrtim::stop() {
    if (_timer == Timer_A)
        HAL_HRTIM_WaveformCountStop(_hrtim, HRTIM_TIMERID_TIMER_A);

}

void Dac_Hrtim::select_wave(WaveformProperties &wave) {
    memset(buf[_channel], 0, sample_size);
    if (wave._type == Waveform_Sine)
        dac_creat_sin_buf(buf[_channel], wave._maxval, sample_size, wave._phase);
    else if (wave._type == Waveform_Triangle)
        dac_creat_tri_buf(buf[_channel], wave._maxval, sample_size, wave._phase);
}
