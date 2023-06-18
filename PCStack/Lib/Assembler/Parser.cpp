
class Parser
{
public:
    // define an enum of command types
    enum CommandType
    {
        A_COMMAND,
        C_COMMAND,
        L_COMMAND,
        SKIP_COMMAND
    };

    Parser(std::string &fileName)
    {
        readFromFile.open(fileName, std::ios::in);
        if (!readFromFile.is_open())
        {
            std::cout << "Error opening file: " << fileName << std::endl;
            exit(1);
        }
    }

    bool hasMoreCommands()
    {
        return !readFromFile.eof();
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
            if (hasMoreCommands())
                return advance();
            else
                return;
        }

        for (int i = 0; i < line.length(); i++)
        {

            if (line[i] != ' ' && line[i] != '\t')
            {
                currentCommand += line[i];
            }
        }
    }

    CommandType commandType()
    {
        return currentCommandType;
    }

    void setCommandType()
    {
        if (currentCommand[0] == '@')
        {
            currentCommandType = A_COMMAND;
        }
        else if (currentCommand[0] == '(')
        {
            currentCommandType = L_COMMAND;
        }
        else if ( !currentCommand.length() || (currentCommand[0] == '/' && currentCommand[1] == '/'))
        {
            std::cout << "SKIP_COMMAND" << std::endl;
            currentCommandType = SKIP_COMMAND;
        }
        else
        {
            currentCommandType = C_COMMAND;
        }
    }

    std::string symbol()
    {
        if (currentCommandType == C_COMMAND)
        {
            std::cout << "Error: symbol() called on C_COMMAND" << std::endl;
            exit(1);
        }

        if (currentCommand[0] == '(')
        {
            return currentCommand.substr(1, currentCommand.length() - 2);
        }
        else
        {
            return currentCommand.substr(1, currentCommand.length() - 1);
        }
    }

    std::string dest()
    {
        // dest only returend if there's an == sign
        if (currentCommandType != C_COMMAND)
        {
            std::cout << "Error: dest() called on non C_COMMAND" << std::endl;
            exit(1);
        }

        int equalPos = currentCommand.find('=');
        if (equalPos != std::string::npos)
        {
            return currentCommand.substr(0, equalPos);
        }
        else
        {
            return "NULL";
        }
    }

    std::string comp() {
        if (currentCommandType != C_COMMAND)
        {
            std::cout << "Error: comp() called on non C_COMMAND" << std::endl;
            exit(1);
        }

        int equalPos = currentCommand.find('=');
        int semiPos = currentCommand.find(';');
        std::cout << "currentCommand: " << currentCommand << std::endl;
        if (equalPos != std::string::npos)
        {
            if (semiPos != std::string::npos)
            {
                return currentCommand.substr(equalPos + 1, semiPos - equalPos - 1);
            }
            else
            {
                return currentCommand.substr(equalPos + 1, currentCommand.length() - equalPos - 1);
            }
        }
        else
        {
            if (semiPos != std::string::npos)
            {
                return currentCommand.substr(0, semiPos);
            }
            else
            {
                return currentCommand;
            }
        }
        return "NULL";
    }

    std::string jump() {
        if (currentCommandType != C_COMMAND)
        {
            std::cout << "Error: jump() called on non C_COMMAND" << std::endl;
            exit(1);
        }

        int semiPos = currentCommand.find(';');
        if (semiPos != std::string::npos)
        {
            return currentCommand.substr(semiPos + 1, currentCommand.length() - semiPos - 1);
        }
        else
        {
            return "NULL";
        }
    }

    bool isNumber(std::string &str)
    {
        // skip '@' and '@R'
        if (str[0] == '@')
        {
            str = str.substr(1, str.length() - 1);
        }
        else if (str[0] == '@' && str[1] == 'R')
        {
            str = str.substr(2, str.length() - 2);
        }

        for (int i = 0; i < str.length(); i++)
        {
            if (!isdigit(str[i]))
            {
                return false;
            }
        }
        return true;
    }

    void toTop()
    {
        readFromFile.clear();
        readFromFile.seekg(0, std::ios::beg);
    }

    // cleanup
    ~Parser()
    {
        readFromFile.close();
    };

private:
    std::fstream readFromFile;
    std::string currentCommand = "";
    CommandType currentCommandType;
};
