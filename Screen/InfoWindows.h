//
// Created by Whisky on 2023/6/1.
//

#ifndef HELLOWORLD_INFOWINDOWS_H
#define HELLOWORLD_INFOWINDOWS_H
#include "ScreenBase/ScreenWindows.h"

class InfoWindows : ScreenWindows
{
public:
    InfoWindows(uint16_t sx, uint16_t sy, uint16_t ex, uint16_t ey, uint16_t color = BLACK)
    : ScreenWindows(sx, sy, ex, ey, color) { }

    InfoWindows& refresh() override;
    InfoWindows& add_frame(uint16_t color) override;

    void show_basic(BasicMeasure& basicmeasure, uint16_t color);
    void show_advanced(AdvancedMeasure& advancedmeasure, uint16_t color);
private:

};

#endif //HELLOWORLD_INFOWINDOWS_H
