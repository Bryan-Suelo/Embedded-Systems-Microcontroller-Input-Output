# C9 - Arrays and Functional Debugging

## Debugging Theory
### Intrusiveness
A **debugging instrument** is hardware or software used for the purpose of debugging. 
**Nonintrusiveness** is the characteristic or quality of a debugger that allows the software/hardware system to operate normally as if the debugger did not exist.
A debugging instrument is classified as **minimally intrusive** if it has a small but negligible effect on the system being debugged.
A **dump** is a debugging technique that records strategic information into memory.
**Stabilization** is process of fixing the inputs so that the system can be run over and over again yielding repeatable outputs.

### Black-box, White-box Testing
**Black-box testing** is simply observing the inputs and outputs without looking inside. Black-box testing has an important place in debugging a module for its functionality.
**White-box testing** allows you to control and observe the internal workings of a system. A common mistake made by new engineers is to just perform black box testing.

A print statement is a common example of a debugging instrument. Using the editor, one adds print statements to the code that either verify proper operation or illustrate the programming errors.

Although using print statements for debugging is widely used in software development, we will avoid using print output when debugging embedded systems because

1. Outputting to a display device takes a 1ms or more, so print statements are usually intrusive.
2. Most embedded systems do not have a display device onto which you can print.
3. If an embedded system has a display it is typically dedicated for the operation of the system and not available for displaying debugging information.

## SysTick Timer
### Working of the Systick Timer
The SysTick timer is simple mechanism we can use to measure and control time. It is a 24-bit timer such that CURRENT counts down every bus cycle. After CURRENT counts to 0, it is automatically reloaded with the RELOAD value and continues to count.

### SysTick Initialization
SysTick is a simple counter that we can use to create time delays and generate periodic interrupts. 
The basis of SysTick is a 24-bit down counter, called **CURRENT**, which counts down at the bus clock frequency.

There are four steps involved in the initialization of the SysTick timer. 
1. **ENABLE** bit to turn off SysTick during initialization.
2. Set the **RELOAD** register.
3. Write any value to the **NVIC_ST_CURRENT_R** value to clear the counter.
4. Write the desired mode to the control register, **NVIC_ST_CTRL_R**.

Without activating the **phase-lock-loop** (PLL), our TM4C123 LaunchPad will run at 16 MHz, meaning the SysTick counter decrements every 62.5 ns.
With the RELOAD set to **0x00FFFFFF**, SysTick behaves like a clock. Every t time it counts down by one, and when it reaches zero, the counter is reloaded with 0x00FFFFFF and it continues to count.

```c
#define NVIC_ST_CTRL_R      (*((volatile unsigned long *)0xE000E010))
#define NVIC_ST_RELOAD_R    (*((volatile unsigned long *)0xE000E014))
#define NVIC_ST_CURRENT_R   (*((volatile unsigned long *)0xE000E018))
void SysTick_Init(void)
{
  NVIC_ST_CTRL_R = 0;              // 1) disable SysTick during setup
  NVIC_ST_RELOAD_R = 0x00FFFFFF;   // 2) maximum reload value
  NVIC_ST_CURRENT_R = 0;           // 3) any write to current clears it
  NVIC_ST_CTRL_R = 0x00000005;     // 4) enable SysTick with core clock
}
```

### Using SysTick to Determine Time
```c
unsigned long Now;      // 24-bit time at this call (12.5ns)
unsigned long Last;     // 24-bit time at previous call (12.5ns)
unsigned long Elapsed;  // 24-bit time between calls (12.5ns)

void Action(void) 
{  // function under test
  Now = NVIC_ST_CURRENT_R;         // what time is it now?
  Elapsed = (Last-Now)&0x00FFFFFF; // 24-bit difference
  Last = Now;                      // set up for next...
}
```

Assume the system calls the function **Action()** over and over. 
The variable **Now** is the time (in 12.5ns units) when the function has been called. 
The variable **Last** is the time (also in 12.5ns units) when the function was called previously. 
To measure **elapsed** time, we perform a time subtraction. 

Since the SysTick counts down we subtract Last-Now. Since the time is only 24 bits and the software variables are 32 bits we **“and”** with **0x00FFFFFF** to create a 24-bit difference.

## Arrays
An array is a collection of data elements where each element is of the same size and type. Recording in an array will be a minimally intrusive debugging technique.

One of the simplest and fastest places to store data is in RAM memory. The TM4C123 has 32 kibibytes of RAM, and we can use it to store temporary data. If the information is a constant, and we know its values at compile time, we can place the data in ROM. The TM4C123 has 256 kibibytes of flash ROM, and we can use it to store constant data.

**Random access** means one can read and write any element in any order. An indexed data structure has elements of the same size and can be accessed knowing the name of the structure, the size of each element, and the element number. In C, we use the syntax [] to access an indexed structure. Arrays, matrices, and tables are examples of indexed structures available in C.

