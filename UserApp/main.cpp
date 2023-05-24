//
// Created by Whisky on 2023/5/16.
//
#include "common_inc.h"

My_Adc Adc(&hadc1 , &htim2);
My_Dac Dac(&hdac, Dac_Channel_1, &htim8);
My_Dac Dac2(&hdac, Dac_Channel_2, &htim8);
My_Pwm Pwm(&htim3, TIM_CHANNEL_1);
AdvancedMeasure advanced_measure;
PwmMeasure pm(&htim9, TIM_CHANNEL_1);

void Main()
{
    Init();

    Pwm.init(1000, 72000000).start();
    WaveformProperties wave (Waveform_Sine, 3300, 0);
    Dac.init(2000, 144000000, wave).start();
    wave.set_type(Waveform_Triangle);
    Dac2.init(1000, 144000000, wave).start();
    pm.init(1000000, 144000000);
    Adc.init(102400, 72000000).start();


    for (;;) {
        //pm.start();

        if (adc_finished)
        {
            advanced_measure.init(Adc).filter(FIR);
            advanced_measure.read();
            advanced_measure.apply_windows().fft();
            printf("freq: %f\n", advanced_measure.get_freq());
            adc_finished = false;
           // Adc.start();
        }

    }

}

