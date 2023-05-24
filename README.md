# STM32嵌入式程序设计C++实现

# 使用说明文档

### 1. 引入库
在你的代码中引入库：
```cpp
#include "Platform.h"
```
### 2. 图形化配置
使用STM32CubeMX进行图形化配置
### 3. 创建对象
创建一个My_Adc的对象。 例如：
```cpp
My_Adc Adc(&hadc1 , &htim2);
```
这里，`&hadc1`和 `&htim2` 是你在STM32CubeMX中配置的ADC和TIM的句柄。
### 4. 初始化ADC采样率和定时器的主频
在你的主函数中，使用init()函数初始化My_Adc对象。例如：
```cpp
Adc.init(102400, 72000000);
```
这里，`102400` 是ADC采样率，`72000000` 是触发ADC的定时器的主频。
### 5. 启动和读取
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

## 成员函数
1. init(uint32_t f_out, uint64_t f_in)
   初始化ADC。f_out 是输出频率，f_in 是输入频率。

2. start()
   启动ADC。

3. stop()
   停止ADC。

4. read()
   读取ADC的数据，并打印到控制台。

注意
这个库是针对STM32微控制器编写的，使用之前需要先用STM32CubeMX进行硬件配置。













