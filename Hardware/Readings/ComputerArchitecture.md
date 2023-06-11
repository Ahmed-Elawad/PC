https://www.nand2tetris.org/_files/ugd/44046b_552ed0898d5d491aabafd8a768a87c6f.pdf

There are three core types of information passed throughout the system:
- data
- addresses
- controls

# Stored programs

Pre 1930 mechanical computers raigned supreme. Some contributions from the community came up with a simple but groundbreaking breakthrough which is the foundation of modern computing. Machanical components would no longer have the logic embedded, but would instead store the logic in memory an output some computed result.

# Von Neumann Architecture(1946)

The Von Neumann Architecture is the practical blueprint used for majority if not all modern computing.

The architecture is comprised of a Centeral Processing unit, and memory units. The devices retain the logic to run AND the data to run the logic against.

# Memory

Memory stores the logic and data that the machine runs. In the traditional architecture the data and logic live on the same memory device. There is a 'Harvard Architecture' variant where they are on isolated devices. While the location of the logic and data may be different the components that store them are one and the same - registers. Registers retain the logic and data cercuitry for modern computers.

```
I'm wondering why we do it this way. Might be for simplicities sake, but what if we had the capibilities for multiple CPU units alongside registers that alter their caluclations based on the current and historical data it's operated against?
```

Memory will contain Data memory and program memory. Data memory will contain data and will receive and output data. 

Program memory will recieve addresses and output data either into the data bus or control bits.

## Data memory

Programs manipulate artifacts. These artifacts are actualy a state of bits in a register. When we manipulate some 'value' we are modifying the state of the registers in the hardware.

 ## Instruction memory

 Instruction memory differs from data memory in that it defines the logical operations and computations to run against the data memory registers. Logic is generally stored on the disk and is loaded into instruction memory. High level langagues do not reside in their base form, rather they get translated to binary sequential instructions sometime before they are run.

 ## CPU 

 A Central Processing UNIT(CPU) is the device that ultimately runs the logical operations against the data memory. The cpu is comprised of multiple components that handle the tasks required of the CPU.

 #### ALU

An alu is a chip embedded in the CPU that runs arithmatic operations against sets of binary inputs(circuit states). Any function not supported by the ALU must be implemented at the software level.

The ALU is likely the simplest unit of the computer artifacts. It recieves an input of numbers and does some operations on those numbers. It also recieves control bits which define the computations to be run against the data.

```
The ALU loads information from the data bus and manupulates it using the control bits
```

#### Registers

CPUs contain some count of registers between 2-32(at the time of the writing) which provide a quickly accessible memory(state) local to the devices that need to operate on them(ALU & CPU). This is intended to provide the quick performance Computer.

Registers accept two kinds of information. They recieve and output data from and to the data bus. The second type of information registers receive is address information. Addresses are saved in registers to reference memory locations for data.

#### Control Unit

The control unit is in charge of decoding insturctions and providing the communication between the CPU, registers, and memory(RAM). The CPU does a consistent set of operations while running. This is referred to as the Fetch-execute cycle. Decode, Execute, calculate next instruction, fetch, decode, execute, repeat

### Optimizations

The ALU is quick at doing calculations. To improve performance registers are placed within the CPU for calculations. Some of these registers are used for addressing data locations and others are used as data stores. Without these registers an operation against a value in memory would involve: two chips(CPU, RAM), and two Busses(Address and data). The overhead cost reduction improves performance by placing memory registers closer to the execution of a program.

### I/O

Computer scientists have devised that the devices using the computer should adhere to it's architecture, not the other way. In practice, digital devices define a location in memory for these devices to provide a signal(memory maps). The memory maps act as the representation of the physical devices state. In the example of a keyboard, as the CPU cycles it is checking the state of the keyboard at each cycle. The state of the keys pressed is logged to some memory register and it's expected behaviour is calculated and presented if neccessary.

Since the hardware does not adhere to the device - a contract has been agreed on for handeling device state by computers.  Some examples are:

- Screens are represented as a single vector of x bit wide registers, but visually they represent 2D images.
- Keyboards use a binary mapping of key -> bits. Once connected the os determines a base address and keypresses are read from that address each CPU cycle


## Hack PC Achitecture

The hack PC uses the simplest implementation of the Von Nuemann Architecture. The computer consists of:


- A CPU
- Two I/O devices: Keyboard(I) and screen(O)
- and 3 memory chips:
    - 1 16K RAM card: @RAM[0-16383]
    - 1 8K bit screen card: @RAM[16384-24575]
    - 1 1 bit keyboard card: @RAM[24576]

The top most level chip is the computer chip which consists:
- The cpu
- instruction memory
- and data memory


#### CPU Implementation

<b>Decode the instruction:</b>

An instruction input is a 16 bit state passed into the instruction input pin(s) of the CPU: “ixxaccccccdddjjj”

The Hack Computer uses two op codes for defining procedures - 1 or 0 - stored at i(MSB).

The first bit of an instruction defines the op code:<br/>
A instruction: MSB(i) = 0<br/>
C Instruction: MSB(i) = 1<br/>

Inputs are fed to parts of the CPU simultaniously and each part executes it's respective tasks.

<b>Execute the instruction</b>

The 'i' bit defines whether the ALU computes the 'A' or 'C' instruction

The 'a'(3rd) bit of a 'C' instruction determines the register the ALU will accept input from 'A' or 'M'

The 6 'c'(4-9) bits determine the function the ALU will compute against the input.

The 'D'(10-12) bits determine the destination of the result(output)

And the 'J'(13-15) bits are used to branch to(fetch) the next instruction
- 

