//
// Created by Whisky on 2023/6/1.
//

#include "InfoWindows.h"

void InfoWindows::show_basic(BasicMeasure &basicmeasure, uint16_t color) {
    lcd_show_string(_sx, _sy, "max:");
    lcd_show_num(_sx + 4 * 8, _sy, convert_to_analog_mv(basicmeasure.get_max()),4, .color = color);
    lcd_show_string(_sx + 8 * 8, _sy, "mv");

    //---------min
    lcd_show_string(_sx, _sy + 16 * 1, "min:");
    lcd_show_num(_sx + 4 * 8, _sy + 16 * 1, convert_to_analog_mv(basicmeasure.get_min()),4 , .color = color);
    lcd_show_string(_sx + 8 * 8, _sy+ 16 * 1, "mv");

    //---------peak to peak
    lcd_show_string(_sx, _sy + 16 * 2, "pp :");
    lcd_show_num(_sx + 4 * 8, _sy + 16 * 2,convert_to_analog_mv(basicmeasure.get_peak_to_peak()),4 , .color = color);
    lcd_show_string(_sx + 8 * 8, _sy+ 16 * 2, "mv");

    //---------rms
    lcd_show_string(_sx, _sy + 16 * 3, "rms:");
    lcd_show_num(_sx + 4 * 8, _sy + 16 * 3, convert_to_analog_mv(basicmeasure.get_rms()),4 , .color = color);
    lcd_show_string(_sx + 8 * 8, _sy+ 16 * 3, "mv");
}

void InfoWindows::show_advanced(AdvancedMeasure &advancedmeasure, uint16_t color) {
    lcd_show_string(_sx, _sy, "Freq:");
    lcd_show_num(_sx, _sy + 16, (u32)advancedmeasure.get_freq(),8, .color = color);

    lcd_show_string(_sx, _sy+16*2, "THD:");
    lcd_show_num(_sx, _sy+ 16 * 3, (u32)(advancedmeasure.get_THD()),3 , .color = color);
    lcd_show_char(_sx + 3*8, _sy+ 16 * 3, '.', .color = color);
    lcd_show_xnum(_sx + 4*8, _sy+ 16 * 3, ((u32)(advancedmeasure.get_THD() * 100) % 100), 2,  .color = color, .mode = LCD_MODE_NO_BACKFILLED,);
    lcd_show_char(_sx + 6*8, _sy+ 16 * 3, '%', .color = color);
}

InfoWindows &InfoWindows::refresh() {
    ScreenWindows::refresh();
    return *this;
}

InfoWindows &InfoWindows::add_frame(uint16_t color) {
    ScreenWindows::add_frame(color);
    return *this;
}
