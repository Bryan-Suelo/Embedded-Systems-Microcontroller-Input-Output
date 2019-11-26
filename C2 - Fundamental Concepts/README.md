# **Chapter 2 - Fundamental Concepts**

## **Binary Number and Systems**

### Binary Representation
#### Decimal number
* Place is a power of 10.
* Values are selected from set {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}.
* A decimal number is simply a combination of its digits multiplied by powers of 10.
#### Binary number
* Place is a power of 2.
* The value is selected from the set {0, 1}.
* A binary number is simply a combination of its digits multiplied by powers of 2. 
* The powers of 2 are 1, 2, 4, 8, 16, ...
#### Example
* Decimal number

> Convert: (4723)<sub>10</sub>

>(4 * 10<sup>^3</sup>) + (7 * 10<sup>^2</sup>) + (2 * 10<sup>^1</sup>) + (3 * 10<sup>^0</sup>) = 4000 + 700 + 20 + 3 = 4723 

* Binary Base

>Convert: (1101)<sub>2</sub>

>(1 * 2^<sup>3</sup>) + ( * 2^<sup>2</sup>) + (0 * 2^<sup>1</sup>) + (1 * 2^<sup>0</sup>) = 8 + 4 + 0 + 1 = 13

### Binary to decimal conversion
* An 8-bit number is called a **byte**
* A 16-bit number is called a **halfword**
* A 32-bit number is called a **word**

#### Binary to decimal converter
calculate a value by multipling each coefficient by its placeholder values and summing all of them together.

>Convert: (1101)<sub>2</sub>

>(1 *2^<sup>7</sup>) + (0 *2^<sup>6</sup>) + (1 *2^<sup>5</sup>) + (0 *2^<sup>4</sup>) + (0 *2^<sup>3</sup>) + (1 *2^<sup>2</sup>) + (0 *2^<sup>1</sup>) + (0 *2^<sup>0</sup>) = 128 + 0 + 32 + 0 + 0 + 4 + 0 + 0 = 164

#### Decimal to binary converter
Using consecutive divisions:
1. Start by dividing the decimal number by 2
2. Iteratively divide the result (the quotient) by 2 until the answer is 0

> Convert: 154

> 154/2 = 77      remainder = 0

> 77/2 = 38       remainder = 1

> continue dividing until 0 ...

> Binary equivalent 10011010

### Hexadecimal Notation 
* Use base 16
* Values are selected from set {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F}

>Example: 0x2A9F

>(2 *16^<sup>3</sup>) + (10 *16^<sup>2</sup>) + (9 *16^<sup>1</sup>) + (15 *16^<sup>0</sup>) = 8192 + 2560 + 144 + 15 = 164

Uses of Hex numbers:
* Addresses
* Contents of registers or memory

### Hexadecimal to binary conversion
**Nibble**: Is defined as 4 binary bits or one hexadecimal digit.

#### Convert binary to hexadecimal
1. Divide the binary number into rigth justified nibbles.
2. Convert each nibble into its corresponding hexadecimal digit.

> Binary: 0011 0110 1100 1101

> Hexadecimal: 0x36CD

#### Convert binary to hexadecimal
1. Convert each hexadecimal digit into its corresponding 4-digit binary nibble.
2. Combine the nibbles into a single binary number.

> Hexadecimal: 0xC56A

> Binary: 1100 0101 0110 1010

### Signed vs Unsigned numbers
#### Signed
* Range between -128 to 127
* Most significant bit is called **sign** bit
* Value 0/1 represent sign
* 0 positive numbers
* 1 positive numbers

> Negative --> (10001101)<sub>2</sub> = -128 + 8 + 4 +1 = -115 

> Postive --> (01000110)<sub>2</sub> = 64 + 4+ 2 = 70

#### Unsigned
* Range between 0 to 255
> (10001101) --> <sub>2</sub> = 128 + 8 + 4 + 1 = 141

### Precision and Bytes
**Precision** is the number of distinct or different values. 
* We express precision in alternatives, bytes, or binary bits.

**Alternatives** are defined as the total number of possibilities.
* An 8-bit digital to analog converter (DAC) can generate 256 different analog outputs. 
* An 8-bit analog to digital converter (ADC) can measure 256 different analog inputs.

