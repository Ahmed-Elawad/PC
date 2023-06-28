/*
Parser implementation that handles converting a file to a target type.
Should be able to to convert:
Byte code => Assembly
Assembly => Binary instructions
*/

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

class Parser
{
public:
    Parser(std::string &fileName)
    {
        readFromFile.open(fileName, std::ios::in);
        if (!readFromFile.is_open())
        {
            std::cout << "Error opening file: " << fileName << std::endl;
            exit(1);
        }
    }

    bool hasMoreLines()
    {
        return !readFromFile.eof();
    }

    CommandType commandTyoe()
    {
        return currentCommandType;
    }

    void advance()
    {
        if (currentCommand.length())
            currentCommand = "";

        std::string line;
        std::getline(readFromFile, line);
        int slashPos = line.find('/');
        if (slashPos != std::string::npos || !line.length())
        {
            if (hasMoreLines())
                return advance();
            else
                return;
        }
        currentCommand = line;
    }

    void setCommandType()
    {
    }

    std::string arg1()
    {
        if (currentCommandType == CommandType::C_RETURN)
            return "";

        int space = currentCommand.find(' ');
        return currentCommand.substr(0, space);
    }

    int arg2()
    {
        if (currentCommandType == CommandType::C_PUSH ||
            currentCommandType == CommandType::C_POP ||
            currentCommandType == CommandType::C_FUNCTION ||
            currentCommandType == CommandType::C_CALL)
        {
            return -1;
        }


        int fisrtSpace = currentCommand.find(' ');
        int secondSpace = currentCommand.find(' ', fisrtSpace);
        return std::stoi(currentCommand.substr(fisrtSpace, secondSpace));
    }

private:
    CommandType currentCommandType;
    std::string currentCommand;
    std::fstream readFromFile;
};
