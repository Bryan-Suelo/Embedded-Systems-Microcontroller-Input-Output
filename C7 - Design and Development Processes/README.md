# Desing and Development processes

## Product life cycle
### Life cycle
The development of a product follows an analysis-design-implementation-testing-deployment cycle.

![](Images/DesignCycle.jpg)

During the **analysis phase**, we discover the requirements and constraints for our proposed system.
* A **requirement** is usually defined in general terms, it often refers to an objective of the system.
* **Specifications** are detailed parameters describing how the system should work, it entails detailed engineering rigor.
* A **constraint** is a limitation, within which the system must operate.

### Requirements Document
A requirements document states what the system will do. It does not state how the system will do it. The main purpose of a requirements document is to serve as an agreement between you and your clients describing what the system will do.
Write the document so that it is easy to read and understand by others.  IEEE publishes a number of templates that can be used to define a project (IEEE STD 830-1998). 

Possible outline:
1. **Overview**
  1.1. **Objectives**: Why are we doing this project? What is the purpose?
  1.2. **Process**: How will the project be developed?
  1.3. **Roles and Responsibilities**: Who will do what?  Who are the clients?
  1.4. **Interactions with Existing Systems**: How will it fit in?
  1.5. **Terminology**: Define terms used in the document.
  1.6. **Security**: How will intellectual property be managed?

2. **Function Description**
  2.1. **Functionality**: What will the system do precisely?
  2.2. **Scope**: List the phases and what will be delivered in each phase.
  2.3. **Prototypes**: How will intermediate progress be demonstrated?
  2.4. **Performance**: Define the measures and describe how they will be determined.
  2.5. **Usability**: Describe the interfaces. Be quantitative if possible.
  2.6. **Safety**: Explain any safety requirements and how they will be measured.

3. **Deliverables**
  3.1. **Reports**: How will the system be described?
  3.2. **Audits**: How will the clients evaluate progress?
  3.3. **Outcomes**: What are the deliverables? How do we know when it is done?

**Observation**: To build a system without a requirements document means you are never wrong, but never done.

### Data Flow graph
**Design phase**: we build a conceptual model of the hardware/software system. It is in this model that we exploit as much abstraction as appropriate. The project is broken into modules or subcomponents.
During this phase, we estimate the cost, schedule, and expected performance of the system. At this point we can decide if the project has a high enough potential for profit. 

**Data flow graph**: this is a block diagram of the system, showing the flow of information. Arrows point from source to destination. The rectangles represent hardware components, and the ovals are software modules. 
We use data flow graphs in the high-level design, because they describe the overall operation of the system while hiding the details of how it works.

![](Images/Dataflow.jpg)

### Call graph
Call graphs are a graphical way to define how the software/hardware modules interconnect.
**Data structures**, which will be presented throughout the class, include both the organization of information and mechanisms to access the data. Rectangles represent hardware components, and ovals show software modules.

An arrow points from the calling routine to the module it calls. The I/O ports are organized into groups and placed at the bottom of the graph. A high-level call graph, shows only the high-level hardware/software modules. 
A detailed call graph would include each software function and I/O port. Normally, hardware is passive and the software initiates hardware/software communication.

![](Images/CallGraph.jpg)

### Implementation
An advantage of a top-down design is that implementation of subcomponents can occur simultaneously. During the initial iterations of the life cycle, it is quite efficient to implement the hardware/software using simulation. 
One major advantage of simulation is that it is usually quicker to implement an initial product on a simulator versus constructing a physical device out of actual components.

Rapid prototyping is important in the early stages of product development. This allows for more loops around the analysis-design-implementation-testing-deployment cycle, which in turn leads to a more sophisticated product.

During the **testing** phase, we evaluate the performance of our system. First, we debug the system and validate basic functions. Next, we use careful measurements to optimize performance such as static efficiency (memory requirements), dynamic efficiency (execution speed), accuracy (difference between expected truth and measured), and stability (consistent operation.)

**Maintenance** is the process of correcting mistakes, adding new features, optimizing for execution speed or program size, porting to new computers or operating systems, and reconfiguring the system to solve a similar problem. No system is static. Customers may change or add requirements or constraints. 
To be profitable, we probably will wish to tailor each system to the individual needs of each customer. Maintenance is not really a separate phase, but rather involves additional loops around the life cycle.

