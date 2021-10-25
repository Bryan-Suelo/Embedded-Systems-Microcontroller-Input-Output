#include "stdint.h"
#include "C:/Keil/ARM/INC/TI/TM4C123/TM4C123GH6PM.h"
void SystemInit(){}

/* 1. Pre-Processor directives section */	
#define GPIO_PORTF_DATA_R (*((volatile unsigned long *)0x400253FC)) // Datasheet 0x40025000
#define GPIO_PORTF_DIR_R (*((volatile unsigned long *)0x40025400))
#define GPIO_PORTF_AFSEL_R (*((volatile unsigned long *)0x40025420))
#define GPIO_PORTF_PUR_R (*((volatile unsigned long *)0x40025510))
#define GPIO_PORTF_DEN_R (*((volatile unsigned long *)0x4002551C))
#define GPIO_PORTF_LOCK_R (*((volatile unsigned long *)0x40025520))
#define GPIO_PORTF_CR_R (*((volatile unsigned long *)0x40025524))
#define GPIO_PORTF_AMSEL_R (*((volatile unsigned long *)0x40025528))
#define GPIO_PORTF_PCTL_R (*((volatile unsigned long *)0x4002552C))
#define SYSCTL_RCG2_R	(*((volatile unsigned long *)0x400FE108))

/* 2. Declarations Section */
unsigned long In;
unsigned long Out;
// Function prototypes
void PortF_Init(void);

/* 3. Subroutines Section*/
int main (void)
{
	PortF_Init(); // Call initialization of port FP4 PF2
	while(1)
	{
		In = GPIO_PORTF_DATA_R&0x10;  // Read PF4 into In
		In = In>>2;			          // Shift into position of PF2		
		GPIO_PORTF_DATA_R = In;      // write output to PF2
	}
}

void PortF_Init(void)
{
	volatile unsigned long delay;
	SYSCTL_RCG2_R |= 0x00000020;	  // 1) F clock
	delay = SYSCTL_RCG2_R;				  // delay
	GPIO_PORTF_LOCK_R = 0x4C4F434B; // 2) unlock PortF PF0
	GPIO_PORTF_CR_R = 0x1F;					// allow changes to PF4-0
	GPIO_PORTF_AMSEL_R = 0x00;			// 3) disable analog function
	GPIO_PORTF_PCTL_R = 0x00000000;	// 4) GPIO clear bit PCTL
	GPIO_PORTF_DIR_R = 0X0E;				// 5) PF4, PF0 input, PF3, PF2, PF1 output
	GPIO_PORTF_AFSEL_R = 0x00;			// 6) no alternate function
	GPIO_PORTF_PUR_R = 0x11;				// enable pull up resistors on PF4, PF0
	GPIO_PORTF_DEN_R = 0x1F;				// 7) enable digital pins PF4-PF0
}
