//
// Created by Whisky on 2023/5/24.
//

#ifndef HELLOWORLD_CONFIG_H
#define HELLOWORLD_CONFIG_H
/**********************************/
//DEBUG
/**********************************/
//#define TIM_DEBUG
//#define FFT_DEBUG
//#define ADC_DEBUG
//#define FILTER_DEBUG
//#define PWM_DEBUG
//#define WINDOWS_DEBUG
//#define RECGNIZE_DEBUG

/**********************************/
//ADC
/**********************************/
#define ADC_BUFF_SIZE (8192)

/**********************************/
//DAC
/**********************************/
#define DAC_BUFF_SIZE 144
#define MAX_VOL 3300

/**********************************/
//SIGNAL_PROCESS
/**********************************/
#define SIGNAL_BUFF_SIZE (ADC_BUFF_SIZE/2)

/**********************************/
//FILTER
/**********************************/
#define FILTER_LENGTH_SAMPLES   SIGNAL_BUFF_SIZE

#endif //HELLOWORLD_CONFIG_H
