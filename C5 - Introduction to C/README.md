# Chapter 5 - Introduction to C

## Introduction 
### Where to begin? Flowcharts
Flowcharts are one way to describe software in a two-dimensional format,
specifically providing convenient mechanisms to visualize conditional 
branching and function calls. Flowcharts are very useful in the initial 
design stage of a software system to define complex algorithms. 

Furthermore, flowcharts can be used in the final documentation stage of a
project, once the system is operational, in order to assist in its use or 
modification.

**Oval shapes** - define entry and exit points. 
* The main **entry point** is the starting point of the software. Each function, or subroutine, also has an entry point. 
* The **exit point** returns the flow of control back to the place from which the function was called.

**Rectangles** - specify process blocks. 
* **High-level** flowchart, a process block might involve many operations.
* **Low-level** flowchart, the exact operation is defined in the rectangle. 

**Parallelogram** - used to define an input/output operation.
**Diamond-shaped** - define a branch point or conditional block. 
* Inside the diamond we can define what is being tested. 
* Each arrow out of a condition block must be labeled with the condition
causing flow to go in that direction. 
* There must be at least two arrows out of a condition block, but there
could be more than two.

**Rectangle with double lines** - specifies a call to a predefined
function. 
**Circles** - used as connectors. 
* A connector with an arrow pointing out of the circle defines a label or a
spot in the algorithm. 
* There should be one label connector for each number. 
* Connectors with an arrow pointing into the circle are jumps or goto commands. 

Structures programs in C are built from three basic templates:
* the sequence
* the conditional
* the while loop

## Background Information
### Terminology
A **compiler** is system software that converts a high-level language program (human readable format) into object code (machine readable format). It produces software that is fast but to change the software we need to edit the source code and recompile.

```C code (**z = x+y;**) → Assembly code (**ADD R2,R1,R0**)  → Machine code (**0xEB010200**)```

An **assembler** is system software that converts an assembly language program (human readable format) into object code (machine readable format).

```Assembly code (**ADD R2,R1,R0**)  → Machine code (**0xEB010200**)```

An **interpreter** executes directly the high level language. It is interactive but runs slower than compiled code. Many languages can be compiled or interpreted. Interpreted means the user typed software to the computer, and the interpreter executed the commands as they were typed.

A **linker** builds software system by connecting (linking) software components. The example code in this module has three software components that are linked together. These components are:

* startup.s
* uart.c
* main.c

A **loader** will place the object code in memory. In an embedded system, the loader will program object code into flash ROM.

A **debugger** is a set of hardware and software tools we use to verify system is operating correctly. The two important aspects of a good debugger are control and observability.

## Structure and Organization
### Punctuation
In **assembly language**, symbols placed at the beginning of each line have special meaning. 
C is a **free field language**. Except for preprocessor lines that begin with #, spaces, tabs and line breaks have the same meaning. This means we can place more than one statement on a single line, or place a single statement across multiple lines. We could write a function without any line breaks.  
Another situation where spaces, tabs and line breaks matter is string constants. We cannot type tabs or line breaks within a string constant. The characters between the first " and second " define the string constant. A string is a set of ASCII characters terminated with a 0.

### Sections of program
 1. **Documentation section** Which includes: 
 * The purpose of the software
 * The authors
 * The date
 * Copyright information 
 
 When the software involves external hardware we will add information about how the external hardware is connected.

2. **Preprocessor directives**. We will use the preprocessor directive **#include** to connect this software with other modules. We use diamond braces to include system libraries, like the standard I/O, and we use quotes to link up with other user code within the project. 

3. **Global declarations** section. Which includes global variables and function prototypes for functions defined in this module.

4. **Functions** themselves.

There are two types of **comments**:
* **How to use the software** explanation. These comments are usually placed at the top of the file, within the header file, or at the start of a function. 
* **Assists a future programmer** (ourselves included) in changing, debugging or extending these routines. We usually place these comments within the body of the functions.

**Preprocessor** directives begin with **#** in the first column. As the name implies preprocessor commands are processed first. We create a **macro** using ```#define```  to define constants.
A second important directive is the ```#include```, which allows you to include another entire file at that position within the program. 

### Variables and expressions
#### Standard I/O and printf
A very powerful approach to I/O is to provide a high-level abstraction in such a way that the I/O device itself is hidden from the user.
* **```printf```** is a function from the standard input and output library that allows you to display messages.

* The **pound sign** ('#') specifies that the value should be converted to an alternate form. The alternate form for hexadecimal adds the 0x or 0X.
```c
printf("%x", 13);    // prints just 'd'
printf("%#x", 13);   // prints '0xd'
printf("%X", 13);    // prints just 'D'
printf("%#X", 13);   // prints '0XD'
printf("%o", 13);    // prints just '15'
printf("%#o", 13);   // prints '015'
```