With a **bottom-up** design we begin with solutions and build up to a problem statement. In a bottom-up design, one begins with designing, building, and testing low-level components. The low-level designs can be developed in parallel. Bottom-up design may be inefficient because some subsystems may be designed, built, and tested, but never used.
The bottom-up design process allows creative ideas to drive the products a company develops. It also allows one to quickly test the feasibility of an idea.

If one fully understands a problem area and the scope of potential solutions, then a **top-down** design will arrive at an effective solution most quickly. On the other hand, if one doesn’t really understand the problem or the scope of its solutions, a bottom-up approach allows one to start off by learning about the problem.

A **top-down designer** starts with a problem, conceives of a solution, procures the parts, builds a prototype, and then tests to see if it works.

A **bottom-up designer** first procures the parts, tries to put the pieces together in interesting ways, and then sees if it solves any interesting problems.

## Successive Refinement
### Structured programming
We begin with a set of general specifications, and then create a list of requirements and constraints. The general specifications describe the problem statement in an overview, requirements define the specific things the system must do, and constraints are the specific things the system must not do. These requirements and constraints will guide us as we develop and test our system.

**Observation**: Sometimes the specifications are ambiguous, conflicting, or incomplete.

There are two approaches to those situations:
* Resolve the issue with your supervisor or customer. 
* Make a decision and document the decision.

**Successive refinement**, **stepwise refinement**, and **systematic decomposition** are three equivalent terms for a technique to convert a problem statement into a software algorithm.
1. Start with a task and decompose the task into a set of simpler subtasks.
2. The subtasks are decomposed into even simpler sub-subtasks. We make progress as long as each subtask is simpler than the task itself.
3. During the task decomposition we must make design decisions as the details of exactly how the task will be performed are put into place.
4. A subtask is so simple that it can be converted to software code.

The **sequence**, **conditional**, and **iteration** are the three building blocks of structured programming. Because embedded systems often have real-time requirements, they employ a fourth building block called **interrupts**. We will implement time-critical tasks using interrupts, which are hardware-triggered software functions.

![](Images/SuccessiveRefinement.jpg)

When solving problems on the computer, we need to solve these questions:

* **What does being in a state mean?**
List the parameters of the state

* **What is the starting state of the system?**
Define the initial state

* **What information do we need to collect?**
List the input data

* **What information do we need to generate?**
List the output data

* **How do we move from one state to another?**
Specify actions we could perform

* **What is the desired ending state?**
Define the ultimate goal

### How to write software?
The **state** of a system specifies "what do we know?" or "what do we believe to be true?" It is extremely important to encode state in a clear and unambiguous manner.

**Global variables**: An obvious way for software to remember information is to place the data in a permanent variable. If the data is shared across the system we call it a global variable.

**Input devices**: This works when software only needs to know the current state, and it doesn't matter about previous conditions.

**Output devices**: Fundamentally, output devices behave in a manner similar to global variables. Outputs are permanently allocated and can be shared across the system.

**Execution location**: A very typical technique to encode knowledge is to making a mapping between where the software is executing and what you believe to be true.
The limitation with this method of encoding state is that it, like inputs, only defines the current knowledge and has no permanent memory of previous states.

## Quality Design
### The golden rule
The ultimate goal of the system is to satisfy the stated objectives such as accuracy, stability, and input/output relationships. Nevertheless it is appropriate to separately evaluate the individual components of the system.

Quantitative criteria include dynamic efficiency (speed of execution), static efficiency (memory requirements), and accuracy of the results. Qualitative criteria center on ease of software maintenance. 

Another qualitative way to evaluate software is ease of understanding. If your software is easy to understand then it will be:

* Easy to debug (fix mistakes)
* Easy to verify (prove correctness)
* Easy to maintain (add features)

**Common Error**: Programmers who sacrifice clarity in favor of execution speed often develop software that runs fast, but is error-prone and difficult to change.

In order to evaluate our software quality, we need performance measures.
**Dynamic efficiency** is a measure of how fast the program executes. It is measured in seconds or processor bus cycles.

**Static efficiency** is the number of memory bytes required. Since most embedded computer systems have both RAM and ROM, we specify memory requirement in global variables, stack space, fixed constants and program. The global variables plus the stack must fit into the available RAM.

Qualitative performance measurements include those parameters to which we cannot assign a direct numerical value.

### Software Maintenance
We should be mortified when other programmers find bugs in our code. There are a few steps we can take to facilitate this important aspect of software design.

**Test it now.** Developers should completely test each module individually, before combining them into a larger system. We should not add new features before we are convinced the existing system is bug-free. In this way, we start with a working system, add features, and then debug this system until it is working again.
This incremental approach makes it easier to track progress.

