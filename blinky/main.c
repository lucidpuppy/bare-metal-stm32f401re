#include <stm32f401xe.h>

#define LED_PIN 5

void delay(unsigned int);

int main(void)
{
    RCC->AHB1ENR  |= RCC_AHB1ENR_GPIOAEN;
    GPIOA->MODER |= ( 0x01<<(LED_PIN << 1) );

    while(1) 
    {        
        GPIOA->BSRR = (1 << LED_PIN);
        delay(10); 
        GPIOA->BSRR = (1 << (LED_PIN + 16) );
        delay(10);
    }
}
	
void delay(unsigned time)
{
	while(time !=0) time --;
}
