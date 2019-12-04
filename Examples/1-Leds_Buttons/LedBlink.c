#include "tm4c1294ncpdt.h"
#include "stdbool.h"
#include "stdint.h"

// Defining PortF Initializers
#define GPIO_PORTF_DATA_R       (*((volatile unsigned long *)0x4005D044))
#define GPIO_PORTF_DIR_R        (*((volatile unsigned long *)0x4005D400))
#define GPIO_PORTF_DEN_R        (*((volatile unsigned long *)0x4005D51C))
// Defining PortJ Initializers
#define GPIO_PORTJ_DATA_R       (*((volatile unsigned long *)0x400603FC))
#define GPIO_PORTJ_DIR_R        (*((volatile unsigned long *)0x40060400))
#define GPIO_PORTJ_PUR_R        (*((volatile unsigned long *)0x40060510))
#define GPIO_PORTJ_DEN_R        (*((volatile unsigned long *)0x4006051C))
// Defining PortN Initializers
#define GPIO_PORTN_DATA_R       (*((volatile unsigned long *)0x4006400C))
#define GPIO_PORTN_DIR_R        (*((volatile unsigned long *)0x40064400))
#define GPIO_PORTN_DEN_R        (*((volatile unsigned long *)0x4006451C))
// Clock Register for Ports
#define SYSTCL_PRGPIO_R         (*((volatile unsigned long *)0x400FE608))

//Global Variables
unsigned long SW1; // input from PJ0
unsigned long SW2; // input from PJ1
unsigned long SW3; // input from PJ1
unsigned long Out; // outputs to PN0, PN1, PF4 and PF0

// Functions
void PortF_Init(void);
void PortJ_Init(void);
void PortN_Init(void);

// Subroutines
int main(void)
{
    PortF_Init();
    PortJ_Init();
    PortN_Init();

    while(1)
    {
        SW1 = GPIO_PORTJ_DATA_R&0x01;       // read PJ1 into SW1
        SW2 = GPIO_PORTJ_DATA_R&0x02;        // read PJ0 into SW2
        SW3 = GPIO_PORTJ_DATA_R&0x03;

            if (SW2 == 0x02)
            {
              GPIO_PORTF_DATA_R = 0x10;  
							//GPIO_PORTN_DATA_R = 0x02;    // Enciede PN0 D2
                
            }
            //Si se presiona el botón 2
            if (SW1 == 0x01)
            {
                //GPIO_PORTN_DATA_R = 0x01;    // Enciende PN1
                GPIO_PORTF_DATA_R = 0x01;
            }
        //Si se presiona el botón  1 y 2
            if (SW3 == 0x00)
            {
                GPIO_PORTF_DATA_R = 0x00;    // apaga los 4 leds
                //GPIO_PORTN_DATA_R = 0x00;
            }
        //Sino se presiona ningún botón
            if (SW3 == 0x03)
            {
                GPIO_PORTF_DATA_R = 0x11;    // enciende los 2 leds del puerto N
                //GPIO_PORTN_DATA_R = 0x00;
			}
	}
}


void PortF_Init(void)
{
    SYSTCL_PRGPIO_R |= 0x0020;
    GPIO_PORTF_DIR_R = 0x11;            // PF4,PF0 output
    GPIO_PORTF_DEN_R = 0x11;          // enable digital pins PF4-PF0
}

void PortJ_Init(void)
{
    SYSTCL_PRGPIO_R |= 0x0100;
    GPIO_PORTJ_DIR_R = 0x00;            // PJ0,PJ1 input
    GPIO_PORTJ_PUR_R = 0x03;          // enable pullup resistors
    GPIO_PORTJ_DEN_R = 0x03;          // enable digital pins PJ0,PJ1
}

void PortN_Init(void)
{
    SYSTCL_PRGPIO_R |= 0x1000;
    GPIO_PORTN_DIR_R = 0x03;            // PN0,PN1 output
    GPIO_PORTN_DEN_R = 0x03;          // enable digital pins PN0, PN1
}