
enum CommandType
{
    C_ARITHMATIC,
    C_PUSH,
    C_POP,
    C_LABEL,
    C_GOTO,
    C_IF,
    C_FUNCTION,
    C_RETURN,
    C_CALL
};

class CodeWriter
{
public:
    CodeWriter(std::string &outputFileName)
    {
        outputFile.open(outputFileName, std::ios::out);
    }

    void writeArithmatic(std::string command)
    {
        // write the arithmatic command lines
    }

    void writePushPop(CommandType commandType, std::string segment, int index)
    {
        // write the push pop instructions
    }

    void close()
    {
        outputFile.close();
    }

private:
    std::fstream outputFile;
};