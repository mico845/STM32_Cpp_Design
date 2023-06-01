//
// Created by Whisky on 2023/5/23.
//

#include "My_Dac.h"
#include <string.h>

void dac_creat_sin_buf(u16 *buf, u16 maxval, u32 samples, float phase_degrees);
void dac_creat_tri_buf(u16 *buf, u16 maxval, u32 samples, u16 phase_time);

My_Dac& My_Dac::init(uint32_t f_out, uint64_t f_in, WaveformProperties &wave) {
    SignalPeripheral::init(f_out, round((float)f_in/DAC_BUFF_SIZE));
    if (_channel == Dac_Channel_1)
        select_wave(wave);
    else if (_channel == Dac_Channel_2)
        select_wave(wave);
    return *this;
}

void My_Dac::start() {
    calc_tim_arr_psc();
    stop();
    if (_channel == Dac_Channel_1)
        HAL_DAC_Start_DMA(_hdac, DAC_CHANNEL_1, (uint32_t *)buf[Dac_Channel_1], DAC_BUFF_SIZE, DAC_ALIGN_12B_R);
    else if (_channel == Dac_Channel_2)
        HAL_DAC_Start_DMA(_hdac, DAC_CHANNEL_2, (uint32_t *)buf[Dac_Channel_2], DAC_BUFF_SIZE, DAC_ALIGN_12B_R);

    HAL_TIM_Base_Start(_htim);
}

void My_Dac::stop() {
    HAL_TIM_Base_Stop(_htim);
    if (_channel == Dac_Channel_1)
        HAL_DAC_Stop_DMA(_hdac, DAC_CHANNEL_1);
    else if (_channel == Dac_Channel_2)
        HAL_DAC_Stop_DMA(_hdac, DAC_CHANNEL_2);
}

void My_Dac::select_wave(WaveformProperties &wave) {
    memset(buf[_channel], 0, DAC_BUFF_SIZE);
    if (wave._type == Waveform_Sine)
        dac_creat_sin_buf(buf[_channel], wave._maxval, DAC_BUFF_SIZE, wave._phase);
    else if (wave._type == Waveform_Triangle)
        dac_creat_tri_buf(buf[_channel], wave._maxval, DAC_BUFF_SIZE, wave._phase);
}


//生成正弦波数组
void dac_creat_sin_buf(u16 *buf, u16 maxval, u32 samples, float phase_degrees)
{
    float32_t outdata;
    float32_t phase_radians = phase_degrees * PI / 180.0; // 将相位从角度转换为弧度
    float32_t inc = (2 * PI) / samples;
    float32_t amplitude = (float32_t)maxval / 2.0;  // 控制正弦波的幅度
    for(u32 i = 0; i < samples; i++)
    {
        // 正弦函数解析式：y= Asin(wx + k)
        outdata = amplitude * arm_sin_f32(inc * i + phase_radians) + amplitude; // 计算正弦波值
        outdata = outdata * 4096 / MAX_VOL; // 映射到DAC的范围
        u16 temp = round(outdata);
        if (temp >= 4096) temp = 4095;  // 确保输出不超过最大值
        buf[i] = (u16)(temp);

    }
}

// 生成三角波数组
void dac_creat_tri_buf(u16 *buf, u16 maxval, u32 samples, u16 phase_time)
{
    float32_t outdata;
    float32_t inc = ((float32_t)maxval) / (samples / 2 );
    for(u32 i = 0 ; i < samples; i++)
    {
        // 三角函数解析式：y= Atri(2πx/λ + k) + b
        if (i < (samples )/2) {
            outdata = i * inc ;
        } else {
            outdata = (samples-i) * inc ;
        }
        outdata = outdata * 4096 / MAX_VOL; // 映射到 DAC 的范围
        u16 temp = round(outdata);
        if (temp >= 4096) temp = 4095;  // 确保输出不超过最大值
        buf[i] = (u16)(temp);
    }
}