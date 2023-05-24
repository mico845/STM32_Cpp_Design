//
// Created by Whisky on 2023/5/23.
//

#include "SignalPeripheral.h"
#include "math.h"
#include "retarget.h"

void SignalPeripheral::calc_tim_arr_psc()
{
    double target = (double)_f_in / _f_out;  // target arr*psc value
    double min_diff = target;  // initialize with a large value
    uint32_t psc_min = 1, psc_max = 65536;
    uint16_t arr, psc = 0;
    // binary search for the best psc value
    while (psc_min <= psc_max) {
        uint32_t psc_mid = (psc_min + psc_max) / 2;
        double arr_candidate = target / psc_mid - 1;
        if (arr_candidate > 65535) {
            psc_min = psc_mid + 1;
        } else {
            if (arr_candidate < 0) arr_candidate = 0;
            double diff = fabs(round(arr_candidate) + 1 - target / psc_mid);  // calculate difference
            if (diff < min_diff) {  // if better solution is found
                min_diff = diff;
                arr = round(arr_candidate);
                psc = psc_mid - 1;
            }
            psc_max = psc_mid - 1;
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

