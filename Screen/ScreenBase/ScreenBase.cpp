//
// Created by Whisky on 2023/6/1.
//

#include "ScreenBase.h"

ScreenBase& ScreenBase::refresh() {
    lcd_fill(_sx ,_sy ,_ex ,_ey,_color);
    return *this;
}

ScreenBase &ScreenBase::add_frame(uint16_t color) {
    lcd_draw_rectangle(_sx - 1,_sy - 1 ,_ex +1 ,_ey +1, color);
    return *this;
}


