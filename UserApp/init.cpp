//
// Created by Whisky on 2023/5/16.
//

#include "common_inc.h"

void Init()
{
    delay_init(144);
    RetargetInit(&huart1);
    lcd_init();
    painter.size = LCD_FONTSIZE_1608;
    lcd_clear();
    //start_demos();
    painter.back_color= GRAY;
    painter.color = BROWN;
    painter.mode = LCD_MODE_NO_BACKFILLED;
    lcd_clear();

#ifdef UART_RECEIVE
    ENABLE_IDLECallback();
    UART_IDLE_RegisterCallback(USER_UART_RxCpltCallback);
    HAL_UART_Receive_DMA(&huart3, (uint8_t*)Rx_str, RX_STR_LEN);
#endif
}
