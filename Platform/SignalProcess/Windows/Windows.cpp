//
// Created by Whisky on 2023/5/23.
//

#include "SignalProcessBase.h"

SignalProcessBase& SignalProcessBase::apply_windows() {
    float32_t windows[SIGNAL_BUFF_SIZE];
    arm_hamming_f32(windows, SIGNAL_BUFF_SIZE);
    for (uint32_t i = 0; i < SIGNAL_BUFF_SIZE; ++i)
        signal[i] = signal[i] * windows[i];
#ifdef WINDOWS_DEBUG
    debug();
#endif
    return *this;
}

SignalProcessBase& SignalProcessBase::release_windows() {
    float32_t ENBW = 0.5;
    for (uint32_t i = 0; i < SIGNAL_BUFF_SIZE; ++i)
        signal[i] = signal[i] / ENBW;
    return *this;
}