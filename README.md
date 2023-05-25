# STM32嵌入式程序设计C++实现

# 使用说明文档

### 1. 引入库
在你的代码中引入库：
```cpp
#include "Platform.h"
```
（该头文件包含了该库其他外设的头文件）

并添加库文件`Platform`

以及底层驱动库`ARM_DSP`、`adc`、`dac`、`dma`、`tim`、`gpio`

**注意：请记住添加头文件包含路径**

### 2. 图形化配置
使用STM32CubeMX进行图形化配置。
**注意，这个库是针对STM32微控制器编写的，使用之前需要先用STM32CubeMX进行硬件配置。**
### 3. 创建对象
创建一个`My_Adc`的对象。 例如：
```cpp
My_Adc Adc(&hadc1 , &htim2);
```
这里，`&hadc1`和 `&htim2` 是你在STM32CubeMX中配置的ADC和TIM的句柄。
### 4. 初始化
在你的主函数中，使用`init()`函数初始化`My_Adc`对象，其中，`f_out` 是输出频率，`f_in` 是输入频率。
对于ADC而言，`f_in` 是定时器的主频，`f_out` 是ADC采样率（由`f_in`分频得到）。
例如：
```cpp
Adc.init(102400, 72000000);
```
这里，`102400` 是ADC采样率，`72000000` 是触发ADC的定时器的主频。
### 5. 启动和操作
在你的主循环中，使用`start()`和`read()`函数来启动ADC并读取数据。例如：
```cpp
Adc.start();
for (;;) {
    if (Adc.is_finish()) {
        Adc.read();
        adc_finished = false;
        Adc.start();
    }
}
```
这里，`Adc.is_finished()`是一个ADC查询，当ADC读取完成时，会被设置为`true`。

## My_Adc 类
`My_Adc`类是一个用于控制STM32的ADC（模数转换器）的类，它继承自`SignalPeripheral`类， 通过继承`SignalPeripheral`类，可以实现定时器的控制。
### 成员函数
1. `My_Adc(ADC_HandleTypeDef* hadc, TIM_HandleTypeDef* htim)`
   构造函数，初始化ADC。`hadc` 是硬件ADC的句柄指针，`htim` 是硬件定时器的句柄指针。

2. `init(uint32_t f_out, uint64_t f_in)`
   初始化ADC。`f_out` 是输出频率，`f_in` 是输入频率。

3. `start()`
   启动ADC。

4. `stop()`
   停止ADC。

5. `read()`
   读取ADC的数据，并打印到控制台。

6. `is_finished()`
   判断ADC是否读取完成，如果完成，将会置位为`ture`。
### 使用案例
```cpp
#include "Adc/My_Adc.h"

My_Adc Adc(&hadc1 , &htim2);

void Main()
{
    ...

    Adc.init(102400, 72000000).start();

    for (;;) {

        if (Adc.is_finished())
        {
            Adc.read();
            adc_finished = false;
            Adc.start();
        }

    }

}

```

## My_Dac 类
`My_Dac`类是一个用于控制DAC（数模转换器）的类，它继承自`SignalPeripheral`类。
### 成员函数
1. `My_Dac(DAC_HandleTypeDef * hdac, Dac_Channel channel, TIM_HandleTypeDef* htim)`
   构造函数，初始化DAC。`hdac` 是硬件DAC的句柄指针，`channel` 是DAC输出的通道，`htim` 是硬件定时器的句柄指针。
   
2. `init(uint32_t f_out, uint64_t f_in, WaveformProperties &wave)`
   初始化DAC。`f_out` 是输出频率，`f_in` 是输入频率，`wave` 是波形属性。
   
3. `start()`
   启动DAC。
   
4. `stop()`
   停止DAC。
   
### 变量介绍
1. `Dac_Channel` 枚举体
   包含有`Dac_Channel_1`、`Dac_Channel_2`。
   <br>
   定义如下：
   
   ```cpp
   typedef enum
   {
      Dac_Channel_1 = 0,
      Dac_Channel_2,
   }Dac_Channel;
   ```
2. `Waveform_Type` 枚举体
   包含有未知波形`Waveform_Unknown`, 方波`Waveform_Square`, 三角波`Waveform_Triangle`, 正弦波`Waveform_Sine`。
   <br>
   定义如下：
   
   ```cpp
   typedef enum {
        Waveform_Unknown = 0,   // 未知波形
        Waveform_Square,        // 方波
        Waveform_Triangle,      // 三角波
        Waveform_Sine           // 正弦波
   } Waveform_Type;
   ```