**Plan for testing.** How to test each module should be considered at the start of a project. Our testing and the client's usage go hand in hand. In particular, how we test the module will help the client understand the context and limitations of how our component is to be used. 

**Get help.** Use whatever features are available for organization and debugging. Pay attention to warnings, because they often point to misunderstandings about data or functions.

**Deal with the complexity.** A complex system can be created out of simple components. A real creative effort is required to orchestrate simple building blocks into larger modules, which themselves are grouped to create even larger systems. 
Use your creativity to break a complex problem into simple components, rather than developing complex solutions to simple problems.

## Functions, procedures, methods and subroutines
### Call by value vs Call by reference
A program module that performs a well-defined task can be packaged up and defined as a single entity. A subroutine is the **assembly language** version of a function. Consequently, subroutines may or may not have **input** or **output** parameters.
The syntax for an assembly subroutine begins with a label, which will be the name of the subroutine and ends with a return instruction.

Formally, there are two components to a subroutine: definition and invocation.

The subroutine **definition** specifies the task to be performed. In other words, it defines what will happen when executed. The definition of a subroutine includes a formal specification its input parameters and output parameters. In well-written software, the task performed by a subroutine will be well-defined and logically complete. 

The subroutine **invocation** is inserted to the software system at places when and where the task should be performed. We define software that invokes the subroutine as “the calling program” because it calls the subroutine.
There are **three** parts to a subroutine invocation: 
* pass input parameters
* subroutine call
* accept output parameters. 

If there are input parameters, the calling program must establish the values for input parameters before it calls the subroutine.

A ```BL``` instruction is used to call the subroutine.
If the register contains a value, the parameter is classified as **call by value**. If the register contains an address, which points to the value, then the parameter is classified as **call by reference**.

### Coupling
Defined as the influence one module’s behavior has on another module. In order to make modules more independent we strive to minimize coupling.

A quantitative measure of coupling is the number of bytes per second (bandwidth) that are transferred from one module to another. On the other hand, information stored in public global variables can be quite difficult to track.

Public global variables cause coupling between modules that complicate the debugging process because now the modules may not be able to be separately tested. On the other hand, we must use global variables to pass information into and out of an interrupt service routine and from one call to an interrupt service routine to the next call. When passing data into or out of an interrupt service routine, we group the functions that access the global into the same module, thereby making the global variable private.

On many microcontrollers it is inefficient to implement local variables on the stack. Consequently, many programmers opt for faster approach of global variables. 
Again, if we restrict access to these globals to function in the same module, the global becomes private. It is poor design to pass data between modules through public global variables; it is better to use a well-defined abstract technique like a FIFO queue.

The following three objectives when dividing a software project into subtasks, it is really only the first one that matters

• Make the software project easier to understand
• Increase the number of modules
• Decrease the interdependency (minimize bandwidth between modules).

## Making Desicions
### Conditional if-then Statements
Decision making is an important aspect of software programming.

#### Conditional IF-THEN Statements
Two values are compared and certain blocks of program are executed or skipped depending on the results of the comparison.
In assembly language it takes three steps to perform a comparison:

* Begin by reading the first value into a register. If the second value is not a constant, it must be read into a register, too.
* Compare the first value with the second value. You can use either a subtract instruction with the ```S (SUBS)``` or a compare instruction ```(CMP CMN)```. The ```CMP CMN SUBS``` instructions set the condition code bits.   
* Conditional branch.

##### Examples
###### Example 1 
| Assembly code | C code |
|--------------:|-------:|
```c
  LDR R2, =G     ; R2 is the address of G            unsigned long G, H;
  LDR R0, [R2]   ; R0 = G                            if (G == H)
  LDR R3, =H     ; R3 is the address of H            {
  LDR R1, [R3]   ; R1 = H                               GEqualH();
  CMP R0, R1     ; is G == H ?                       } 
  BNE next1      ; if not equal, skip
  BL  GEqualH    ; G == H
next1
```

###### Example 2
| Assembly code | C code |
|--------------:|-------:|
```c
  LDR R2, =G     ; R2 is the address of G            unsigned long G, H;
  LDR R0, [R2]   ; R0 = G                            if (G == H)
  LDR R3, =H     ; R3 is the address of H            {
  LDR R1, [R3]   ; R1 = H                               GNotEqualH();
  CMP R0, R1     ; is G != H ?                       } 
  BEQ next2      ; if equal, skip
  BL  GEqualH    ; G != H
next2
```