* The **zero** ('0') specifies zero-padding. The converted value is padded on the left with the specified number of zeros minus the number of digits to be printed.
```c
printf("%d", 15);      // prints '15'
printf("%4d", 15);     // prints '  15'
printf("%04d", 15);    // prints '0015'
printf("%06d", 1234);  // prints '001234'
```

* A **minus sign** ('-') specifies left justification. Without the minus, the format is right justified.
```c
printf("%5d", 123);    // prints '  123' (right justified)
printf("%-5d", 123);   // prints '123  ' (left justified)
```

A **space** (' ') specifies that a blank should be left before a positive number.
```c
printf("% d", 17);     // prints ' 17'
printf("% d", -17);    // prints '-17'
```

* The **plus sign** ('+') specifies that a sign always be placed before the value. The plus sign overrides a space if both are used.
```c
printf("%+d", 12);    // prints '+12'
printf("%+d", -2);    // prints '-2'
```

* A **decimal digit** specifies the minimum field width. Using the minus sign makes the format is left justified, otherwise it is right justified. Used with the zero-modifier for numeric conversions, the value is right-padded with zeros to fill the field width.
```c
printf("%4d", 25);     // prints '  25' (right justified)
printf("%-4d", 25);    // prints '25  ' (left justified)
printf("%4d", 1234);   // prints '1234' (filled up)
printf("%4d", 12345);  // prints '12345' (bigger than 3 width)
```

* A **precision value** in the form of a period ('.'), followed by an optional digit string. If the digit string is omitted, a precision of zero is used. For floating point output, it specifies the number of digits after the decimal place. For string conversion, it specifies the maximum number of characters of the string to print.
```c
printf("%.4d", 7);          // prints '0007'
printf("%.4d", 123456);     // prints '123456'
printf("%3s", "Jonathan");  // prints 'Jonathan'
printf("%.3s", "Jonathan"); // prints 'Jon'
```      

#### Datatypes and Variables
Variables are used to hold information.
| Data type     | Precision        | Range                     |
| ------------- |:----------------:| -------------------------:|
| unsigned char | 8-bit unsigned   |0 to +255                  |
|signed char    |8-bit signed      |-128 to +127               |
|unsigned int   |compiler-dependent|                           |
| int           |compiler-dependent|                           |
|unsigned short |16-bit unsigned   |0 to +65535                |
|short          |16-bit signed     |-32768 to +32767           |
|unsigned long  |unsigned 32-bit   |0 to 4294967295L           |
|long           |signed 32-bit     |-2147483648L to 2147483647L|
|float          |32-bit float      |±10-38 to ±10+38           |
|double         |64-bit float      |±10-308 to ±10+308         |

**Keil** considers int as 32 bits. We will avoid **int** and use **long** for 32-bit variables so there is no confusion. 
Variables declared outside of a function are properly called **external variables** because they are defined outside of any function. While this is the **standard term** for these variables, it is confusing because there is another class of external variable, one that exists in a separately compiled source file. 

There are two reasons to employ global variables:
* Data permanence. 
* Information sharing. 

Normally we pass information from one module to another explicitly using input and output parameters, but there are applications like interrupt programming where this method is unavailable. For these situations, one module can store data into a global while another module can view it.

