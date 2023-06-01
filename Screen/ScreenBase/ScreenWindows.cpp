//
// Created by Whisky on 2023/6/1.
//

#include "ScreenWindows.h"


ScreenWindows& ScreenWindows::refresh() {
    ScreenBase::refresh();
    return *this;
}

ScreenWindows &ScreenWindows::add_frame(uint16_t color) {
    ScreenBase::add_frame(color);
    return *this;
}


