#include "stdint.h"
#include "C:/Keil/ARM/INC/TI/TM4C123/TM4C123GH6PM.h"
void SystemInit(){}

#define GPIO_PORTA_DATA_R 		(*((volatile unsigned long *)0x400043FC)) // Datasheet 0x40004000
#define GPIO_PORTA_DIR_R			(*((volatile unsigned long *)0x40004400))
#define GPIO_PORTA_AFSEL_R		(*((volatile unsigned long *)0x40004420))
#define GPIO_PORTA_DEN_R			(*((volatile unsigned long *)0x4000451C))	
#define GPIO_PORTA_AMSEL_R		(*((volatile unsigned long *)0x40004528))
#define GPIO_PORTA_PCTL_R			(*((volatile unsigned long *)0x4000452C))
#define	SYSCTL_RCGC2_R				(*((volatile unsigned long *)0x400FE108))
	
void PortA_Init(void);
	
int main(void){}
	
void PortA_Init(void)
{
	volatile unsigned long delay;
	SYSCTL_RCGC2_R |= 0x00000001;			// 1) activate clock for Port A
	delay = SYSCTL_RCGC2_R;						// allow time for clock to start
																		// 2) no need to unlock GPIO Port A
	GPIO_PORTA_AMSEL_R &= ~0x20;			// 3) disable analog on PA5
	GPIO_PORTA_PCTL_R &= 0x00F00000;	// 4) PCTL GPIO on PA5
	GPIO_PORTA_DIR_R &= ~0x20;				// 5) direction PA5 input
	GPIO_PORTA_AFSEL_R &= ~0x20;			// 6) PA5 regular port function
	GPIO_PORTA_DEN_R  |= 0x20;				// 7) enable PA5 digital port
}	

unsigned long Switch_Input(void)
{
	return (GPIO_PORTA_DATA_R&0x20);	// 0x20(pressed) or 0(not pressed) 
}