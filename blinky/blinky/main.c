#include <stm32f4xx.h>

 
#define LED_PIN 5

#define LED_ON() GPIOA->BSRR |= (1 << 5)
#define LED_OFF() GPIOA->BSRR |= (1 << 21)
 

void delay(uint32_t);


int main()
{
													 /* Enbale GPIOA clock */
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

	GPIOA->MODER |= (1 << (LED_PIN << 1));			/* Configure GPIOA pin 5 as output */		
	
	GPIOA->OSPEEDR |= (3 << (LED_PIN << 1));		/* Configure GPIOA pin 5 in max speed */
 
													/* Turn on the LED */
	
	while(1)
		{
			LED_ON();
			delay(2000);
			LED_OFF();
			delay(2000);
		}

	return 0;
}

void delay(uint32_t t)
{
	while(t!=0) t--;
}