When comparing unsigned values, the instructions ```BHI BLO BHS``` and ```BLS``` should follow the subtraction or comparison instruction.

When comparing signed values, the instructions ```BGT BLT BGE``` and ```BLE``` should follow the subtraction or comparison instruction.

###### Example 3
| Assembly code | C code |
|--------------:|-------:|
```c
  LDR R2, =G     ; R2 is the address of G            unsigned long G, H;
  LDR R0, [R2]   ; R0 = G                            if (G > H)
  LDR R3, =H     ; R3 is the address of H            {
  LDR R1, [R3]   ; R1 = H                               GGreaterH();
  CMP R0, R1     ; is G > H ?                       } 
  BLS next1      ; if G <= H, skip
  BL  GGreaterH  ; G > H
next1
```

###### Example 4
| Assembly code | C code |
|--------------:|-------:|
```c
  LDR R2, =G       ; R2 is the address of G            unsigned long G, H;
  LDR R0, [R2]     ; R0 = G                            if (G >= H)
  LDR R3, =H       ; R3 is the address of H            {
  LDR R1, [R3]     ; R1 = H                               GGreaterEqH();
  CMP R0, R1       ; is G >= H ?                       } 
  BLO next2        ; if G < H, skip
  BL  GGreaterEqH  ; G >= H
next2
```

###### Example 5
| Assembly code | C code |
|--------------:|-------:|
```c
  LDR R2, =G     ; R2 is the address of G            unsigned long G, H;
  LDR R0, [R2]   ; R0 = G                            if (G > H)
  LDR R3, =H     ; R3 is the address of H            {
  LDR R1, [R3]   ; R1 = H                               GLessH();
  CMP R0, R1     ; is G < H ?                       } 
  BHS next3      ; if G >= H, skip
  BL  GLessH     ; G < H
next3
```

###### Example 6
| Assembly code | C code |
|--------------:|-------:|
```c
  LDR R2, =G     ; R2 is the address of G            unsigned long G, H;
  LDR R0, [R2]   ; R0 = G                            if (G > H)
  LDR R3, =H     ; R3 is the address of H            {
  LDR R1, [R3]   ; R1 = H                               GGreaterH();
  CMP R0, R1     ; is G <= H ?                       } 
  BHI next4      ; if G > H, skip
  BL  GLessEqH    ; G <= H
next4
```

To convert these examples to **16 bits**:
* Use the ```LDRH R0, [R2]``` instruction instead of the ```LDR R0, [R2]``` instruction. 
* Use the ```LDRH R1, [R3]``` instruction instead of the ```LDR R1, [R3]``` instruction. 

To convert these examples to **8 bits**:
* Use the ```LDRB R0, [R2]``` instruction instead of the ```LDR R0,[R2]``` instruction.
* Use the ```LDRB R1, [R3]``` instruction instead of the ```LDR R1, [R3]``` instruction.

### If-Else Statement
If statements can be expanded by an "else" statement. If the condition is false, the program will execute the statements under the "else" statement.

###### Example 1
| Assembly code | C code |
|--------------:|-------:|
```c
     LDR R2, =G1     ; R2 = &G1             unsigned long G1, G2;
     LDR R0, [R2]    ; R0 = G1              if (G1 > G2)
     LDR R2, =G2     ; R2 = &G2             {
     LDR R1, [R2]    ; R1 = G2                isGreaterH();
     CMP R0, R1      ; is G1 > G2 ?         } 
     BHI high        ; if so, skip to high  else
low  BL  isLessEq    ; G1 <= G2             { 
     B next          ; unconditional          isLessEq();
high BL isGreater    ; G1 > G2              }
next
```

##### Selection Operator
The format is:**```Expr1 ? Expr2 : Expr3```**

The first input parameter is an expression, **```Expr1```**, which yields a Boolean (0 for false, not zero for true).
**```Expr2```** and **```Expr3```** return values that are regular numbers. 

The selection operator will return the result of **```Expr2```** if the value of **```Expr1```** is **true**, and will return the result of **```Expr3```** if the value of **```Expr1```** is **false**. 

### Switch Statements
Switch statements provide a non-iterative choice between any number of paths based on specified conditions. They compare an expression to a set of constant values. Selected statements are then executed depending on which value, if any, matches the expression.
* The **break** causes execution to exit the switch statement. 
* The **default** case is run if none of the explicit case statements match.

### While Loops
Quite often the microcomputer is asked to wait for events or to search for objects. Both of these operations are solved using the **```while```** or **```do-while```** structure.