A **byte** contains 8 bits where each bit is binary and has the value 1 or 0.

### Words and halfwords
**Word** contains 32 bits.
* There are 2<sup>32</sup> different unsigned 32-bit numbers. The smallest unsigned 32-bit number is 0 and the largest is 2<sup>32</sup>-1. This range is 0 to about 4 billion.

A **halfword** or **double byte** contains 16 bits.

### Fixed-Point numbers
We will use **fixed-point** numbers when we wish to express values in our computer that have noninteger values. A fixed-point number contains two parts. The first part is a variable **integer**, called I. The variable integer will be stored on the computer. The second part of a fixed-point number is a fixed constant, called the **resolution** Δ.

The value of the number is the product of the variable integer times the fixed constant. The integer may be signed or unsigned.

## Embedded Systems
### Microcontrollers
**Embedded** means hidden inside, so one can't see it.

**System** means multiple components interfaced together for a common purpose. Systems have structure, behavior, and interconnectivity.

Embedded system components:
* We use **ROM** for storing the software and fixed constant data
* **RAM** is used for storing temporary information.  
* **Flash EEPROM** is an electrically-erasable programmable ROM, because the information can easily be erased and reprogrammed. 

Microcontrollers incorporates:
* Processor
* RAM
* ROM
* I/O ports

### Properties of Embedded Systems
A **microcomputer** is a small computer that includes a processor, memory and I/O devices.

An **Interface** is defined as the hardware and software that combine to allow the computer to communicate with the external hardware.

A **device driver** is a set of software functions that facilitate the use of an I/O port.

In a **real-time** computer system, we can put an upper bound on the time required to perform the input-calculation-output sequence.

**Latency** is the response time when the new input information becomes available and when that information is processed. 

**Software maintenance** includes: verification of proper operation, updates, fixing bugs, adding features, extending to new applications, end user configurations.

Embedded systems properties:

* A microcontroller hidden inside.
* A dedicated purpose.
* Runs in real time.
* Input/output is important.
* High volume, low cost.
* Extremely reliable.
* Low power.
* Small size and weight.

## Introduction to Computers
### Computer organization
Von Neumann computer:
* Processor
* RAM
* ROM
* I/O

Harvad computer:
* Processor
* ROM
* ICode

### Architecture
**Software** is an ordered sequence of very specific instructions that are stored in memory, defining exactly what and when certain tasks are to be performed. It is a set of instructions, stored in memory, that are executed in a complicated but well-defined manner.

**Processor** executes the software by retrieving and interpreting these instructions one at a time.

A **microprocessor** is a small processor.

A **port** is a physical connection between the computer and its outside world.

A **bus** is a collection of wires used to pass information between modules.

The computer can store information in **RAM** by writing to it, or it can retrieve previously stored data by reading from it. RAMs are volatile; meaning if power is interrupted and restored the information in the RAM is lost. 

**ROM**s are nonvolatile; meaning if power is interrupted and restored the information in the ROM is retained. Some ROMs are programmed at the factory and can never be changed. A Programmable ROM (PROM) can be erased and reprogrammed by the user, but the erase/program sequence is typically 10000 times slower than the time to write data into a RAM.

### ARM Cortex M4
* It is a Harvard architecture because it has separate data and instruction buses.
* Has separate data and instruction buses.
* Instructions are fetched from flash ROM using the ICode bus.
* Data are exchanged with memory and I/O via the system bus interface.
* The nested vectored interrupt controller (NVIC) manages **interrupts**, which are hardware-triggered software functions.

