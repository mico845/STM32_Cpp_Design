//
// Created by Whisky on 2023/5/23.
//

#ifndef HELLOWORLD_MY_DAC_H
#define HELLOWORLD_MY_DAC_H

#include "SignalPeripheral.h"
#include "SignalSystem.h"
#include "arm_math.h"
#include "Config.h"

typedef enum
{
    Dac_Channel_1 = 0,
    Dac_Channel_2,
}Dac_Channel;

struct WaveformProperties;

class My_Dac: public SignalPeripheral {

public:
    My_Dac(DAC_HandleTypeDef * hdac, Dac_Channel channel, TIM_HandleTypeDef* htim) : SignalPeripheral(htim),
                                                                        _channel(channel), _hdac(hdac) { }
    ~My_Dac() = default;
    My_Dac& init(uint32_t f_out, uint64_t f_in, WaveformProperties &wave);
    void start() override;
    void stop() override;

private:
    DAC_HandleTypeDef *_hdac;
    Dac_Channel _channel = Dac_Channel_1;
    u16 buf[2][DAC_BUFF_SIZE] = {0};
    void select_wave(WaveformProperties &wave);
};

struct WaveformProperties {
public:
    friend class My_Dac;
public:
    // Add a constructor with default values
    WaveformProperties(
            Waveform_Type type = Waveform_Sine,
            uint16_t maxval = 3300,
            float phase = 0) : _type(type), _maxval(maxval), _phase(phase) { }
    WaveformProperties& set_type(Waveform_Type type) {_type = type ; return *this;}
    WaveformProperties& set_maxval(u16 maxval) {_maxval = maxval ; return *this;}
    WaveformProperties& set_phase(float phase) {_phase = phase ; return *this;}
private:
    Waveform_Type _type;
    u16 _maxval;
    float _phase;


};

#endif //HELLOWORLD_MY_DAC_H
