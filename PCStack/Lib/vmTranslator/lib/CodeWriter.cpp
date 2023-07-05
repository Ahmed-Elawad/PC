
/*
NOTE 1:
    Use some form of templating instead of functional operations. Having to extend a function later on will
    be burdonsome if the arguments need to be modified.
NOTE 2:
    Really need to set the values read to 0 otherwise it's tough to debug. Probably how memory leaks occur too.
NOTE 3:
    Increment and decrement of the SP needs to ALWAYS be an effect of SP operations
    PUSH uses RAM[SP], SP++, POPS use RAM[SP-1] - RAM[SP-N], SP-- per pop
NOTE 4:
    Any operation on a Memory location should also clear that memory location
*/

#include <map>

class CodeWriter
{
public:
    CodeWriter(std::string &outputFileName)
    {
        outputFile.open(outputFileName, std::ios::out);
        segmentsTable.insert({"SP", 256});
        segmentsTable.insert({"STATIC", 16});
        segmentsTable.insert({"TEMP", 5});
        segmentsTable.insert({"THIS", 2048});
        segmentsTable.insert({"THAT", 2100});
        segmentsTable.insert({"LCL", 2150});
        segmentsTable.insert({"ARG", 2200});
        segmentsTable.insert({"CONSTANT", 2300});
        writeInitLogic();
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
        if (command == "gt")
            writeGt();
        if (command == "and")
            writeAnd();
        if (command == "not")
            writeNot();
        if (command == "or")
            writeOr();
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
        writeOp("D", "D+1");

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

    void writeGt()
    {
        writeSub();
        writeDecrementSP();
        // load sp value into D
        writePopStackIntoD();

        // write jump conditions
        outputFile << "// if result > 0; set RAM[SP] to true" << std::endl;
        writeSymbol("SETTRUE");
        writeJump("D", "JLT");

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

    void writeAnd()
    {
        // verify both A and B are true: expect either 0 or 1 as states
        writeAdd(); // should always result in 2 if both are true: 1 + 1 === 2 ✅, 0 + 1 === 2 ❌, 0 + 0 === 2 ❌
        // push 2 to the stack(theres a better way but i want this done rn)
        writeSymbol("SP");
        writeOp("A", "M");
        writeOp("M", "1");
        writeIncrementSP();
        writeSymbol("SP");
        writeOp("A", "M");
        writeOp("M", "1");
        writeIncrementSP();
        writeAdd(); // write some function in memory instead of the steps every single time

        // now do equality check
        writeEq();
    }

    void writeNot()
    {

        writeSymbol("SP");
        writeOp("A", "M");
        writeOp("M", "0");
        writeIncrementSP();

        // now do equality check
        writeEq();
    }

    void writeOr()
    {
        // add the two values
        writeAdd();
        writeDecrementSP();
        // pull result into d
        writePopStackIntoD();

        // set to true if d > 0;
        writeSymbol("SETTRUE");
        writeJump("D", "JGT");

        // set false if it's >= 0
        writeSymbol("SETFALSE");
        writeJump("D", "JEQ");

        writeSymbol("SETFALSE");
        writeJump("D", "JLT");

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

    void writePushPop(CommandType commandType, std::string &segment, int index)
    {
        outputFile << "// START: writePushPop" << std::endl;
        // if push: pop from stack, push into segment
        if (commandType == CommandType::C_PUSH)
        {
            writeDecrementSP();
            // calculate the target address
            int targetAddr = segmentsTable[segment] + index;
            // pop the value from the stack into D
            writePopStackIntoD();
            // write the D into the target location
            writeSymbol(std::to_string(targetAddr));
            // push the value into tmp addr
            writeOp("M", "D");
        }

        // if pop: pop from segment, push into stack
        if (commandType == CommandType::C_POP)
        {
            // calculate the target address
            int targetAddr = segmentsTable[segment] + index;
            // pop the value from the stack into D
            writeSymbol(std::to_string(targetAddr));
            writeOp("D", "M");

            writeSymbol("SP");
            // push the value into tmp addr
            writeOp("A", "M");
            writeOp("M", "D");

            writeIncrementSP();
        }

        outputFile << "// END: writePushPop" << std::endl;
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

        writeSymbol("SP");
        writeOp("D", "M");

        writeOp("D", "D-1");
        writeSymbol("SP");
        writeOp("M", "D");

        // write 0 into the current stack value
        // write the new value into the stack
        writeSymbol("SP");
        writeOp("A", "M");
        writeOp("A", "A+1");
        writeOp("M", "0");
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
        outputFile << "// START: init logic" << std::endl;
        // set SP to target test position
        writeSymbol("256");
        writeOp("D", "A");
        writeSymbol("SP");
        writeOp("M", "D");
        writeIncrementSP();
        outputFile << "// END: init logic" << std::endl;
    }

    void close()
    {
        outputFile.close();
    }

    void setTestVal(int val) {
        testVal = val;
    }

private:
    int lineCount = 0;
    std::fstream outputFile;
    std::map<std::string, int> segmentsTable;
    int testVal;
};