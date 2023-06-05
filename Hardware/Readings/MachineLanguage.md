# Machne lang notes

- Machine language provides instructions to the hardware to produce an output. 

# Elements

- A sequence of instructions tells the computer what to do.
- active instructions: how will the machine know which instructionis to do
- Input: the instructions have to provide the values which the operations run on

Machine language is the interface between: software > hardware
generally done with a 1-1 correspondence between the machine language and the the hardware implementation

Machine languages provide sets of operations
- Arithmatic
- Logical
- flow control

Some differences include:
- richness of libraries
- Data types - available primitive values

# Memory

Memory access is expensive:
- need to tell the hardware the location of the values to operate on
- Reads are slow compared to the CPU speed

Memory hierarchy provides the mechanism of improving the performance of an application

CPU:
    - Registers fastest and working state
        - built from fastest tech available
        - built into CPU
        - Types:
            - Data registers: Contains data
            - Address Registers: retains references
Cache:
    - sequences of small registers close to the CPU registers close to CPU
Main Memory:
    - 
Disk:
    - Solid state memory

Addressing Modes:
    - Register: ADD r1, r2
        - does an operation on two registers
    - Direct
        - ADD R1, M[100]
        - tells the computer to address register one and add it to a specified memory address
        - directly address rq and the mem address
    - indirect
        - ADD r1, @A
        - add r1 to a reference
        - mem reference is written on an address register
    - Immediate
        - add 10, r1
        - 10 is a constant: 1010

# I/O

I/O devices read and write some stream of bits to a register.
- for a mouse use the position a mouse is moved to write some value to a register, then output that position onto the screen
- CPU needs a protocol to handle the input: Drivers
- Memory mapping is a method of defining the kinds of interaction behaviors

# Flow control

How to tell the hardware what operation to execute

CPUs execute instructions in sequence

Some operations require looping over a sequence of executables

```
JGT R1, 0 , cont
Subtract R1, 0, R!
cont:
// do something else
```

# Design

Cost - Performance tradeoff

Sophistication = greater cost
- time to completion of instruction
- cost in resources: silicon

# Process of code to actions

Higher Level Language > compiler > machine language > CPU(machine)


# Glossary

Instruction: sequences of bits - 0111000|0011|0010

Mnemonics: 
    - 0111000 = Add
    - 0011 = r3
    - 0010 = r2

Assembler: convert 

# nmumonics vs binary

An assembler takes the symbolic language and converts it to binary for the machine to execute. The translation is very closely tied to the hardware implementation of the machine.

```
Hack machine example

Symbolic syntax: @value
value is a non negative number at most 2^15 -1
```

Instruction | Symbol | Binary
---| --- | ---
A | @21 | 0000-0000-0001-0101
c | dest = comp ; jump | 1110000000000000

```
A instruction notes:
set the value of the A(Address) register to 1

first bit specifies the op code: 0 = A instruction
final bits represent the value: value = 21 (0001-0101)

C instruction:
dest = comp ; jump
if the destination = the computation and the computation = 0 jump to the address registers location

1st bit = op code
'1' = c

next two bits are unused
'11' = unused

next 7 bits specify the computation to be done:
Bits that are passed to the alu to do the computation on the value in the A register


the next 3 bits define the destination of the result

the final 3 bits represent the jump condition

```