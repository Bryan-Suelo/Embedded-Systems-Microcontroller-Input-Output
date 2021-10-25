# C10 - Finite State Machine

## Phase-Lock-Lock
### Activating the PLL
Normally, the execution speed of a microcontroller is determined by an external crystal. 
Most microcontrollers include a phase-lock-loop (PLL) that allows the software to adjust the execution speed of the computer. Typically, the choice of frequency involves the tradeoff between software execution speed and electrical power. 
* Slowing down the bus clock will require less power to operate and generate less heat. 
* Speeding up the bus clock obviously allows for more calculations per second, at the cost of requiring more power to operate and generating more heat.

The internal oscillator is significantly less precise than the crystal, but it requires less power and does not need an external crystal. If we wish to have accurate control of time, we will activate the external crystal (called the main oscillator) and use the PLL to select the desired bus speed.

There are two ways to activate the PLL. 
* Call a library function.
* Access the clock registers directly. 

In general, using library functions creates a better design because the solution will be more stable (less bugs) and will be more portable (easier to switch microcontrollers). 

### Activating the PLL, Low Power Design
0. Use **RCC2** because it provides more options.
1. The first step is to set the **BYPASS2** (bit 11) bit. At this point the PLL is bypassed and there is no system clock divider.
2. The second step is to specify the crystal frequency in the four **XTAL** bits. The **OSCSRC2** bits are cleared to select the main oscillator as the oscillator clock source.
3. The third step is to clear **PWRDN2** (bit 13) to activate the PLL.
4. Configure and enable the clock divider using the 7-bit **SYSDIV2** field. If the 7-bit SYSDIV2 is n, then the clock will be divided by **n+1**. To get the desired 80 MHz from the 400 MHz PLL, we need to divide by 5. So, we place a 4 into the **SYSDIV2** field.
5. Wait for the PLL to stabilize by waiting for **PLLRIS** (bit 6) in the **SYSCTL_RIS_R** to become high.
6. Connect/enable the PLL by clearing the **BYPASS2** bit. To modify this program to operate on other microcontrollers, you will need to change the crystal frequency and the system clock divider.

```c++
void PLL_Init(void)
{
  // 0) Use RCC2
  SYSCTL_RCC2_R |=  0x80000000;  // USERCC2
  // 1) bypass PLL while initializing
  SYSCTL_RCC2_R |=  0x00000800;  // BYPASS2, PLL bypass
  // 2) select the crystal value and oscillator source
  SYSCTL_RCC_R = (SYSCTL_RCC_R &~0x000007C0)   // clear XTAL field, bits 10-6
                 + 0x00000540;   // 10101, configure for 16 MHz crystal
  SYSCTL_RCC2_R &= ~0x00000070;  // configure for main oscillator source
  // 3) activate PLL by clearing PWRDN
  SYSCTL_RCC2_R &= ~0x00002000;
  // 4) set the desired system divider
  SYSCTL_RCC2_R |= 0x40000000;   // use 400 MHz PLL
  SYSCTL_RCC2_R = (SYSCTL_RCC2_R&~ 0x1FC00000)  // clear system clock divider
                  + (4<<22);      // configure for 80 MHz clock
  // 5) wait for the PLL to lock by polling PLLLRIS
  while((SYSCTL_RIS_R&0x00000040)==0){};  // wait for PLLRIS bit
  // 6) enable use of PLL by clearing BYPASS
  SYSCTL_RCC2_R &= ~0x00000800;
}
```

## Accurate Time Delays Using SysTick
### Implementing Time Delays
The accuracy of SysTick depends on the accuracy of the clock. When we use the PLL to derive a bus clock based on the 16 MHz crystal, the time measured or generated using SysTick will be very accurate.

The **RELOAD** register is set to the number of bus cycles one wishes to wait. Writing to **CURRENT** will clear the counter and will clear the count flag (bit 16) of the **CTRL** register. 

After SysTick has been decremented delay times, the count flag will be set and the while loop will terminate. Since SysTick is only 24 bits, the maximum time one can wait with SysTick_Wait is 2<sup>24</sup> * 12.5ns, which is about 200 ms. 
To provide longer delays, the function **SysTick_Wait10ms** calls the function SysTick_Wait repeatedly. Notice that 800,000*12.5ns is 10ms.

## Abstraction
### Introduction to FSMs
An FSM can be described by five things that capture the behavior of the system we want to design:

