

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
            writeEq();
    }

    void writeAdd()
    {
        // go to the last position
        writeDecrementSP();

        // pop the stack value into RAM[TMP]
        writeSymbol("SP");
        writeOp("A", "M");
        writeOp("D", "M");
        writeSymbol("TMP");
        writeOp("M", "D");

        // decrement the stack pointer
        writeDecrementSP();

        // load the value of the stack pointer into D
        writeSymbol("SP");
        writeOp("A", "M");
        writeOp("D", "M");

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
        // go to the last position
        writeDecrementSP();

        // pop the stack value into RAM[TMP]
        writeSymbol("SP");
        writeOp("A", "M");
        writeOp("D", "M");
        writeSymbol("TMP");
        writeOp("M", "D");

        // decrement the stack pointer
        writeDecrementSP();

        // load the value of the stack pointer into D
        writeSymbol("SP");
        writeOp("A", "M");
        writeOp("D", "M");

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
    }

    void writeNeg()
    {
        writeDecrementSP();
        writeSymbol("SP");
        writeOp("A", "M");
        writeOp("D", "M");

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
    }

    void writeLt()
    {
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

    void writeEndLoop()
    {
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
        writeSymbol("SP");
        writeOp("D", "M");
        writeOp("D", "D-1");
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