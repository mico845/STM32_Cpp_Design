//
// Created by Whisky on 2023/5/24.
//

#ifndef HELLOWORLD_GPIO_H
#define HELLOWORLD_GPIO_H

#include "BasePeripheral.h"
class Gpio : public BasePeripheral
{
public:
    Gpio(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin,
         GPIO_PinState PinState = GPIO_PIN_RESET) : _GPIOx(GPIOx), _GPIO_Pin(GPIO_Pin), _PinState(PinState) { }
    void set();
    void reset();
    void toggle();
    GPIO_PinState read();

private:
    GPIO_TypeDef* _GPIOx;
    uint16_t _GPIO_Pin;
    GPIO_PinState _PinState;
};

#endif //HELLOWORLD_GPIO_H
