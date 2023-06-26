/*
Parser implementation that handles converting a file to a target type.
Should be able to to convert:
Byte code => Assembly
Assembly => Binary instructions
*/

enum CommandType {
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

class Parser
{
public:
    bool hasMoreLines() {
        return !readFromFile.eof();
    }

    void advance() {
        if (!hasMoreLines()) return;

        std::getline(readFromFile, currentCommand);
    }

    int arg2() {
        if ()
        return 1;
    }

    void setCommandType() {

    }
    
private:
    CommandType currentCommandType;
    std::string currentCommand;
    std::fstream readFromFile;
};
