//
// Created by Whisky on 2023/5/23.
//

#ifndef HELLOWORLD_SIGNALPERIPHERAL_H
#define HELLOWORLD_SIGNALPERIPHERAL_H

#include "BasePeripheral.h"
#include "Config.h"

class SignalPeripheral : public BasePeripheral {
public:
    SignalPeripheral(TIM_HandleTypeDef *htim) : _htim(htim) { }

    ~SignalPeripheral() = default;

    virtual SignalPeripheral& init(uint32_t f_out, uint64_t f_in){
        _f_out = f_out;
        _f_in = f_in;
        return *this;
    }

    virtual void start() = 0;
    virtual void stop() = 0;

protected:
    virtual void calc_tim_arr_psc();
    uint32_t _f_out;
    uint64_t _f_in;
    TIM_HandleTypeDef *_htim;
private:
    void init() override { }
    void debug();
};

#endif //HELLOWORLD_SIGNALPERIPHERAL_H
