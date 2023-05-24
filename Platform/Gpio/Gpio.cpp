//
// Created by Whisky on 2023/5/24.
//

#include "Gpio.h"

void Gpio::set() {
    _PinState = GPIO_PIN_SET;
    HAL_GPIO_WritePin(_GPIOx, _GPIO_Pin, _PinState);
}

void Gpio::reset() {
    _PinState = GPIO_PIN_RESET;
    HAL_GPIO_WritePin(_GPIOx, _GPIO_Pin, _PinState);
}

void Gpio::toggle() {
    if (_PinState == GPIO_PIN_RESET)
        _PinState = GPIO_PIN_SET;
    else
        _PinState = GPIO_PIN_RESET;
    HAL_GPIO_WritePin(_GPIOx, _GPIO_Pin, _PinState);
}

GPIO_PinState Gpio::read() {
    return HAL_GPIO_ReadPin(_GPIOx, _GPIO_Pin);
}
