https://www.nand2tetris.org/_files/ugd/44046b_552ed0898d5d491aabafd8a768a87c6f.pdf

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

## Data memory

Programs manipulate artifacts. These artifacts are actualy a state of bits in a register. When we manipulate some 'value' we are modifying the state of the registers in the hardware.

 ## Instruction memory

 Instruction memory differs from data memory in that it defines the logical operations and computations to run against the data memory registers. Logic is generally stored on the disk and is loaded into instruction memory. High level langagues do not reside in their base form, rather they get translated to binary sequential instructions sometime before they are run.

 ## CPU 

 A Central Processing UNIT(CPU) is the device that ultimately runs the logical operations against the data memory. The cpu is comprised of multiple components that handle the tasks required of the CPU.

 #### ALU

An alu is a chip embedded in the CPU that runs arithmatic operations against sets of binary inputs(circuit states). Any function not supported by the ALU must be implemented at the software level.

#### Registers

CPUs contain some count of registers between 2-32(at the time of the writing) which provide a quickly accessible memory(state) local to the devices that need to operate on them(ALU & CPU). This is intended to provide the quick performance Computer.

#### Control Unit

The control unit is in charge of decoding insturctions and providing the communication between the CPU, registers, and memory(RAM). The CPU does a consistent set of operations while running. This is referred to as the Fetch-execute cycle. Decode, Execute, calculate next instruction, fetch, decode, execute, repeat