**Sequential access** means one reads and writes the elements in order. Pointers are usually employed in these types of data structures. Strings, linked-lists, stacks, queues, and trees are examples of sequential structures.

An **array** is made of elements of equal precision and allows random access. The **precision** is the size of each element. Typically, precision is expressed in bits or bytes. The **length** is the number of elements. The **origin** is the index of the first element. A data structure with the first element existing at index zero is called zero-origin indexing. 

### Array examples
Assume there are 50 students in the class, and their grades on the first exam are stored in an array. Write a function that calculates and returns class average. Write a second function that finds and returns the highest grade on the exam.
```c++
My class Average(Grades,50);
```
```c++
unsigned long Grades[50];

unsigned long Average(unsigned long class[], unsigned long size)
{
    unsigned long sum, i;
    sum = 0;

    for (i=0; i<size; i++)
    {
        sum = sum + class[i]; // add up all values
    }
    return (sum/size);
}
```

Find the Max score in an array of student scores
```c++
HighestsScore = Max(Grades,50);
```
```c++
unsigned long Grades[50];

unsigned long Max(unsigned long class[], unsigned long size)
{
    unsigned long largest, i;
    largest = 0;        // smallest possible value

    for (i=0, i<size; i++)
    {
        if (class[i] > largest)
        {
            largest = class[i];
        }
    }
    return (largest);
}
```

## Strings
### Strings
A string is simply an array of ASCII characters.

### Strings Examples
```c++
jFound = jcount(Name);
```
```c++
char Name[] = "John Smith";

unsigned long jcount(char str[])
{
    unsigned long count, i;
    count = 0;
    i = 0;
    while (str[i] != 0)
    {
        if (str[i] == 'j')
        {
            count++;
        }
        i++;
    }
    return(count);
}
```

## Functional Debugging
### Stabilization
Having **control** over events means we can create and recreate input conditions for our system under test.
**Observability** means we can select when and what we observe, and do in such a way that the data collection is minimally intrusive.

**Functional debugging** involves the verification of input/output parameters. Functional debugging is a static process where inputs are supplied, the system is run, and the outputs are compared against the expected results.

The first step of debugging is to **stabilize** the system. In the debugging context, we stabilize the problem by creating a test routine that fixes (or stabilizes) all the inputs. In this way, we can reproduce the exact inputs over and over again. Stabilization is an effective approach to debugging because we can control exactly what software is being executed.

To stabilize the system we define a fixed set of inputs to test, run the system on these inputs, and record the outputs. Debugging is a process of finding patterns in the differences between recorded behavior and expected results. The advantage of modular programming is that we can perform modular debugging. We make a list of modules that might be causing the bug.

### Single Stepping, Breakpoint
The debugger provides three stepping commands **Step**,  **StepOver** and **StepOut** commands. 
* **Step** is the usual execute one assembly instruction. However, when debugging C we can also execute one line of C. 
* **StepOver** will execute one assembly instruction, unless that instruction is a subroutine call, in which case the debugger will execute the entire subroutine and stop at the instruction following the subroutine call. 
* **StepOut** assumes the execution has already entered a subroutine, and will finish execution of the subroutine and stop at the instruction following the subroutine call.

A **breakpoint** is a mechanism to tag places in our software, which when executed will cause the software to stop. Normally, you can break on any line of your program.

### Instrumentation: Print Statements
The use of **print statements** is a popular and effective means for functional debugging. One difficulty with print statements in embedded systems is that a standard “printer” may not be available. Another problem with printing is that most embedded systems involve time-dependent interactions with its external environment. 

The print statement itself may be so slow, that the debugging process itself causes the system to fail. In this regard, the print statement is usually intrusive. 

There are three limitations of using print statements to debug.
* Many embedded systems do not have a standard output device onto which we could stream debugging information. 
* They can significantly slow down the execution speed in real-time systems. The bandwidth of the print functions often cannot keep pace with the real-time execution.

### Instrumentation: Dump into Array with/without Filtering
Add a debugging instrument that **dumps** strategic information into an array at run time. We can then observe the contents of the array at a later time. 

One problem with dumps is that they can generate a tremendous amount of information. If you suspect a certain situation is causing the error, you can add a filter to the instrument. A **filter** is a software/hardware condition that must be true in order to place data into the array. In this situation, if we suspect the error occurs when another variable gets large, we could add a filter that saves in the array only when the variable is above a certain value.

#### Example
Instrumenting a dump
```c++
#define SIZE 20
unsigned char HappyBuf[SIZE]; // 8 bit variables
unsigned char SadBuf[SIZE];
unsigned long Cnt;
unsigned long sad;

void Save(void)
{
    Cnt = 0;
    sad = 0;
    if (sad > 100)
    {
        if (Cnt < size) // make sure there is room
        {
        HappyBuf[Cnt] = happy; // record happy
        SadBuf[Cnt] = sad; // record sad
        Cnt++;
        }
    }  
}
```
