//
// Created by Whisky on 2023/5/23.
//

#include "SignalPeripheral.h"
#include "math.h"
#include "retarget.h"


void SignalPeripheral::calc_tim_arr_psc()
{
    if (_f_in < _f_out) {
        // Handle this error case according to your requirements.
        return;
    }
    // Start with arr = psc = 0
    unsigned int arr = 0;
    unsigned int psc = 0;
    // First, try to increase arr while keeping psc constant
    while (_f_in / (arr + 1) > _f_out && arr < 65535) {
        arr++;
    }
    // If arr has reached its max value and we still don't meet the requirement,
    // then start to increase psc
    if (_f_in / ((arr + 1) * (psc + 1)) > _f_out) {
        while (_f_in / ((arr + 1) * (psc + 1)) > _f_out && psc < 65535) {
            psc++;
        }
    }
    _htim->Instance->CNT = 0;
    _htim->Instance->ARR = arr;
    _htim->Instance->PSC = psc;
#ifdef TIM_DEBUG
    debug();
#endif

}

void SignalPeripheral::debug() {
    printf("arr: %lu\n",_htim->Instance->ARR);
    printf("psc: %lu\n",_htim->Instance->PSC);
}

