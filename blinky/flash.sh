echo "configuring openocd for stm32f401re nucleo.."

openocd -f interface/stlink-v2.cfg -f board/st_nucleo_f401re.cfg