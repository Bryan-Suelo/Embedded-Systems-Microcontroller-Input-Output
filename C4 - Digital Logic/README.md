# Chapter 4 - Digital Logic

## Binary Information Implemented with MOS Transistors

### Representation of Binary Data
**Binary bit** - can exist in one of two possible states.
In **positive logic** presence of a voltage is called *high state*. The
absence of voltage is called *low state*

### Digital Values Encoded as Voltages
Data sheet for the TM4C123 microcontroller

* Chapter 24.3 Recommended Operating Conditions

V<sub>IL</sub> - Maximum allowable voltage that the input consider as low
V<sub>IH</sub> - Minimum allowable voltage that the input will  consider as high
V<sub>OL</sub> - Maximum possible voltage that an output can be 
V<sub>OH</sub> - Minimum possible voltage that  an output can be

If the information we wish to store exists in more than two states, we use multiple bits.
A collection of n bits has 2<sup>n</sup> states.
A byte contains eight bits (**octet**), and is built by grouping eight
binary bits into one object.

## Digital Logic
### Design of a NOT gate
P type transistor
* Current can flow from source to drain
* No current will flow if the switch is open
* Switch will be closed (active) if its gate is low
* A transistor will be off (switch open) if its gate is high

N type transistor
* Switch will be closed (active) if its gate is high
* A transistor will be off (sitch open) if its gate is low

![](NOT_Gate.JPG)

Implementation of a NOT gate

### Logic and Boolean Operations
**Boolean**
* Takes true/false inputs and generates true/false outputs
* We use Boolean operations to make decisions
**bit-wise logical** operation 
* Operation is performed on a bit-by-bit manner 
* Set/clear/mask/toggle individual bits needed to perform input/output
operations
* When operating on numbers (collection of bits) we will perform bit-wise
logic operations bit by bit.

| Binary        | Bit-wise logic | Boolean |
| -----------   |:--------------:| -------:|
|               | NOT (~)        | NOT (!) |
|A = 01100111   | A~ = 10011000  |  A! = 0 |
|               | AND (&)        | AND (&&)|
| A = 01100111  |  A&B =         |  A&&B = |
| B = 11110000  |  01100000      |   1     |
|               | OR (+)         | OR (+)  |
| A = 01100111  |  A+B =         |  A++B = |
| B = 11110000  |  11110111      |   1     |

NAND - Operation followed by an AND followed by a NOT

### Boolean Algebra
**Precedence** is used to determine the order of operation. Usually NOT is
evaluated first, then AND, and then OR. This order can be altered using
parentheses.

## Flip Flops
### Flip Flops
The simplest storage device is the **set-reset latch**.
#### Build a set-reset latch
| Input                 | Output|
| ----------------------|:-----:|
|  S* = 0       R* = 0  | Q = 0 |        
|  S* = 0       R* = 1  | Q = 0 |        
|  S* = 1       R* = 0  | Q = 0 |
|  S* = 1       R* = 1  | Q = 1 |

**Gated D latch** - To use the gated latch, we first put the data on the D
input, next we make W go high, and then we make W go low. This causes the
data value to be stored at Q. After W goes low, the data does not need to
exist at the D input anymore. If the D input changes while W is high, then
the Q output will change correspondingly. However, the last value on the D
input is remembered or latched when the W falls.

**D flip-flop** - Are used to store information. D flip-flops are the basic building block of RAM and registers on the computer.

### Tristate driver
Can be used dynamically control signals within the computer. It is called
tristate because there are three possible outputs: **high**, **low**, and
**HiZ**. The tristate driver is an essential component from which computers
are built. 
To activate the driver, we make its gate (G*) low. When the driver is active
its output (Y) equals its input (A). 
To deactivate the driver, we make its G* high. When the driver is not active
its output Y floats independent of A. 
The HiZ output means the output is neither driven high nor low. 

## Digital Information Stored in Memory
### Introduction to Memory
**Memory** - Collection of hardware elements in a computer into which we store information, the memory is called byte-addressable because each byte
has a separate address.
The address of a memory cell specifies its physical location, and its
content is the data. When we write to memory, we specify an address and bits
of data, causing that information to be stored into the memory.
When we read from memory we specify an address, causing bits of data to be
retrieved from the memory. 

**Read Only Memory** (ROM) - Type of memory where the information is
programmed or burned into the device, and during normal operation it only
allows read accesses. 
* Information is nonvolatile, meaning the contents are not lost when power is
removed.
* ROM on the other hand is much denser than RAM. This means we can pack more * ROM bits into a chip than we can pack RAM bits. 
* Most microcontrollers have much more ROM than RAM.
* The system can quickly and conveniently read data from a ROM. It takes a
comparatively long time to program or burn data into a ROM.

Writing to Flash ROM is a two-step process:
* ROM is erased, causing all the bits to become 1. 
* System writes zeroes into the ROM as needed. Each of these two steps
requires around 1 ms to complete.

**Random Access Memory** (RAM) - Used to store temporary information, and during normal operation we can read from or write data into RAM.

* Information in the RAM is volatile, meaning the contents are lost when power is removed.
* Writing to RAM is about 100,000 times faster (on the order of 10 ns). 

**Register** - Basic storage element.
There are two operations one performs on a register: write and read
_**Perform a Write**_:
* One first puts the desired information on the 8 data bus wires.
* System pulses the Write signal high then low. 
* Write pulse will latch or store the desired data into the 8 flip-flops.

_**Perform a Read**_:
* Will place a copy of the register information onto the data bus. 

**Bus** - Collection of wires used to pass data from one place to another.

**Tristate drivers** - Gate signals are negative logic. This means if the Read* signal is high, the tristate drivers are off, and this register does not affect signals on the bus. However, the read operation occurs by setting the Read* signal low, which will place the register data onto the bus.

### From Kibibytes to Gigibytes
The term **kibibyte** is a contraction of kilo binary byte and is a unit of
information or computer storage, abbreviated **KiB**.
The term **kibibit** is a contraction of kilo binary bit, and is a unit of
information or computer storage, abbreviated **Kibit**.

1 kibibyte = 1 KiB = 2<sup>10</sup> bytes = 1024 bytes
1 mebibyte = 1 MiB = 2<sup>20</sup>bytes = 1,048,576 bytes
1 gibibyte = 1 GiB = 2<sup>30</sup>bytes = 1,073,741,824 bytes

A mebibyte (1 MiB is 1,048,576 bytes) is approximately equal to a megabyte
(1 MB is 1,000,000 bytes).