3. `WaveformProperties`类
   实例时需要填三个变量，分别为：
   - 波形类型`type`, `Waveform_Type`类型, 目前只有`Waveform_Triangle`和`Waveform_Sine`可选;
   - 最大值`maxval`, `uint16_t`类型, 范围为0 - `MAX_VOL`;(`MAX_VOL` 无修改默认为 `3300`)
   - 相位`phase`（还在制作调试中）。
   <br>
   如不填写,将得到默认值:
     
   ```cpp
   WaveformProperties(Waveform_Type type = Waveform_Sine, uint16_t maxval = 3300, float phase = 0)
   ```
   可以调用内置成员函数进行后续修改：
   - 修改波形类型`WaveformProperties& set_type(Waveform_Type type) {_type = type ; return *this;}`
   - 修改最大值`WaveformProperties& set_maxval(u16 maxval) {_maxval = maxval ; return *this;}`
   - 修改相位`WaveformProperties& set_phase(float phase) {_phase = phase ; return *this;}`

### 使用案例

```cpp
#include "Dac/My_Dac.h"

My_Dac Dac(&hdac, Dac_Channel_1, &htim8);
My_Dac Dac2(&hdac, Dac_Channel_2, &htim8);

void Main()
{
    ...

   WaveformProperties wave (Waveform_Sine, 3300, 0);    //正弦波，3300mv，相位为0
   Dac.init(2000, 144000000, wave).start();
   wave.set_type(Waveform_Triangle);                    //三角波，3300mv，相位为0
   Dac2.init(1000, 144000000, wave).start();

    for (;;) {
        ...
    }

}
```


## My_Pwm 类
`My_Pwm`类是一个用于控制STM32的PWM（脉冲宽度调制）的类，它继承自`SignalPeripheral`类。

### 成员函数
1. `My_Pwm(TIM_HandleTypeDef* htim, uint8_t channel)`
   构造函数，初始化PWM。`htim` 是硬件定时器句柄，`channel` 是定时器通道。

2. `start()`
   启动PWM。

3. `stop()`
   停止PWM。

4. `set_duty(float duty)`
   设置PWM的占空比。`duty` 是占空比，取值范围`0.0`-`1.0`。如果不进行配置，占空比默认为`0.5`。

### 使用案例
```cpp
#include "Pwm/My_Pwm.h"

My_Pwm Pwm(&htim3, TIM_CHANNEL_1);

void Main()
{
    ...

    Pwm.init(1000, 72000000).start();
    
    for (;;) {
        ...
    }

}
```

## SignalProcessBase 类
`SignalProcessBase`类是一个信号处理基类，它继承自`EmbeddedSystem`类。用于信号窗函数的应用，傅立叶变换（FFT），以及滤波器的应用。

### 成员函数
1. `init(My_Adc& Adc)`
   初始化信号处理，输入参数为My_Adc类的一个实例。

2. `apply_windows()`
   应用窗函数。

3. `fft()`
   执行快速傅里叶变换。

4. `filter(Filter_Type type)`
   应用滤波器。`type` 是滤波器类型，可以是`FIR`或`IIR`。

5. `read()`
   读取信号数据。

### 变量介绍
1. `Filter_Type` 枚举体
   包含有两种滤波器类型：FIR滤波器`FIR`和IIR滤波器`IIR`。
   ```cpp
   typedef enum {
        FIR = 0,   // FIR滤波器
        IIR,       // IIR滤波器
   } Filter_Type;
   ```
   
### 使用案例
```cpp
#include "Adc/My_Adc.h"
#include "SignalProcessBase/SignalProcessBase.h"

My_Adc Adc(&hadc1 , &htim2);
SignalProcessBase signal_process_base;

void Main()
{
    ...
    
    Adc.init(102400, 72000000).start();
    
    for (;;) {
        if (Adc.is_finished())
        {
            Adc.read();
            signal_process_base.init(Adc);
            signal_process_base.read();
            adc_finished = false;
            Adc.start();
        }
    }

}
```

## BasicMeasure 类
`BasicMeasure`类是一个用于获取信号基本测量值的类，它继承自`SignalProcessBase`类。

### 成员函数
1. `get_max()`
   获取信号的最大值，返回值为 `float32_t` 类型。

2. `get_min()`
   获取信号的最小值，返回值为 `float32_t` 类型。

3. `get_peak_to_peak()`
   获取信号的峰峰值，返回值为 `float32_t` 类型。

4. `get_rms()`
   获取信号的均方根值，返回值为 `float32_t` 类型。

5. `get_average(u32 n)`
   获取信号的平均值，`n` 是取平均的点数，返回值为 `float32_t` 类型。

6. `get_average()`
   获取信号的平均值，无需输入参数，返回值为 `float32_t` 类型。

