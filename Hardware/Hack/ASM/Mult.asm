// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies 
//
// This program only needs to handle arguments that satisfy
// R0 >= 0, R1 >= 0, and R0*R1 < 32768.

@R2
M=0

@R0
D=M

@20
D;JLE

@R1
D=M

@20
D;JLE

@R1
D=M

@R2
M=M+D

// decrement R3
@R0
D=M-1

@R0
M=D

@10
D;JNE

@20
0;JMP