The statements inside a while statement, will continuously be executed if the while condition is **true**. If the condition is/becomes **false**, the program will skip the loop and continue with the execution of the remaining statements.

###### Example 1
| Assembly code | C code |
|--------------:|-------:|
```c
     LDR R4, =GPIO_PORTA_DATA_R             
loop LDR R0, [R2]     ; R0 = Port A         while (GPIO_PORTA_DATA_R&0x08)
     ANDS R0, #0x08   ; test  bit 3         {
     BEQ next         ; if so, quit           Body();
     BL Body          ; body of the loop    }
     B Loop        
next
```

### Do-While Loop
The statements inside a do-while statement will always be executed once, and will continuously be executed if the while condition is **true**. If the condition becomes **false**, the program will skip the loop and continue with the execution of the remaining statements. 
```c
volatile unsigned long a;

int main () 
{
printf("Starting the loop ..., a = %d\n",a);
do 
{
a = (a/10);
printf("current a = %d\n",a);
} 
while (a>0);
printf("Ending the loop ...\n");
return 0;
}
```

### For Loops
For loops can iterate up or down. To show the similarity between the while loop and for loop these two C functions are identical. The **```<init>```** code is executed once. The **```<test>```** code returns a true/false and is tested before each iteration. The **```<body>```** and **```<end>```** codes are executed each iteration.

###### Example 1
| Assembly code | C code |
|--------------:|-------:|
```c
      MOV R4, #0     ; R4 = 0
loop  CMP R4, #10    ; index >= 10 ?           for(i=0; i<10; i++)
      BHS done       ; if so, skip to done     {
      BL  Process    ; Process function          Process();    
      ADD R4, R4, #1 ; R4 = R4 + 1            }              
      B loop                                  
done       
```

###### Example 2
| Assembly code | C code |
|--------------:|-------:|
```c
      MOV R4, #10     ; R4 = 0
loop  BL  Process    ; body               for(i=10; i!=10; i--)
      SUBS R4, R4, #1 ; R4 = R4 - 1       {      
      BNE loop                              Process();    
done                                      }
```
A for loop functionality is similar to a while loop, with automatic initialization and update. It is usually used when the number of iterations is known. One variable is used as a counter of iterations. 
* The **first** field is the **initialization**, which is always executed once. 
* The **second** field is the **condition** to be **checked**. The loop will continue being executed until the condition becomes false.
* The **third** field (**update**) is executed at the end of each iteration and is usually used for incrementing/decrementing the counter.

## Functional debugging
### Control and observability
**Functional debugging** involves the verification of input/output parameters. Functional debugging is a static process where inputs are supplied, the system is run, and the outputs are compared against the expected results.

There are two important aspects of debugging: **control** and **observability**.

The first step of debugging is to **stabilize** the system. In the debugging context, we stabilize the problem by creating a test routine that fixes (or stabilizes) all the inputs. Stabilization is an effective approach to debugging because we can control exactly what software is being executed. 
Once stabilized, if we modify the program, we are sure that the change in our outputs is a function of the modification we made in our software and not due to a change in the input parameters.
To stabilize the system we define a fixed set of inputs to test, run the system on these inputs, and record the outputs. 

**Debugging** is a process of finding patterns in the differences between recorded behavior and expected results. The advantage of modular programming is that we can perform modular debugging.

The **debugger** provides three stepping commands **Step**,  **StepOver** and **StepOut** commands. 
* **Step** is the usual execute one assembly instruction.
* **StepOver** will execute one assembly instruction, unless that instruction is a subroutine call, in which case the debugger will execute the entire subroutine and stop at the instruction following the subroutine call.
* **StepOut** assumes the execution has already entered a subroutine, and will finish execution of the subroutine and stop at the instruction following the subroutine call.

A **breakpoint** is a mechanism to tag places in our software, which when executed will cause the software to stop. Normally, you can break on any line of your program. One of the problems with breakpoints is that sometimes we have to observe many breakpoints before the error occurs. 
One way to deal with this problem is the **conditional breakpoint**.
Modern debuggers allow you to set breakpoints that will trigger on a count. However, this method allows flexibility of letting you choose the exact conditions that cause the break.

The use of **print statements** is a popular and effective means for functional debugging. One difficulty with print statements in embedded systems is that a standard “printer” may not be available. 
Another problem with printing is that most embedded systems involve time-dependent interactions with its external environment. The print statement itself may be so slow, that the debugging process itself causes the system to fail.
The print statement is intrusive.