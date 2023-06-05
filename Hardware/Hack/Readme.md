# Why

Want to look at a computer and see nothing but a complicated hammer

# Project Description

Building Tetris following guidlines in ["Nand to Tetris"](). 

- build basic logic gates
- build abstractions that resolve in a basic computer

# Structure

TBD but will probably be

- Hardware
    - Contains the hardware components like gates, chips, and interfaces
- software
    - contains the software components for the system
- GUI
    - Uses the hardware and software components to provide a visual interface

# Architecture

Hack computer will use a 16-bit architecture to represent it's atomic unit of information.

It will consist of a instruction memory, CPU, and data memory.

Data Memory: 
- a sequence of 16-bit registers
- RAM[0], RAM[1], ... RAM[n]

Instruction Memory:
- a sequence of 16-bit registers
- ROM[0], ROM[1], ... ROM[n]

CPU(Central Processing Unit):
- Performs 16-bit instructions

Buses: a bus moves 16 bits of data between the components
- instruction: to cary instructions
- data: to carry data 
- address: to carry addresses

Software will control the Hack computer. The software will be implemented in the hack machine language:
- 16-bit A instructions
- 16-bit C instructions
    - each are specified as a 16 bit number


Hack program: A sequence of 16-bit instructions written in the hack machine language

The computer recognizes only 3 registers as artifacts:
- D: 16-bit value
- A: 16-bit value
    - data address or value
- M: 16-bit RAM register addressed by a
    - Selected memory register
    - only 1 register is selected at a time

# Control

A reset button will be part of the architecture.

- ROM is loaded with the Hack Program
- reset button clicked
- Program runs


