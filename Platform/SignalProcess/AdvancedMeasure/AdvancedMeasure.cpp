//
// Created by Whisky on 2023/5/23.
//

#include "AdvancedMeasure.h"

AdvancedMeasure &AdvancedMeasure::init(My_Adc &Adc) {
    SignalProcessBase::init(Adc);
    _samplerate = samplerate;
    return *this;
}

AdvancedMeasure &AdvancedMeasure::apply_windows() {
    SignalProcessBase::apply_windows();
    return *this;
}

AdvancedMeasure &AdvancedMeasure::fft() {
    SignalProcessBase::fft();
    return *this;
}

AdvancedMeasure &AdvancedMeasure::filter(Filter_Type type) {
    SignalProcessBase::filter(type);
    return *this;
}

float32_t AdvancedMeasure::get_freq() {
    float32_t max_value = 0;
    // 寻找缓冲区中最大值及其位置
    for (u32 i = 2; i <  SIGNAL_BUFF_SIZE / 2; i++) {

        if (fabs(signal[i]) > max_value) {

            max_value = fabs(signal[i]);
            _max_index = i;
        }
    }
    // 计算最大值所在的频率
    float32_t freq = (float32_t)( _max_index * samplerate/SIGNAL_BUFF_SIZE );
    _freq = freq;
    return freq;
}

float32_t AdvancedMeasure::get_THD(u8 range) {
    float32_t max_value = 0;
    u32 max_index_3th;
    u32 max_index_5th;
    // 寻找缓冲区中最大值及其位置
    for (u32 i = 2; i <  SIGNAL_BUFF_SIZE / 2; i++) {

        if (fabs(signal[i]) > max_value) {

            max_value = fabs(signal[i]);
            _max_index = i;
        }
    }
    // 计算最大值所在的频率
    max_index_3th =  _max_index * 3;
    max_index_5th =  _max_index * 5;

    float64_t sum_1th = 0;
    float64_t sum_3th = 0;
    float64_t sum_5th = 0;

    // 计算3次谐波和5次谐波分量的幅度和
    for (int i = -range/2; i <= range/2; i++) {
        if ( _max_index + i >= 0 &&  _max_index + i <= SIGNAL_BUFF_SIZE)
        {
            sum_1th += signal[ _max_index + i];
        }
        if (max_index_3th + i >= 0 && max_index_3th + i <= SIGNAL_BUFF_SIZE)
        {
            sum_3th += signal[max_index_3th + i];
        }
        if (max_index_5th + i >= 0 && max_index_5th + i <= SIGNAL_BUFF_SIZE)
        {
            sum_5th += signal[max_index_5th + i];
        }
    }
    // 计算总谐波失真度
    float32_t THD = (sqrt(pow(sum_3th, 2) + pow(sum_5th, 2)) / fabs(sum_1th)) * 100;
    return THD;
}
float32_t AdvancedMeasure::get_THD()
{
    return get_THD(5);
}

Waveform_Type AdvancedMeasure::fft_recognize_wave(u8 range) {

    float32_t max_value = 0;
    u32 max_index_3th;

// 寻找缓冲区中最大值及其位置
    for (u32 i = 2; i <  SIGNAL_BUFF_SIZE / 2; i++) {

        if (fabs(signal[i]) > max_value) {

            max_value = fabs(signal[i]);
            _max_index = i;
        }
    }
// 计算最大值所在的频率
    max_index_3th =  _max_index * 3;

    float64_t sum_1th = 0;
    float64_t sum_3th = 0;

// 能量泄漏范围为 range， 例如range = 5， 即将一个坐标周围即本身（-2到2）一共5个点求和
    // 计算3次谐波
    for (int i = -range/2; i <= range/2; i++) {
        if ( _max_index + i >= 0 &&  _max_index + i <= SIGNAL_BUFF_SIZE)
        {
            sum_1th += signal[ _max_index + i];
        }
        if (max_index_3th + i >= 0 && max_index_3th + i <= SIGNAL_BUFF_SIZE)
        {
            sum_3th += signal[max_index_3th + i];
        }
    }

    float32_t k = sum_1th/sum_3th;

#ifdef RECGNIZE_DEBUG
    printf("k: %f\n",k);
#endif

    if (k < 4 && k > 2)         //方波的 基波幅度 是三次谐波幅度的 三倍。 实际测量在2~4之间浮动
        return Waveform_Square;

    else if (k < 12 && k > 6)       //三角波的基波幅度是三次谐波幅度的 九倍。  实际测量在 6 ~ 12 间浮动
        return Waveform_Triangle;

    else if (k > 13)                //正弦波理论上三次谐波幅度是0，k值会非常大
        return Waveform_Sine;
    else
        return Waveform_Unknown;
}

Waveform_Type AdvancedMeasure::fft_recognize_wave() {
    return fft_recognize_wave(5);
}

float32_t AdvancedMeasure::read_freq() {
    return _freq;
}

AdvancedMeasure& AdvancedMeasure::convert_amplitude() {
    signal[0] = signal[0]/SIGNAL_BUFF_SIZE * (float32_t)(2.0);

    for (uint32_t i = 1; i <= SIGNAL_BUFF_SIZE; ++i) {
        signal[i] = signal[i]/SIGNAL_BUFF_SIZE * (float32_t)(4.0);
    }

    return *this;
}

float32_t AdvancedMeasure::get_amplitude() {
    float32_t max_value = 0;
    // 寻找缓冲区中最大值及其位置
    for (u32 i = 2; i <  SIGNAL_BUFF_SIZE / 2; i++) {

        if (fabs(signal[i]) > max_value) {

            max_value = fabs(signal[i]);
            _max_index = i;
        }
    }

    return max_value;
}

float32_t AdvancedMeasure::find(uint32_t index, uint8_t range) {
    float32_t sum = signal[index];
    if (index - range >= 0 && index + range < SIGNAL_BUFF_SIZE)
    {
        for (uint32_t i = index - range; i <= index + range; ++i)
            sum += pow(signal[i], 2) ;
        sum = sqrt(sum);
    }
    return sum;
}

uint32_t AdvancedMeasure::read_max_index() {
    return _max_index;
}

AdvancedMeasure &AdvancedMeasure::release_windows() {
    SignalProcessBase::release_windows();
    return *this;
}

AdvancedMeasure &AdvancedMeasure::convert_to_mv() {
    SignalProcessBase::convert_to_mv();
    return *this;
}

AdvancedMeasure &AdvancedMeasure::normalize(uint32_t max_value) {
    SignalProcessBase::normalize(max_value);
    return *this;
}

AdvancedMeasure &AdvancedMeasure::deal_DC() {
    SignalProcessBase::deal_DC();
    return *this;
}

uint32_t AdvancedMeasure::get_second_freq(uint32_t interval) {
    float32_t max_value = 0;
    // 寻找缓冲区中最大值及其位置
    for (uint32_t i = 2 ; i <  SIGNAL_BUFF_SIZE / 2; ++i) {
        if (i > _max_index -interval && i < _max_index + interval)
            continue;

        if (fabs(signal[i]) > max_value) {
            max_value = fabs(signal[i]);
            _second_index = i;
        }

    }
    float32_t freq = (float32_t)( _second_index * _samplerate/SIGNAL_BUFF_SIZE );
    return freq;
}

uint32_t AdvancedMeasure::read_second_index() {
    return _second_index;
}

float32_t AdvancedMeasure::get_samplerate() {
    return _samplerate;
}





