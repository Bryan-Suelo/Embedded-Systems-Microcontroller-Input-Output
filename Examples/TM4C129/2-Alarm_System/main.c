#include "tm4c1294ncpdt.h"
#include "stdbool.h"
#include "stdint.h"
#include "stdio.h"
void SystemInit(){}
	
#define GPIO_PORTL_DATA_R 			(*((volatile unsigned long *) 0x400620FC))
#define GPIO_PORTL_DIR_R 				(*((volatile unsigned long *) 0x40062400))
#define GPIO_PORTL_DEN_R 				(*((volatile unsigned long *) 0x4006251C))	
#define SYSTCL_PRGPIO_R         (*((volatile unsigned long *) 0x400FE608))	
	
volatile unsigned long arm;
volatile unsigned long sensor;

void PortL_init(void);
void delayms(unsigned long ms);

int main(void)
{
	PortL_init();
	while(1)
	{
		arm = GPIO_PORTL_DATA_R&0x01;
		sensor = GPIO_PORTL_DATA_R&0x06;
		GPIO_PORTL_DATA_R |= 0x08;
		if ((arm != 0x01)&&(sensor != 0x06))
		{
			GPIO_PORTL_DATA_R |= 0x08;
			delayms(100);
		}
		else
		{
			GPIO_PORTL_DATA_R &= ~0x08;
		}
	}
}

void PortL_init(void)
{
	SYSTCL_PRGPIO_R |= 0x0400;
	GPIO_PORTL_DIR_R = 0x08;
	//GPIO_PORTL_PUR_R = 0x07;
	GPIO_PORTL_DEN_R = 0x0F;
}	

void delayms(unsigned long ms)
{
	volatile unsigned long count;
	while (ms > 0)
	{
		count = 25000;
		while (count > 0)
		{
			count--; 
		}
		ms--;
	}
}
