// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

@SCREEN
D=A
@SCREENSTART
M=D

@8000
D=D+A
@SCREENEND
M=D

@CURRENTSCREENREGISTER
M=D

(WAITLOOP)
@KBD
D=M
@PREBLACKSCREN
D;JGT
@WAITLOOP
0;JMP

(PREBLACKSCREN)
// set current register to screen SCREENSTART
@SCREENSTART
D=M
@CURRENTSCREENREGISTER
M=D
@BLACKSCREENLOOP
0;JMP

(BLACKSCREENLOOP)
@KBD
D=M
@PREWHITESCREEN
D;JEQ

@CURRENTSCREENREGISTER
A=M
M=-1
@CURRENTSCREENREGISTER
M=M+1
@SCREENEND
D=M
@CURRENTSCREENREGISTER
D=D-M
@BLACKSCREENLOOP
D;JGT
@WAITLOOP
0;JMP



(PREWHITESCREEN)
@SCREENSTART
D=M
@CURRENTSCREENREGISTER
M=D
@WHITESCREENLOOP
0;JMP

(WHITESCREENLOOP)
// go to black screen loop if key is pressed
@KBD
D=M
@PREBLACKSCREN
D;JGT


@CURRENTSCREENREGISTER
A=M
M=0
@CURRENTSCREENREGISTER
M=M+1

@SCREENEND
D=M
@CURRENTSCREENREGISTER
D=D-M
@WHITESCREENLOOP
D;JGT
@WAITLOOP
0;JMP

// END LOOP
(END)
@END
0;JMP