#include "stdint.h"
#include "C:/Keil/ARM/INC/TI/TM4C123/TM4C123GH6PM.h"
void SystemInit(){}
	
#define GPIO_PORTE_DATA_R 		(*((volatile unsigned long *)0x400243FC))	
#define GPIO_PORTE_DIR_R 			(*((volatile unsigned long *)0x40024400))
#define GPIO_PORTE_AFSEL_R  	(*((volatile unsigned long *)0x40024420))
#define GPIO_PORTE_DEN_R  		(*((volatile unsigned long *)0x4002451C))	
#define GPIO_PORTE_AMSEL_R  	(*((volatile unsigned long *)0x40024528))		
#define GPIO_PORTE_PCTL_R  		(*((volatile unsigned long *)0x4002452C))		
#define SYSTCTL_RCGC2_R 			(*((volatile unsigned long *)0x400FE108))		

void PortE_Init(void);
void delayms(unsigned long ms);
void EnableInterrupts(void);
volatile unsigned long arm;
volatile unsigned long sensor;

int main(void)
{
	
	PortE_Init();
	arm = GPIO_PORTE_DATA_R&0x04;			// arm 0 if deactivated, 1 if deactivated
	sensor = GPIO_PORTE_DATA_R&0x03;	// 1 means ok, 0 means break in
	
	if ((arm == 0x04) && (sensor != 0x03))
	{
		GPIO_PORTE_DATA_R ^= 0x10;			// toggles output for alarm
		delayms(100);										// 100ms delay makes a 5Hz period
	}
	else
	{
		GPIO_PORTE_DATA_R &= ~0x10;			// LED off if activated
	}
}

void PortE_Init(void)
{
	volatile unsigned long delay;
	SYSTCTL_RCGC2_R |= 0x00000010;	 	// Port E clock
	delay = SYSTCTL_RCGC2_R;				 	// wait 3-5 bus cycles
	
	GPIO_PORTE_DIR_R |=	0x10;					// PE4 output
	GPIO_PORTE_DIR_R &= ~0x07;				// PE2,1,0 input
	GPIO_PORTE_AFSEL_R &= ~0x17;			// not alternate
	GPIO_PORTE_AMSEL_R &= ~0x17;			// no analog	
	GPIO_PORTE_PCTL_R &= 0x000F0FFF;	// bit for PE4, PE2, PE1, PE0
	GPIO_PORTE_DEN_R |= 0x17;					// enable PE4, PE2, PE1, PE0
}	

void delayms(unsigned long ms)
{
	unsigned long count;
	while (ms > 0)
	{
		count = 20000;					// Delay while there are still ms to delay
		while (count > 0)				// number of counts to delay 1ms at 80MHz
		{
			count --;
		}												// This while loop takes approximately 3 cycles
		ms --;
	}
}