## I/O ports
### Ports on the TM4C123
[Data sheet for the TM4C123 microcontroller](https://prod-edxapp.edx-cdn.org/assets/courseware/v1/fa65824471e6a00ada3317b79943c1ae/asset-v1:UTAustinX+UT.6.10x+3T2019+type@asset+block/tm4c123gh6pm.pdf)
* Chapter 10 General-Purpose Input/Outputs (GPIOS)
* Chapter 22 Pin DIagram

An **input port** is hardware on the microcontroller that allows information about the external world to be entered into the computer.

An **output port** sends information out to the external world.

An **interface** is defined as the collection of the I/O port, external electronics, physical devices, and the software, which combine to allow the computer to communicate with the external world.

I/O interfaces classification:
* **Parallel** - binary data are available simultaneously on a group of lines
* **Serial** - binary data are available one bit at a time on a single line
* **Analog** - data are encoded as an electrical voltage, current, or power
* **Time** - data are encoded as a period, frequency, pulse width, or phase shift

## CPU Registers 
### Registers
Processor - Instruction set architechture
* Instruccionts supported
* Data types
* Registers (General purpose, special)
* Addressing mode (How data is formed?)
* Memory address

## Assembly Language
### Syntax
Assembly language instructions have four fields separated by spaces or tabs.
 
 * **Label field** is optional and starts in the first column and is used to identify the position in memory of the current instruction. You must choose a unique name for each label. 
 * **Opcode field** specifies the processor command to execute. 
 * **Operand field** specifies where to find the data to execute the instruction. Thumb instructions have 0, 1, 2, 3, or 4 operands, separated by commas. 
 * **Comment field** is also optional and is ignored by the assembler, but it allows you to describe the software making it easier to understand.

 When describing assembly instructions we will use the following list of symbols

* **Ra Rd Rm Rn Rt** and **Rt2** represent registers
* **{Rd,}** represents an optional destination register
* **#imm12** represents a 12-bit constant, 0 to 4095
* **#imm16** represents a 16-bit constant, 0 to 65535
* **operand2** represents the flexible second operand
* **{cond}** represents an optional logical condition
* **{type}** encloses an optional data type
* **{S}** is an optional specification that this instruction sets the condition code bits
* **Rm {, shift}** specifies an optional shift on Rm
* **Rn {, #offset}** specifies an optional offset to Rn

The assembly source code is a text file (with Windows file extension .s) containing a list of instructions.

The **assembler** translates assembly source code into **object code**, which are the machine instructions executed by the processor. All object code is halfword-aligned.

The **listing** is a text file containing a mixture of the object code generated by the assembler together with our original source code.

```assembly
Address    Object code Label Opcode Operand    Comment
0x000005E2 F04F0164  Func MOV   R1,#0x64    ; R1=100
0x000005E6 FB00F001       MUL   R0,R0,R1    ; R0=100*input
0x000005EA F100000A       ADD   R0,R0,#0x0A ; R0=100*input+10
0x000005EE 4770           BX    LR          ; return 100*input+10
```

When we **build** a project all files are assembled or compiled then linked together.

The **linker** decides exactly where in memory everything will be.

### Adressing modes and operands
**Addressing mode** - is the format the instruction uses to specify the memory location to read or write data. The addressing mode is associated more specifically with the operands, and a single instruction could exercise multiple addressing modes for each of the operands. All instructions begin by fetching the machine instruction (op code and operand) pointed to by the PC.
```assembly
ADD R1, R2 ; R1 + R2 
```

**Pointer** or **Index** register - A register that contains the address or the location of the data.

**Indexed addressing** mode uses a register pointer to access memory. The addressing mode that uses the PC as the pointer is called **PC-relative** addressing mode.

The **MOV** instruction will move data within the processor without accessing memory. 

The **LDR** instruction will read a 32-bit word from memory and place the data in a register.

**Register** - Most instructions operate on the registers. In general, data flows towards the op code (right to left). In other words, the register closest to the op code gets the result of the operation.
```assembly
    MOV   R2,#100      ; R2=100, immediate addressing
    LDR   R2,[R1]      ; R2= value pointed to by R1
    ADD   R2,R0        ; R2= R2+R0
    ADD   R2,R0,R1     ; R2= R0+R1
```

**Register list** - The stack push and stack pop instructions can operate on one register or on a list of registers. **SP** is the same as R13, **LR** is the same as R14, and **PC** is the same as R15.
```assembly
    PUSH  {LR}         ; save LR on stack
    POP   {LR}         ; remove from stack and place in LR
    PUSH  {R1,R2,LR}   ; save registers and return address
    POP   {R1,R2,PC}   ; restore registers and return
```

**Immediate addressing** - Data itself is contained in the instruction. Immediate addressing is only used to get, load, or read data. It will never be used with an instruction that stores to memory.
```assembly
    MOV   R0,#100      ; R0=100, immediate addressing
```

**Indexed addressing** - With indexed addressing mode, the data is in memory and a register will contain a pointer to the data. Once the instruction is fetched, one or more additional memory access cycles are required to read or write the data. In these examples, R1 points to RAM. In this class, we will focus on just the first two forms of indexed addressing.
```assembly
    LDR   R0,[R1]      ; R0= value pointed to by R1
    LDR   R0,[R1,#4]   ; R0= word pointed to by R1+4
    LDR   R0,[R1,#4]!  ; first R1=R1+4, then R0= word pointed to by R1
    LDR   R0,[R1],#4   ; R0= word pointed to by R1, then R1=R1+4
    LDR   R0,[R1,R2]   ; R0= word pointed to by R1+R2
    LDR   R0,[R1,R2, LSL #2] ; R0= word pointed to by R1+4*R2 
```

**PC-relative addressing** - A simple example of PC-relative addressing is the unconditional branch. In assembly language, we simply specify the label to which we wish to jump, and the assembler encodes the instruction with the appropriate PC-relative offset.
```assembly
    B  Location  ; jump to Location, using PC-relative addressing
```

**Flexible second operand <op2>** - Many instructions have a flexible second operand, shown as <op2> in the descriptions of the instruction. <op2> can be a constant or a register with optional shift. The flexible second operand can be a constant in the form #constant
```assembly
    ADD Rd, Rn, #constant   ;Rd = Rn+constant
```

where constant is calculated as one of these four, X and Y are hexadecimal digits:

* Constant produced by shifting an unsigned 8-bit value left by any number of bits
* Constant of the form 0x00XY00XY
* Constant of the form 0xXY00XY00
* Constant of the form 0xXYXYXYXY

If Rd is missing, Rn is also the destination. For example:
```assembly
     ADD Rd, Rn, Rm {,shift}  ;Rd = Rn+Rm
     ADD Rn, Rm {,shift}      ;Rn = Rn+Rm
```     

where Rm is the register holding the data for the second operand, and shift is an optional shift to be applied to Rm. The optional shift can be one of these five formats:
```assembly
ASR #n   Arithmetic (signed) shift right n bits, 1 ≤ n ≤ 32.
LSL #n   Logical (unsigned) shift left n bits, 1 ≤ n ≤ 31.
LSR #n   Logical (unsigned) shift right n bits, 1 ≤ n ≤ 32.
ROR #n   Rotate right n bits, 1 ≤ n ≤ 31.
RRX      Rotate right one bit, with extend.
```

**Aligned access** is an operation where a word-aligned address is used for a word, dual word, or multiple word access, or where a halfword-aligned address is used for a halfword access. Byte accesses are always aligned. The address of an aligned word access will have its bottom two bits equal to zero.

## Address Space
### Memory Map Layout
ROM
* Code
* Constants

Ram
* Data
* Variables
* Stack

### Memory map of the TM4C123
[Data sheet for the TM4C123 microcontroller](https://prod-edxapp.edx-cdn.org/assets/courseware/v1/fa65824471e6a00ada3317b79943c1ae/asset-v1:UTAustinX+UT.6.10x+3T2019+type@asset+block/tm4c123gh6pm.pdf)
* Chapter 1.2 TM4C123GH6PM Microcontroller Overview

Task that can occur in parallel
* **ICode bus** - Fetch opcode from ROM
* **DCode bus** - Read constant data from ROM
* **System bus** - Read/write data from RAM or I/O, fetch opcode from RAM
* **PPB** - Read/write data from internal peripherals like the NVIC
* **AHB** - Read/write data from high-speed  I/O and parallel ports (M4 only)

## Software Development 
### Integrated Development Environment - Keil
* ARM Keil™ uVision®
* Texas Instruments Code Composer Studio™ (CCStudio)

Assembly language or C development process:
* Use an **editor** to create our **source code**. This contains specific set of sequential commands in human-readable-form.
* Use an **assembler** or **compiler** to translate our source code into object code. This contains these same commands in machine-readable-form. The assembler/compiler may also produce a **listing file**, which is a human-readable output showing the addresses and object code that correspond to each line of the source program.
* The **target** specifies the platform on which we will be running the object code.