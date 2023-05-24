# STM32嵌入式程序设计C++实现

# 使用说明文档

### 1. 引入库
在你的代码中引入库：
```cpp
#include "Platform.h"
```
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
    if (adc_finished) {
        Adc.read();
        adc_finished = false;
        Adc.start();
    }
}
```
这里，`adc_finished`是一个全局标志，当ADC读取完成时，会被设置为`true`。

## My_Adc 类
### 成员函数
1. `init(uint32_t f_out, uint64_t f_in)`
   初始化ADC。`f_out` 是输出频率，`f_in` 是输入频率。

2. `start()`
   启动ADC。

3. `stop()`
   停止ADC。

4. `read()`
   读取ADC的数据，并打印到控制台。
### 使用案例
```cpp
My_Adc Adc(&hadc1 , &htim2);

void Main()
{
    .....

    Adc.init(102400, 72000000).start();

    for (;;) {

        if (adc_finished)
        {
            Adc.read();
            adc_finished = false;
            Adc.start();
        }

    }

}

```













