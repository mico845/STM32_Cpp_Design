//
// Created by Whisky on 2023/6/1.
//

#ifndef HELLOWORLD_SCREENWINDOWS_H
#define HELLOWORLD_SCREENWINDOWS_H
#include "ScreenBase/ScreenBase.h"
#include "Platform.h"

class ScreenWindows: public ScreenBase
{
public:
    ScreenWindows(uint16_t sx, uint16_t sy, uint16_t ex, uint16_t ey, uint16_t color = BLACK)
    : ScreenBase(sx, sy, ex, ey, color) { }

    ScreenWindows& refresh() override;
    ScreenWindows& add_frame(uint16_t color) override;

};

#endif //HELLOWORLD_SCREENWINDOWS_H
