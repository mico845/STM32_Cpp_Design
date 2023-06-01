//
// Created by Whisky on 2023/6/1.
//

#include "GraphWindows.h"

#define ADC_MAX (4096)

void GraphWindows::graph(My_Adc &adc, uint16_t color) {
    u32 x1, x2, y1, y2;
    uint32_t size = ADC_BUFF_SIZE;

    for (uint32_t i = 0; i < size - 1; i ++) {
        // 计算坐标
        // 计算当前点和下一个点的坐标
        x1 = mapX((size - i) * _scaleFactorX, 0, size, _sx , _ex );
        x2 = mapX((size - (i + 1)) * _scaleFactorX, 0, size, _sx , _ex );
        y1 = mapY(adc.adc_buf[i] * _scaleFactorY, 0, ADC_MAX, _sy , _ey );
        y2 = mapY(adc.adc_buf[i + 1] * _scaleFactorY, 0, ADC_MAX, _sy , _ey);

        // 超出矩形范围
        if (x1 > _ex || x2 > _ex || y1 > _ey || y2 > _ey) {
            continue;
        }

        // 绘制直线
        lcd_draw_line(x1, y1, x2, y2, color);
#if 0
        // 绘制点
        lcd_draw_point(x1, y1, color);
#endif
    }
}

GraphWindows &GraphWindows::add_ref_axis(uint16_t color) {
    uint16_t y_interval = (_ey - _sy)/10;
    for (uint16_t y = _sy; y < _ey; y += y_interval) {
        lcd_draw_hline(_sx , y,  (_ex - _sx)  , color);  // 修改为从 _sx 开始绘制
    }
    uint16_t x_interval = (_ex - _sx) / 10;
    for (uint16_t x =_sx; x < (_ex); x += x_interval) {
        lcd_draw_line(x , _sy, x, _ey, color);  // 修改为从 _sy 到 _ey 绘制
    }
    return *this;
}

GraphWindows &GraphWindows::refresh() {
    ScreenWindows::refresh();
    return *this;
}

GraphWindows &GraphWindows::add_frame(uint16_t color) {
    ScreenWindows::add_frame(color);
    return *this;
}

void GraphWindows::graph(SignalProcessBase &signalProcessBase, uint16_t color,uint32_t size) {
    uint32_t x1, x2, y1, y2;
    float32_t max = signalProcessBase.get_max();
    float32_t min = signalProcessBase.get_min();

    for (uint32_t i = 0; i < size - 1; i++) {
        x1 = mapX((size - i) * _scaleFactorX, 0, size, _sx, _ex);
        x2 = mapX((size - (i + 1)) * _scaleFactorX, 0, size, _sx, _ex);
        y1 = mapY(signalProcessBase.signal[i] * _scaleFactorY, min, max,
                  _sy, _ey);
        y2 = mapY(signalProcessBase.signal[i + 1] * _scaleFactorY, min, max, _sy, _ey);

        if (x1 > _ex || x2 > _ex || y1 > _ey || y2 > _ey) {
            continue;
        }

        lcd_draw_line(x1, y1, x2, y2, color);
    }
}

uint32_t GraphWindows::mapX(uint32_t value, uint32_t fromLow, uint32_t fromHigh, uint32_t toLow, uint32_t toHigh) {
    return (fromHigh - value) * (toHigh - toLow) / (fromHigh - fromLow) + toLow;
}

uint32_t GraphWindows::mapY(uint32_t value, uint32_t fromLow, uint32_t fromHigh, uint32_t toLow, uint32_t toHigh) {
    return (fromHigh - value) * (toHigh - toLow) / (fromHigh - fromLow) + toLow;
}