**Local variables** contain temporary information that is accessible only within a narrow scope. We can define local variables at the start of a compound statement. We call these local variables since they are known only to the block in which they appear, and to subordinate blocks. 
**Local variable** must be declared immediately after a brace **{** that begins a compound statement. Unlike globals, which are said to be static, locals are created dynamically when their block is entered, and they cease to exist when control leaves the block.
Local names **supersede** the names of globals and other locals declared at higher levels of nesting. Therefore, locals may be used freely without regard to the names of other variables. Although two global variables cannot use the same name, a local variable of one block can use the same name as a local variable in another block. 

#### Expressions
| Operation | Meaning                                  | 
| ----------|:----------------------------------------:|
| =         | Assignment statement                     |
|==         |Equal to comparison                       |
|?          |Selection                                 |
|<=         |Less than or equal to                     |
|<          |Less than                                 |
|>=         |Greater than or equal to                  |
|>          |Greater than                              |
|!=         |Not equal to                              |
|!          |Logical not (true to false, false to true)|
|<<         |Shift left                                |
|~          |1’s complement                            |
|>>         |Shift right                               |
|+          |Addition                                  |
|++         |Increment                                 |
|-          |Subtraction                               |
|--         |Decrement                                 |
|*          |Multiply or pointer reference             |
|&&         |Boolean and                               |
|/          |Divide                                    |
|%          |Modulo, division remainder                |
|+=         |Add value to                              |
|-=         |Subtract value to                         |
|&          |Logical and, or address of                |
|*=         |Multiply value to                         |
|^          |Logical exclusive or                      |
|/=         |Divide value to                           |
|.          |Used to access parts of a structure       |
|&=         |And value to                              |
|^=         |Exclusive or value to                     |
|<<=        |Shift value left                          |
|>>=        |Shift value right                         |
|%=         |Modulo divide value to                    |
|->         |Pointer to a structure                    |

The **precedence** of the operator determines which operations are performed first.
**Associativity**determines the left to right or right to left order of evaluation when multiple operations of equal precedence are combined. 

|Precedence|Operators                          |Associativity|
|----------|-----------------------------------|:-----------:|
|Highest   |() []. ->  ++(postfix)  --(postfix)|Left to right|
||++(prefix)  --(prefix)   !  ~ sizeof(type) +(unary) -(unary)  &(address)  *(dereference)|Right to left|
|          |*   /   %                          |Left to right|
|          |+   -                              |Left to right|
|          |<<   >>                            |Left to right|
|          |<    <=   >   >=                   |Left to right|
|          |==  !=                             |Left to right|
|          |&                                  |Left to right|
|          |^                                  |Left to right|
|          |OR                                 |Left to right|
|          |&&                                 |Left to right|
|          |OR                                 |Left to right|
|          |? :                                |Right to left|
|          |=   +=   -=  *=  /=  %=  <<=  >>=  OR=  &=  ^=|Right to left|
|Lowest    |  ,                                |Left to right|

### Functions
#### Function Syntax
**Function** is a sequence of operations that can be invoked from other places within the software. We can pass zero or more parameters into a function. A function can have zero or one output parameter.
A **function declaration** specifies its name, its input parameters and its output parameter. Another name for a function declaration is **prototype**. A data structure declaration specifies its type and format. On the other hand, a function definition specifies the exact sequence of operations to execute when it is called.
A **function definition** will generate object code, which are machine instructions to be loaded into memory that perform the intended operations. A data structure definition will reserve space in memory for it. The confusing part is that the definition will repeat the declaration specifications. 

#### Function Parameter
**Address** shows the ROM location into which the instruction is stored. 
The **Machine code** is the actual instruction in hexadecimal format. 
The **Label** is a symbol marking that spot in the program. We use labels to call functions and the jump to other locationgs in the same program. 
Each Instruction has an **op code** and one or more **operands**. 
The **Comments** were added to explain what the program is doing.

To specify the absence of a parameter we use the expression **void**. The body of a function consists of a statement that performs the work. Normally the body is a compound statement between a **{}** pair. If the function has a return parameter, then all exit points must specify what to return.

### Conditional Branching Loops
#### If-Then Conditional and While Loop Lecture
Ex.
```
void Initialize (void);
```
A function like this says it does not require inputs and outputs.
* Prototype: is not returning
* Name: Initialize
* Output

#### Making Decisions
An effective software design approach is to test the input parameters of a function to make sure the values make sense.
An unsigned long can represent a number up to 4 billion.

The **for** control structure has three parts and a body.
```c
      for(part1;part2;part3){body;}
```
The **first** part ```side = 1``` is executed once at the beginning. 
The **second** part is always a conditional that results in a true or a false. 
The body and **third** part are repeated until the conditional is false.

### Keyboard Input using scanf
#### Example C program

### C Keywords and Punctuation
#### C Keywords and Punctuation
**Volatile** keyword disables compiler optimization, forcing the compiler to fetch a new value each time. 
* Use volatile when defining I/O ports because the value of ports can change outside of software action. 
* Use volatile when sharing a global variable between the main program and an interrupt service routine. 
It is a good programming practice not to use these keywords for your variable or function names.

**Semicolons** are used as statement terminators. Preprocessor directives do not end with a semicolon since they are not actually part of the C language proper.

**Colons** terminate case, and default prefixes that appear in switch statements.

**Commas** separate items that appear in lists. We can create multiple variables of the same type using commas.

**Lists** are used with functions having multiple parameters, both when the function is defined and called. Lists can also be used in general expressions. Sometimes it adds clarity to a program if related variables are modified at the same place. 
The value of a list of expressions is always the value of the last expression in the list.

**Apostrophes** are used to specify character literals. 

**Quotation marks** are used to specify string literals. Strings are stored as a sequence of ASCII characters followed by a termination code, 0.

**Braces** { } most common application is for creating a compound statement. Each open brace { must be matched with a closing brace }. 
Notice the use of indenting helps to match up braces. Each time an open brace is used, the source code is tabbed over using 2 spaces.

**Square brackets** [ ] enclose array dimensions (in declarations) and subscripts (in expressions).

**Parentheses** () enclose argument lists that are associated with function declarations and calls. They are required even if there are no arguments.