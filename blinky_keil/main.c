#include <stm32f401xe.h>

#define LED_GPIO        GPIOA
#define LED_PIN         5

void delay(unsigned int);

int main(void)
	{
    RCC->AHB1ENR  |= RCC_AHB1ENR_GPIOAEN;
    LED_GPIO->MODER |= ( 0x01<<(LED_PIN << 1) );

    while(1) 
			{        
        LED_GPIO->BSRR = (1 << LED_PIN);
        delay(10); 
        LED_GPIO->BSRR = (1 << (LED_PIN+16) );
        delay(10);
      }
	}
	
void delay(unsigned time)
	{
    for (unsigned i=0; i<time; i++)
        for (volatile unsigned j=0; j<20000; j++);
	}
