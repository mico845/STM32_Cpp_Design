//
// Created by Whisky on 2023/5/16.
//
#include "common_inc.h"

//Peripheral
My_Adc Adc(&hadc1 , &htim2);
My_Dac Dac(&hdac, Dac_Channel_1, &htim8);
My_Dac Dac2(&hdac, Dac_Channel_2, &htim8);
My_Pwm Pwm(&htim3, TIM_CHANNEL_1);
AdvancedMeasure advanced_measure;

//GUI
GraphWindows signal_graph(10, 10, 220, 115, LGRAY);
GraphWindows signal_after_graph(10+5, 10+5, 220-5, 115-5, LGRAY);
InfoWindows basic_info(10, 122, 90, 187, LGRAYBLUE);
InfoWindows advanced_info(229, 41, 295, 105, LGRAYBLUE);

void adc_process();

void Main()
{
    Init();

    signal_graph.add_frame(CYAN);

    Pwm.init(1000, 72000000).start();
    WaveformProperties wave(Waveform_Sine, 3300, 0);
    Dac.init(1000, 144000000, wave).start();
    wave.set_type(Waveform_Triangle);
    Dac2.init(1000, 144000000, wave).start();
    Adc.init(409600, 72000000).start();

    for (;;) {
        if (Adc.is_finished())
        {
            adc_process();
        }
    }

}

void adc_process()
{
    static float x_scale = 100.0;
    advanced_measure.init(Adc);
    basic_info.refresh().show_basic(advanced_measure, BRRED);
    advanced_measure.apply_windows().fft();
    signal_graph.refresh().add_ref_axis(LIGHTGREEN).set_scaleFactorX(x_scale).set_scaleFactorY(1.0).graph(Adc,YELLOW);
    signal_after_graph.graph(advanced_measure,RED);
    advanced_info.refresh().show_advanced(advanced_measure, BRRED);
    uint32_t freq = advanced_measure.read_freq();
    x_scale = freq / 5.0;
    freq *= 15;
    if (freq <= 1000)
        freq = 15000;
    else if (freq >= 2400000)
        freq = 2400000;
    Adc.set_samplerate(freq).start();
}



