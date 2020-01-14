# Chapter 6 - Microcontroller Ports

## Introduction
### Overview of I/O ports
Exchange digital information with the external world is possible with parallel ports or GPIO. From the very beginning of a project, we must consider how the system will be tested.

The regular function of a pin is to perform parallel I/O. Most pins, however, have an alternative function. For example, some ports can be either regular parallel port pins or an asynchronous serial port called universal asynchronous receiver/transmitter (**UART**). 
Joint Test Action Group (**JTAG**), standardized as the IEEE 1149.1, is a standard test access port used to program and debug the microcontroller board. Each microcontroller uses five port pins for the JTAG interface.

I/O pins on microcontrollers have a wide range of alternative functions:
* **UART** (Universal asynchronous receiver/transmitter)
It can be used for serial communication between computers. It is asynchronous and allows for simultaneous communication in both directions. 

* **SSI** (Synchronous serial interface)
It is alternately called serial peripheral interface (**SPI**). It is used to interface medium-speed I/O devices. We could use SSI to interface a digital to analog converter (DAC) or a secure digital card (SDC).

* **I<sup>2</sup>C** (Inter-integrated circuit)
Simple I/O bus that we will use to interface low speed peripheral devices. Input capture and output compare will be used to create periodic interrupts and measure period, pulse width, phase, and frequency.

* **Timer** - Periodic interrupts, input capture, and output compare

* **PWM** - (Pulse width modulation)
Its outputs will be used to apply variable power to motor interfaces. In a typical motor controller, input capture measures rotational speed, and PWM controls power. A PWM output can also be used to create a DAC.

* **ADC** - Analog to digital converter
will be used to measure the amplitude of analog signals and will be important in data acquisition systems. 

* **Analog Comparator** - Compare two analog signals
Takes two analog inputs and produces a digital output depending on which analog input is greater.

* **QEI** - Quadrature encoder interface
Can be used to interface a brushless DC motor.

* **USB** - Universal serial bus
This is a high-speed serial communication channel. 

* **Ethernet** - High-speed network
Can be used to bridge the microcontroller to the Internet or a local area network.

* **CAN** - Controller area network
It creates a high-speed communication channel between microcontrollers and is commonly found in automotive and other distributed control applications.

* **Mixed-signal** refers to a system with both analog and digital components. Notice how many I/O ports perform this analog-digital bridge: ADC, DAC, analog comparator, PWM, QEI, Input capture, and output compare.

## Tiva TM4C123 LaunchPad I/O Pins 
### TM4C123 Block Diagram
There are two buses used for I/O. The digital I/O ports are connected to both the advanced peripheral bus and the advanced high-performance bus. 
Because of the multiple buses, the microcontroller can perform I/O bus cycles simultaneous with instruction fetches from flash ROM.

### Overview of Ports Lecture
An **input port** has the direction register bit at 0, meaning the software can only read the values on the **input pin**. An **output port** has the direction register bit at 1, meaning the software can read and write to the pin.

![](IOPort.jpg)

### LaunchPad Pins
Each pin has one configuration bit in the **GPIOAMSEL** register. Set this bit to connect the port pin to the ADC or analog comparator. 
Each pin also has four bits in the **GPIOPCTL** register, which is set to specify the alternative function for that pin (0 means regular I/O port). 

### LaunchPad External Hardware
Pins PA1 – PA0 create a serial port, which is linked through the debugger cable to the PC. The USB device interface uses PD4 and PD5.

The evaluation board has two switches and one 3-color LED. The switches are negative logic and will require activation of the internal pull-up resistors.
In particular, you will set bits 0 and 4 in ```GPIO_PORTF_PUR_R``` register. The LED interfaces on **PF3** – **PF1** are positive logic. To use the LED, make the **PF3** – **PF1** pins an output. 
To activate the **red** color, output a one to **PF1**. The **blue** color is on **PF2**, and the **green** color is controlled by **PF3**.

## Basic Concepts of Input and Output Ports
### Digital Circuits of an Input and Output Port
A parallel I/O port is a simple mechanism that allows the software to interact with external devices. It is called parallel because multiple signals can be accessed all at once. 

An **input port** - Allows the software to read external digital signals, is read only. That means a read cycle access from the port address returns the values existing on the inputs at that time.
In particular, the tristate driver will drive the input signals onto the data bus during a read cycle from the port address. A write cycle access to an input port usually produces no effect. The digital values existing on the input pins are copied into the microcontroller when the software executes a read from the port address.

![](Input_Port.jpg)

**Readable output port** - A write cycle to the port address will affect the values on the output pins. In particular, the microcontroller places information on the data bus and that information is clocked into the D flip-flops.

![](Output_Port.jpg)

### Digital Circuit of a Bidirectional I/O Pin
Microcontrollers use the concept of a direction register to determine whether a pin is an input (direction register bit is 0) or an output (direction register bit is 1).
**Initialization ritual** is a program executed during start up that initializes hardware and software. If the ritual software makes direction bit zero, the port behaves like a simple input, and if it makes the direction bit one, it becomes a readable output port.
Each digital port pin has a direction bit. This means some pins on a port may be inputs while others are outputs. The digital port pins on most microcontrollers are bidirectional.

![](Bidirectional_Port.jpg)

## I/O Programming and the Direction Register
### GPIO Registers
Direction register ```GPIO_PORTF_DIR_R``` specifies which pins are input and which are output. Individual port pins can be general purpose I/O (GPIO) or have an alternate function.
We will set bits in the alternate function register ```GPIO_PORTF_AFSEL_R``` when we wish to activate the alternate functions. For each I/O pin we wish to use whether GPIO or alternate function we must enable the digital circuits by setting the bit in the enable register ```GPIO_PORTF_DEN_R```. 
We use the data register ```GPIO_PORTF_DATA_R``` to perform input/output on the port. Conversely, we read and write the data register multiple times to perform input and output respectively during the running phase.

### Software to initialize Port F
To initialize an I/O port for general use, we perform eight steps.
1. Activate the clock for the port. ```SYSCTL_RCGC2_R```
2. Unlock the port; unlocking is needed only for pins PC3-0, PD7, PF0 on the LM4F and TM4C. ```GPIO_PORTF_LOCK_R = 0x4C4F434B``` 
3. Allow changes to unlock pins. ```GPIO_PORTF_CR_R```
4. Disable the analog function of the pin, because we will be using the pin for digital I/O. ```GPIO_PORTF_AMSEL_R```
5. Clear bits in the PCTL to select regular digital function. ```GPIO_PORTF_PCTL_R```
6. Set its direction register. Specify whether the pin is an input or an output by clearing or setting bits in the DIR register. ```GPIO_PORTF_DIR_R``` 
7. Clear bits in the alternate function register. ```GPIO_PORTF_AFSEL_R```
8. Enable the digital port. ```GPIO_PORTF_DEN_R```


It is necessary to add a short delay between activating the clock and accessing the port registers. The direction register specifies bit for bit whether the corresponding pins are input or output.