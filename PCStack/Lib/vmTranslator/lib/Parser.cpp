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
        std::string arg1val = arg0();
        std::cout << "Command Requested - " << arg1val << std::endl;
        if (arg1val == "push")
        {
            return CommandType::C_PUSH;
        }
        if (arg1val == "pop")
        {
            return CommandType::C_POP;
        }
        if (arg1val == "add" || arg1val == "sub" || arg1val == "neg" || arg1val == "eq" || arg1val == "lt" || arg1val == "gt" || arg1val == "and" || arg1val == "not")
        {
            return CommandType::C_ARITHMATIC;
        }

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
        std::cout << "Advanced to: " << line << std::endl;
        currentCommand = line;
    }

    std::string arg0()
    {
        int firstSpace = currentCommand.find(' ');
        return currentCommand.substr(0, firstSpace);
    }

    std::string arg1()
    {
        if (currentCommandType == CommandType::C_RETURN)
            return "";

        int fisrtSpace = currentCommand.find(' ');
        int secondSpace = currentCommand.find(' ', fisrtSpace);
        return currentCommand.substr(fisrtSpace, secondSpace);
    }

    int arg2()
    {
        CommandType command = commandTyoe();
        if (command != CommandType::C_PUSH ||
            command != CommandType::C_POP ||
            command != CommandType::C_FUNCTION ||
            command != CommandType::C_CALL)
        {
            return -1;
        }

        int fisrtSpace = currentCommand.find(' ');
        int secondSpace = currentCommand.find(' ', fisrtSpace);
        return std::stoi(currentCommand.substr(secondSpace, currentCommand.length()));
    }

private:
    CommandType currentCommandType;
    std::string currentCommand;
    std::fstream readFromFile;
};
