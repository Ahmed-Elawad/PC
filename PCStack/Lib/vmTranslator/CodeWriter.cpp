

class CodeWriter
{
public:
    CodeWriter(std::string &outputFileName)
    {
        outputFile.open(outputFileName, std::ios::out);
    }

    void writeArithmatic(std::string command)
    {
        if (command == "add")
            writeAdd();
        if (command == "sub")
            writeSub();
        if (command == "neg")
            writeNeg();
        if (command == "eq")
            writeEq();
        if (command == "lt")
            writeLt();
    }

    void writeAdd()
    {
        // go to the last position
        writeDecrementSP();

        // pop the stack value into RAM[TMP]
        writePopStackIntoD();
        writeSymbol("TMP");
        writeOp("M", "D");

        // decrement the stack pointer
        writeDecrementSP();

        // load the value of the stack pointer into D
        writePopStackIntoD();

        // load the temp value into A
        writeSymbol("TMP");
        writeOp("A", "M");

        // set D = D + A
        writeOp("D", "D+A");

        // write the new value into the stack
        writeSymbol("SP");
        writeOp("A", "M");
        writeOp("M", "D");

        // increment to the next position
        writeIncrementSP();
    }

    void writeSub()
    {
        outputFile << "// START writeSub" << std::endl;
        // go to the last position
        writeDecrementSP();

        // pop the stack value into RAM[TMP]
        writePopStackIntoD();
        writeSymbol("TMP");
        writeOp("M", "D");

        // decrement the stack pointer
        writeDecrementSP();

        // load the value of the stack pointer into D
        writePopStackIntoD();

        // load the temp value into A
        writeSymbol("TMP");
        writeOp("A", "M");

        // set D = D + A
        writeOp("D", "D-A");

        // write the new value into the stack
        writeSymbol("SP");
        writeOp("A", "M");
        writeOp("M", "D");

        // increment to the next position
        writeIncrementSP();
        outputFile << "// END writeSub" << std::endl;
    }

    void writeNeg()
    {
        writeDecrementSP();
        writePopStackIntoD();

        // write into D negated A
        writeOp("D", "!D");

        // load d into RAM[sp]
        writeSymbol("SP");
        writeOp("A", "M");
        writeOp("M", "D");

        writeIncrementSP();
    }

    void writeEq()
    {
        writeSub();
        writeDecrementSP();
        // load sp value into D
        writePopStackIntoD();

        // write jump conditions
        writeSymbol("SETTRUE");
        writeJump("D", "JEQ");

        writeSymbol("SETFALSE");
        writeJump("D", "JNE");

        // define a jump point
        outputFile << "(SETTRUE)" << std::endl;
        // Write the jump point logic: set RAM[SP] = true(1)
        writeSymbol("SP");
        writeOp("A", "M");
        writeOp("M", "1");
        writeSymbol("END");
        writeJump("0", "JMP");

        // define a jump point
        outputFile << "(SETFALSE)" << std::endl;
        // Write the jump point logic: set RAM[SP] = true(1)
        writeSymbol("SP");
        writeOp("A", "M");
        writeOp("M", "0");
        writeSymbol("END");
        writeJump("0", "JMP");
    }

    void writeLt()
    {
        writeSub();
        writeDecrementSP();
        // load sp value into D
        writePopStackIntoD();

        // write jump conditions
        outputFile << "// if result > 0; set RAM[SP] to true" << std::endl;
        writeSymbol("SETTRUE");
        writeJump("D", "JGT");

        outputFile << "// if result is anything else; set RAM[SP] to false" << std::endl;
        writeSymbol("SETFALSE");
        writeJump("0", "JMP");

        outputFile << "// function setting RAM[SP] true" << std::endl;
        // define a jump point
        outputFile << "(SETTRUE)" << std::endl;
        // Write the jump point logic: set RAM[SP] = true(1)
        writeSymbol("SP");
        writeOp("A", "M");
        writeOp("M", "1");
        writeSymbol("END");
        writeJump("0", "JMP");

        outputFile << "// function setting RAM[SP] false" << std::endl;
        // define a jump point
        outputFile << "(SETFALSE)" << std::endl;
        // Write the jump point logic: set RAM[SP] = true(1)
        writeSymbol("SP");
        writeOp("A", "M");
        writeOp("M", "0");
        writeSymbol("END");
        writeJump("0", "JMP");
    }

    void writePushPop(CommandType commandType, std::string segment, int index)
    {
        // write the push pop instructions
    }

    /********************
     * Utility functions for writing repetitive commands
     */
    void writeSymbol(std::string addr)
    {
        outputFile << "@" + addr << std::endl;
        lineCount++;
    }

    void writeOp(std::string dest, std::string comp)
    {
        outputFile << dest + " = " + comp << std::endl;
        lineCount++;
    }

    void writeJump(std::string comp, std::string jmp)
    {
        outputFile << comp + ";" + jmp << std::endl;
        lineCount++;
    }

    void writeEndLoop()
    {
        outputFile << "(END)" << std::endl;
        outputFile << "@" << lineCount << std::endl;
        outputFile << "0;JMP" << std::endl;
    }

    void writeIncrementSP()
    {
        writeSymbol("SP");
        writeOp("D", "M");
        writeOp("D", "D+1");
        writeSymbol("SP");
        writeOp("M", "D");
    }

    void writeDecrementSP()
    {
        // write 0 into the current stack value
        // write the new value into the stack
        // writeSymbol("SP");
        // writeOp("A", "M");
        // writeOp("M", "0");

        writeSymbol("SP");
        writeOp("D", "M");

        writeOp("D", "D-1");
        writeSymbol("SP");
        writeOp("M", "D");
    }

    void writePopStackIntoD()
    {
        writeSymbol("SP");
        writeOp("A", "M");
        writeOp("D", "M");
    }

    void writeLoadDtoTMP()
    {
        writeSymbol("TMP");
        writeOp("M", "D");
    }

    void writeInitLogic()
    {
        // set SP to target test position
        writeSymbol("258");
        writeOp("D", "A");
        writeSymbol("SP");
        writeOp("M", "D");
    }

    void close()
    {
        outputFile.close();
    }

private:
    int lineCount = 0;
    std::fstream outputFile;
    int stackPointerAddr = 256;
    int staticPointerAddr = 16;
    int tempPointerAddr = 5;
};