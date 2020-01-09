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
It is alternately called serial peripheral interface (**SPI**). It is used to interface medium-speed I/O devices. In this book, we will use it to interface a graphics display. We could use SSI to interface a digital to analog converter (DAC) or a secure digital card (SDC).

* **I<sup>2</sup>C** (Inter-integrated circuit)
Simple I/O bus that we will use to interface low speed peripheral devices. Input capture and output compare will be used to create periodic interrupts and measure period, pulse width, phase, and frequency.

* **Timer** - Periodic interrupts, input capture, and output compare

* **PWM** - (Pulse width modulation)
Its outputs will be used to apply variable power to motor interfaces. In a typical motor controller, input capture measures rotational speed, and PWM controls power. A PWM output can also be used to create a DAC.

* **ADC** - Analog to digital converter, measure analog signals.
will be used to measure the amplitude of analog signals and will be important in data acquisition systems. The analog comparator takes two analog inputs and produces a digital output depending on which analog input is greater.

* **Analog Comparator** - Compare two analog signals

* **QEI** - Quadrature encoder interface
Can be used to interface a brushless DC motor.

* **USB** - Universal serial bus
This is a high-speed serial communication channel. 

* **Ethernet** - High-speed network
Can be used to bridge the microcontroller to the Internet or a local area network.

* **CAN** - Controller area network
It creates a high-speed communication channel between microcontrollers and is commonly found in automotive and other distributed control applications.

* **Mixed-signal** refers to a system with both analog and digital components. Notice how many I/O ports perform this analog-digital bridge: ADC, DAC, analog comparator, PWM, QEI, Input capture, and output compare.

