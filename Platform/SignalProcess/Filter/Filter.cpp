//
// Created by Whisky on 2023/5/24.
//

#include "SignalProcessBase.h"
#include "fdacoefs.h"

#define BLOCK_SIZE (32)                                 /* 调用一次arm_fir_f32处理的采样点个数 */
uint32_t blockSize = BLOCK_SIZE;
uint32_t numBlocks = FILTER_LENGTH_SAMPLES/BLOCK_SIZE;  /* 需要调用arm_fir_f32的次数 */
static float32_t firStateF32[BLOCK_SIZE + BL - 1];      /* 状态缓存，大小numTaps + blockSize - 1*/

void filter_fir(float32_t *inputF32, float32_t *outputF32)
{
    arm_fir_instance_f32 S;
    arm_fir_init_f32(&S, BL, (float32_t *)&B[0], &firStateF32[0], blockSize);
    for(u32 i = 0; i < numBlocks; ++i)
    {
        arm_fir_f32(&S, inputF32 + (i * blockSize), outputF32 + (i * blockSize), blockSize);
    }
}

SignalProcessBase &SignalProcessBase::filter(Filter_Type type) {
    filter_fir(signal, signal);
#ifdef FILTER_DEBUG
    debug();
#endif
    return *this;
}