### 使用案例
```cpp
#include "Adc/My_Adc.h"
#include "BasicMeasure/BasicMeasure.h"

My_Adc Adc(&hadc1 , &htim2);
BasicMeasure basic_measure;

void Main()
{
    ...

    Adc.init(102400, 72000000).start();

    for (;;) {
        if (Adc.is_finished())
        {
            Adc.read();
            basic_measure.init(Adc);
            float32_t max = basic_measure.get_max();
            float32_t min = basic_measure.get_min();
            float32_t peak_to_peak = basic_measure.get_peak_to_peak();
            float32_t rms = basic_measure.get_rms();
            
            ...
            
            adc_finished = false;
            Adc.start();
        }
    }
}
```

## AdvancedMeasure 类
`AdvancedMeasure`类是一个用于获取信号高级测量值的类，它继承自`BasicMeasure`类。

### 成员函数
1. `get_freq()`
   获取信号的频率，返回值为 `float32_t` 类型。

2. `get_THD(u8 range)`
   获取信号的总谐波失真(THD)，`range` 是谐波的范围，返回值为 `float32_t` 类型。

3. `get_THD()`
   获取信号的总谐波失真(THD)，无需输入参数，返回值为 `float32_t` 类型。

4. `fft_recognize_wave(u8 range)`
   使用FFT识别信号的波形，`range` 是谐波的范围，返回值为 `Waveform_Type` 类型。

5. `fft_recognize_wave()`
   使用FFT识别信号的波形，无需输入参数，返回值为 `Waveform_Type` 类型。

### 使用案例
```cpp
#include "Adc/My_Adc.h"
#include "AdvancedMeasure/AdvancedMeasure.h"

My_Adc Adc(&hadc1 , &htim2);
AdvancedMeasure advanced_measure;

void Main()
{
    ...

    Adc.init(102400, 72000000).start();

    for (;;) {
        if (Adc.is_finished())
        {
            Adc.read();
            advanced_measure.init(Adc).filter(FIR);
            advanced_measure.read();
            advanced_measure.apply_windows().fft();
            printf("freq: %f\n", advanced_measure.get_freq());
            adc_finished = false;
            Adc.start();
        }
    }
}
```

## PwmMeasure 类
`PwmMeasure`类是一个用于测量PWM（脉冲宽度调制）信号的类，它继承自`SignalPeripheral`类。

### 构造函数
1. `PwmMeasure(TIM_HandleTypeDef* htim, uint8_t channel)`
   构造函数，初始化一个`PwmMeasure`对象。`htim`是用于PWM输入的定时器，`channel`是用于PWM的通道。

2 `init(uint32_t f_out, uint64_t f_in)`
   初始化PWM测量。`f_out` 是输出频率（采样率），`f_in` 是输入频率（定时器主频）。

3. `start(Pwm_Capture_Mode mode)`
   启动PWM测量。如果`mode`是`Pwm_Continuous_Capture`，则连续捕获Pwm ; 如果`mode`是`Pwm_Single_Capture`，则只捕获一次Pwm信号。**注意：该函数应该放在程序运行的循环区域**

4. `stop()`
   停止PWM测量。
   
5. `is_finished()`
   判断PWM是否读取完成一个脉冲，如果完成，将会置位为`ture`。

### 使用案例
```cpp
#include "Pwm/PwmMeasure.h"
#include "Pwm/My_Pwm.h"

My_Pwm Pwm(&htim3, TIM_CHANNEL_1);
PwmMeasure pm(&htim9, TIM_CHANNEL_1);

void Main()
{
    ...
    Pwm.init(1000, 72000000).start();
    pm.init(1000000, 144000000).start();

    for (;;) {
      if (pm.is_finished())
      {
         printf("freq: %f Hz\n", pm.get_freq());
         delay_ms(1000);
         pm.start();
      }
        ...
    }
}
```

## Gpio 类
`Gpio`类是一个用于控制STM32的GPIO（通用输入输出）的类，它继承自`BasePeripheral`类。

### 构造函数
1. `Gpio(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState)`
   构造函数，初始化一个`Gpio`对象。`GPIOx`是GPIO端口，`GPIO_Pin`是GPIO引脚，`PinState`是引脚状态。

2. `Gpio(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)`
   构造函数，初始化一个`Gpio`对象。`GPIOx`是GPIO端口，`GPIO_Pin`是GPIO引脚。

### 成员函数
1. `set()`
   设置GPIO状态为高电平。

2. `reset()`
   设置GPIO状态为低电平。

3. `toggle()`
   切换GPIO状态。

4. `read()`
   读取GPIO状态。

### 使用案例
```cpp
#include "Gpio/Gpio.h"

Gpio led(GPIOC, GPIO_PIN_13);

void Main()
{
    ...

    led.set();


    for (;;) {
        led.toggle();
        delay_ms(1000);
    }

    ...
}
```
