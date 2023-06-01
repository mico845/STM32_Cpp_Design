//
// Created by Whisky on 2023/6/1.
//

#ifndef HELLOWORLD_GRAPHWINDOWS_H
#define HELLOWORLD_GRAPHWINDOWS_H
#include "ScreenBase/ScreenWindows.h"

class GraphWindows : ScreenWindows
{
public:
    GraphWindows(uint16_t sx, uint16_t sy, uint16_t ex, uint16_t ey, uint16_t color = BLACK)
                                                            : ScreenWindows(sx, sy, ex, ey, color) { }
    void graph(My_Adc& adc , uint16_t color);
    void graph(SignalProcessBase &signalProcessBase, uint16_t color,uint32_t size = SIGNAL_BUFF_SIZE);
    GraphWindows& add_ref_axis(uint16_t color);

    GraphWindows& refresh() override;
    GraphWindows& add_frame(uint16_t color) override;

    GraphWindows& set_scaleFactorX(float scaleFactorX)
    { _scaleFactorX = scaleFactorX; return *this;}
    GraphWindows& set_scaleFactorY(float scaleFactorY)
    { _scaleFactorY = scaleFactorY; return *this;}

private:
    uint32_t mapX(uint32_t value, uint32_t fromLow, uint32_t fromHigh, uint32_t toLow, uint32_t toHigh);
    uint32_t mapY(uint32_t value, uint32_t fromLow, uint32_t fromHigh, uint32_t toLow, uint32_t toHigh);
    float _scaleFactorX = 1.0, _scaleFactorY = 1.0;
};


#endif //HELLOWORLD_GRAPHWINDOWS_H
