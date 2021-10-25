#include "stdint.h"
#include "C:/Keil/ARM/INC/TI/TM4C123/TM4C123GH6PM.h"
void SystemInit(){}
	
#define GPIO_PORTA_DATA_R 	(*((volatile unsigned long *)0x400253FC))	
#define GPIO_PORTA_DIR_R 		(*((volatile unsigned long *)0x40004400))
#define GPIO_PORTA_AFSEL_R	(*((volatile unsigned long *)0x40004420))
#define GPIO_PORTA_DEN_R	 	(*((volatile unsigned long *)0x4000451C))	
#define GPIO_PORTA_AMSEL_R 	(*((volatile unsigned long *)0x40004528))
#define GPIO_PORTA_PCTL_R 	(*((volatile unsigned long *)0x4000452C))	
#define SYSCTL_RCGC2_R			(*((volatile unsigned long *)0x400F3108))
	
void PortA_Init(void);

int main(void){}

void PortA_Init(void)
{
	volatile unsigned long delay;
	SYSCTL_RCGC2_R |= 0x00000001;				// 1) activate clock for Port A
	delay = SYSCTL_RCGC2_R;							// Allow time for clock to start	
																			// 2) no need to unlock PA2
	GPIO_PORTA_PCTL_R &= ~0x00000F00;		// 3) regular GPIO
	GPIO_PORTA_AMSEL_R &= ~0x04;				// 4) disable analog function on PA2
	GPIO_PORTA_DIR_R |= 0x04;						// 5) set direction	to output
	GPIO_PORTA_AFSEL_R &= ~0x04;				// 6) regular port function
	GPIO_PORTA_DEN_R |= 0x04;						// 7) enable digital port
}			

	