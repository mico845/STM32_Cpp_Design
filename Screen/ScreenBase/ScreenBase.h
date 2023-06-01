//
// Created by Whisky on 2023/6/1.
//

#ifndef HELLOWORLD_SCREENBASE_H
#define HELLOWORLD_SCREENBASE_H
#ifdef __cplusplus
extern "C" {
#endif
/*---------------------------- C Scope ---------------------------*/
#include "lcd.h"

#ifdef __cplusplus
}
/*---------------------------- C++ Scope ---------------------------*/
class ScreenBase
{
public:
    ScreenBase(uint16_t sx, uint16_t sy, uint16_t ex, uint16_t ey, uint16_t color = BLACK)
    : _sx(sx), _sy(sy), _ex(ex),_ey(ey),_color(color) { }
    virtual ScreenBase& add_frame(uint16_t color);
    virtual ScreenBase& refresh();
protected:
    uint16_t _sx,_sy,_ex,_ey,_color;
};
#endif
#endif //HELLOWORLD_SCREENBASE_H
