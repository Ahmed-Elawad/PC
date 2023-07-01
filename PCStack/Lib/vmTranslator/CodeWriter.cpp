

class CodeWriter
{
public:
    CodeWriter(std::string &outputFileName)
    {
        outputFile.open(outputFileName, std::ios::out);
    }

    void writeArithmatic(std::string command)
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