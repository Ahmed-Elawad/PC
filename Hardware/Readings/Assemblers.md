Assemblers convert assembly level langague to the binary representation of the instructions the computer should do. 

Assemblers generally store tables of symbols and definitions and convert the high level code into the instructions.

# Parsing

Instructions written in assembly are first parsed by an artifact of the assembler. Generally there will be syntax tables that provide the definitions that map a symbol to it's instructional representation.

The process is generally to break the input into it's symbolic representative sections, look up the symbol, construct the instruction section, and repeat.

```
This is an example for the Hack language which runs on a 16-bit system comprising of 1 memory chip and one ROM program chip.

Symbolic syntax:
dest = comp; jump

MD=D+1
```

Program constructors take the instructions and generate the symbolic representation of the code. 


# Assembly logic - without symbols

given a text file
step through the lines in the file

for each line 
    parse the line into it's fields
        A instruction
            break it into it's fields
        c instruction 
            dest= comp ; jump
            for each field generat the binary code
    Assemble the binary component into a single instruction
    write the 16 bits to a binary file


    
    