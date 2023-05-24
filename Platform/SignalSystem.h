//
// Created by Whisky on 2023/5/23.
//

#ifndef HELLOWORLD_SIGNALSYSTEM_H
#define HELLOWORLD_SIGNALSYSTEM_H
#include "EmbeddedSystem.h"

typedef enum {
    Waveform_Unknown = 0,   // 未知波形
    Waveform_Square,        // 方波
    Waveform_Triangle,      // 三角波
    Waveform_Sine           // 正弦波
} Waveform_Type;

class SignalSystem : public EmbeddedSystem
{
public:

};
#endif //HELLOWORLD_SIGNALSYSTEM_H
