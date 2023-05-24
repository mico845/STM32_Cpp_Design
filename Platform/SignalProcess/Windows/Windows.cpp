//
// Created by Whisky on 2023/5/23.
//

#include "SignalProcessBase.h"

SignalProcessBase& SignalProcessBase::apply_windows() {
    float32_t windows[SIGNAL_BUFF_SIZE];
    arm_hamming_f32(windows, SIGNAL_BUFF_SIZE);
    for (u32 i = 0; i < SIGNAL_BUFF_SIZE; ++i)
        signal[i] = signal[i] * windows[i];
#ifdef WINDOWS_DEBUG
    debug();
#endif
    return *this;
}