# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

# compile ASM with C:/MinGW/gcc-arm-none-eabi/bin/arm-none-eabi-gcc.exe
# compile C with C:/MinGW/gcc-arm-none-eabi/bin/arm-none-eabi-gcc.exe
# compile CXX with C:/MinGW/gcc-arm-none-eabi/bin/arm-none-eabi-g++.exe
ASM_FLAGS =   -mfloat-abi=hard -mfpu=fpv4-sp-d16 -mcpu=cortex-m4 -mthumb -mthumb-interwork -ffunction-sections -fdata-sections -fno-common -fmessage-length=0 -Og -g

ASM_DEFINES = -DARM_MATH_CM4 -DARM_MATH_MATRIX_CHECK -DARM_MATH_ROUNDING -DSTM32F407xx -DUSE_HAL_DRIVER

ASM_INCLUDES = -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Core\Inc -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Drivers\STM32F4xx_HAL_Driver\Inc -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Drivers\STM32F4xx_HAL_Driver\Inc\Legacy -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Drivers\CMSIS\Device\ST\STM32F4xx\Include -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Drivers\CMSIS\Include -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\UserApp -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\System\sys -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\System\usart -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\System\delay -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Platform -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Platform\Gpio -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Platform\Peripheral -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Platform\Adc -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Platform\Dac -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Platform\Pwm -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Platform\SignalProcess -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Platform\SignalProcess\BasicMeasure -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Platform\SignalProcess\AdvancedMeasure -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Platform\SignalProcess\FFT -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Platform\SignalProcess\Filter -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Platform\SignalProcess\Filter\fdacoefs -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Platform\SignalProcess\PwmMeasure -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Screen\ScreenBase -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Screen -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\HardWare\lcd -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\HardWare\key -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\ARM_DSP\Include\dsp -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\ARM_DSP\Include -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\ARM_DSP\PrivateInclude 

C_FLAGS =   -mfloat-abi=hard -mfpu=fpv4-sp-d16 -mcpu=cortex-m4 -mthumb -mthumb-interwork -ffunction-sections -fdata-sections -fno-common -fmessage-length=0 -Og -g -std=gnu11

C_DEFINES = -DARM_MATH_CM4 -DARM_MATH_MATRIX_CHECK -DARM_MATH_ROUNDING -DSTM32F407xx -DUSE_HAL_DRIVER

C_INCLUDES = -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Core\Inc -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Drivers\STM32F4xx_HAL_Driver\Inc -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Drivers\STM32F4xx_HAL_Driver\Inc\Legacy -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Drivers\CMSIS\Device\ST\STM32F4xx\Include -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Drivers\CMSIS\Include -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\UserApp -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\System\sys -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\System\usart -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\System\delay -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Platform -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Platform\Gpio -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Platform\Peripheral -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Platform\Adc -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Platform\Dac -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Platform\Pwm -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Platform\SignalProcess -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Platform\SignalProcess\BasicMeasure -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Platform\SignalProcess\AdvancedMeasure -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Platform\SignalProcess\FFT -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Platform\SignalProcess\Filter -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Platform\SignalProcess\Filter\fdacoefs -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Platform\SignalProcess\PwmMeasure -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Screen\ScreenBase -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Screen -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\HardWare\lcd -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\HardWare\key -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\ARM_DSP\Include\dsp -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\ARM_DSP\Include -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\ARM_DSP\PrivateInclude 

CXX_FLAGS =   -mfloat-abi=hard -mfpu=fpv4-sp-d16 -mcpu=cortex-m4 -mthumb -mthumb-interwork -ffunction-sections -fdata-sections -fno-common -fmessage-length=0 -Og -g -std=gnu++17

CXX_DEFINES = -DARM_MATH_CM4 -DARM_MATH_MATRIX_CHECK -DARM_MATH_ROUNDING -DSTM32F407xx -DUSE_HAL_DRIVER

CXX_INCLUDES = -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Core\Inc -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Drivers\STM32F4xx_HAL_Driver\Inc -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Drivers\STM32F4xx_HAL_Driver\Inc\Legacy -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Drivers\CMSIS\Device\ST\STM32F4xx\Include -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Drivers\CMSIS\Include -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\UserApp -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\System\sys -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\System\usart -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\System\delay -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Platform -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Platform\Gpio -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Platform\Peripheral -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Platform\Adc -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Platform\Dac -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Platform\Pwm -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Platform\SignalProcess -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Platform\SignalProcess\BasicMeasure -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Platform\SignalProcess\AdvancedMeasure -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Platform\SignalProcess\FFT -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Platform\SignalProcess\Filter -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Platform\SignalProcess\Filter\fdacoefs -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Platform\SignalProcess\PwmMeasure -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Screen\ScreenBase -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\Screen -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\HardWare\lcd -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\HardWare\key -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\ARM_DSP\Include\dsp -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\ARM_DSP\Include -IC:\Users\Whisky\MYProjects\Project_STM32\STM32_F407_VET6\main\ARM_DSP\PrivateInclude 

