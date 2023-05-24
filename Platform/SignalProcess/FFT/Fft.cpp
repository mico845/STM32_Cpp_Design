//
// Created by Whisky on 2023/5/23.
//
#include "AdvancedMeasure.h"
#include "arm_const_structs.h"
#include "retarget.h"

void cfft(float32_t *input, u32 fftSize, u8 ifftFlag, u8 bitReverseFlag, float32_t *fft_output_maxval)
{
    /* input 处理*/
    float32_t fft_input[fftSize * 2];

    for(u32 i = 0; i < fftSize; i++)
    {
        fft_input[i * 2] = input[i];
        fft_input[i * 2 + 1] = 0;
    }

    if (fftSize == 2048)
        arm_cfft_f32(&arm_cfft_sR_f32_len2048, fft_input, ifftFlag, bitReverseFlag);
    else if (fftSize == 1024)
        arm_cfft_f32(&arm_cfft_sR_f32_len1024, fft_input, ifftFlag, bitReverseFlag);
    else if (fftSize == 512)
        arm_cfft_f32(&arm_cfft_sR_f32_len512, fft_input, ifftFlag, bitReverseFlag);
    else if (fftSize == 4096)
        arm_cfft_f32(&arm_cfft_sR_f32_len4096, fft_input, ifftFlag, bitReverseFlag);
    else if (fftSize == 256)
        arm_cfft_f32(&arm_cfft_sR_f32_len256, fft_input, ifftFlag, bitReverseFlag);
    else if (fftSize == 128)
        arm_cfft_f32(&arm_cfft_sR_f32_len128, fft_input, ifftFlag, bitReverseFlag);
    else if (fftSize == 64)
        arm_cfft_f32(&arm_cfft_sR_f32_len64, fft_input, ifftFlag, bitReverseFlag);
    else if (fftSize == 32)
        arm_cfft_f32(&arm_cfft_sR_f32_len32, fft_input, ifftFlag, bitReverseFlag);
    else if (fftSize == 16)
        arm_cfft_f32(&arm_cfft_sR_f32_len16, fft_input, ifftFlag, bitReverseFlag);
    else
    {
        printf("error : fft_size set error\r\n");
        return;
    }
    arm_cmplx_mag_f32(fft_input, fft_output_maxval, fftSize);
}

AdvancedMeasure& AdvancedMeasure::fft() {
    cfft(signal, SIGNAL_BUFF_SIZE, 0, 1, signal);
#ifdef FFT_DEBUG
    debug();
#endif
    return *this;
}

