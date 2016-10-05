echo "linking.."

mkdir -p elf

arm-none-eabi-gcc -mcpu=cortex-m4 -mlittle-endian -mthumb -specs=nosys.specs -D Linker/STM32F401CE_FLASH.ld -Wl,--gc-sections Objects/system_stm32f4xx.o Objects/main.o startup_stm32f401xe.s -o elf/main.elf

arm-none-eabi-objcopy -O binary elf/main.elf main.hex

# Objects/stm32f4xx_gpio.o Objects/stm32f4xx_rcc.o