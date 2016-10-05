#!/bin/bash
clear
echo "compiling.."

mkdir -p Objects

arm-none-eabi-gcc -Wall -mcpu=cortex-m4 -mlittle-endian -mthumb -I Include/ -I Inc/ -D STM32F401xE -Os -c startup_stm32f401xe.s -o Objects/startup_stm32f401xe.o

arm-none-eabi-gcc -Wall -mcpu=cortex-m4 -mlittle-endian -mthumb -I Include/ -I Inc/ -D STM32F401xE -Os -c system_stm32f4xx.c -o Objects/system_stm32f4xx.o

# arm-none-eabi-gcc -Wall -mcpu=cortex-m4 -mlittle-endian -mthumb -I Include/ -I Inc/ -DSTM32F401xE -Os -c stm32f4xx_rcc.c -o Objects/stm32f4xx_rcc.o

# arm-none-eabi-gcc -Wall -mcpu=cortex-m4 -mlittle-endian -mthumb -I Include/ -I Inc/ -DSTM32F401xE -Os -c stm32f4xx_gpio.c -o Objects/stm32f4xx_gpio.o

arm-none-eabi-gcc -Wall -mcpu=cortex-m4 -mlittle-endian -mthumb -I Include/ -I Inc/ -D STM32F401xE -Os -c main.c -o Objects/main.o