1. Set of inputs the system takes in Input ```∈ {In0, In1, ...}```
2. Set of outputs the system produces Output ```∈ {Out0, Out1...}```
3. Set of states one can find the system in CurrentState ```∈ {S0, S1,...}```
4. The State Transition Graph (STG), which tells us what causes the system to move state to another,  ```NextState= f(CurrentState ,Input)```
5. Output determination, which tells us what is the corresponding  in each state, ```Output = g(CurrentState )```

### Introduction to structures
In programming an FSM we will use a "structure" to encapsulate the behaviour corresponding to each state. 
An array only allows us to store multiple values of the **same** data type, we will need something different than an array.  In C, such a composite store is called a struct, which allows one to combine multiple elements of different data types into one entity. We will also see how users can create new data types with **typedef**.

### struct and typedef
A **structure** has elements with different data types and/or precisions. In C, we use **struct** to define a structure.
The **const** modifier causes the structure to be allocated in ROM. Without the const, the C compiler will place the structure in RAM, allowing it to be dynamically changed.

```c++
struct player{
  unsigned char Xpos;     // first element
  unsigned char Ypos;     // second element
  unsigned short Score;   // third element
};
typedef struct player playerType;
```
We can allocate a variable called Sprite of this type, which will occupy four bytes (one each for Xpos and Ypos and two for score) in RAM, we can access the individual attributes of this variable using the syntax name.element:
```c++
playerType Sprite;
Sprite.Xpos = 10;
Sprite.Ypos = 20;
Sprite.Score = 12000;
```

## Finite State Machines with Indexed structures
### Designing a FSM
Software **abstraction** allows us to define a complex problem with a set of basic abstract principles. If we can construct our software system using these abstract building blocks, then we have a better understanding of both the problem and its solution. This is because we can separate what we are doing (policies) from the details of how we are getting it done (mechanisms). This separation also makes it easier to optimize. 
Abstraction provides  a proof of correct function and simplifies both extensions and customization.

The abstract principles of FSM development are the inputs, outputs, states, and state transitions. The FSM state graph defines the time-dependent relationship between its inputs and outputs. If we can take a complex problem and map it into a FSM model, then we can solve it with simple FSM software tools. Further, our FSM software implementation will be easy to understand, debug, and modify. 

Let's deﬁne what are the essential elements that constitute an FSM. A Finite Statement Machine can be described by these ﬁve essential elements:

1. A ﬁnite set of states that you can ﬁnd the system in. One of these states has to be identiﬁed as the initial state
2. A ﬁnite set of external inputs to the system
3. A ﬁnite set of external outputs that the system generates
4. An explicit speciﬁcation of all state transitions. That is, for every state, what happens (as in, which state will the system transition to) when you are in that state and a speciﬁc input occurs?
5. An explicit speciﬁcation of how the outputs are determined. That is, when does a speciﬁc output get generated?

A State Transition Graph (**STG**) has nodes and edges.
* **nodes** relate to the states of the FSM and the edges represent the transitions from one state to another when a particular input is received.
*  **Edges** are accordingly labeled with the input that caused the transition. 

The output can also be captured in the Graph. Note that a FSM where the output is only dependent on the current state and not the input is called a **Moore FSM**.  FSMs where the output is dependent on both the current state and the input are called **Mealy FSMs**.

The FSM controller employs a well-defined model or framework with which we solve our problem. STG will be specified using either a linked or table data structure. An **important aspect** of this method is to create a 1-1 mapping from the STG into the data structure. 
The three advantages of this abstraction are: 
* it can be faster to develop because many of the building blocks preexist;  
* it is easier to debug (prove correct) because it separates conceptual issues from implementation;
* it is easier to change. 

The execution of a **Moore FSM** repeats this sequence over and over:
* Perform output, which depends on the current state
* Wait a prescribed amount of time (optional state dwell time)
* Input
* Go to next state, which depends on the input and the current state

The execution of a **Mealy FSM** repeats this sequence over and over:
* Wait a prescribed amount of time (optional)
* Input
* Perform output, which depends on the input and the current state
* Go to next state, which depends on the input and the current state 

A **linked structure** consists of multiple identically-structured nodes. Each node of the linked structure defines one state. One or more of the entries in the node is a link to other nodes.

## Stepper motors
### Simple Stepper motor
A motor can be evaluated in terms of its maximum speed (**RPM**), its torque (**N-m**), and the efficiency in which it translates electrical power into mechanical power. Sometimes however, we wish to use a motor to control the rotational position (**θ=motor shaft angle**) rather than to control the rotational speed (**ω=dθ/dt**). 