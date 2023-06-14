
class Parser
{
public:
    Parser(std::string &fileName)
    {
        std::cout << "Parser constructor " << fileName << std::endl;
        readFromFile.open(fileName, readFromFile.in);
    };

    enum CommandType
    {
        A_COMMAND,
        C_COMMAND,
        L_COMMAND
    };

    bool hasMoreCommands()
    {
        return !readFromFile.eof();
    };

    void advance()
    {
        if (!hasMoreCommands())
            return;

        std::getline(readFromFile, current_command, '\n');
        std::cout << current_command << std::endl;
        setCommantType();
    };

    void setCommantType()
    {
        if (current_command[0] == '@')
        {
            current_command_type = CommandType::A_COMMAND;
        }
        else
        {
            current_command_type = CommandType::C_COMMAND;
        }
    }

    CommandType commandType()
    {
        return current_command_type;
    };

    std::string symbol()
    {
        if (current_command_type == CommandType::C_COMMAND)
            return "NULL";

        if (current_command_type == CommandType::A_COMMAND)
        {
            return current_command.substr(1, current_command.length() - 1);
        }

        if (current_command_type == CommandType::L_COMMAND)
            return "NULL";

        return "NULL";
    };

    std::string dest()
    {
        // dest=comp;jump
        if (current_command_type != CommandType::C_COMMAND)
            return "NULL";
        return current_command.substr(0, current_command.find("="));
    };

    std::string comp()
    {
        if (current_command_type != CommandType::C_COMMAND)
            return "NULL";
            // mmight not always have a jump
        return current_command.substr(current_command.find('=') + 1, current_command.find(';') - 2);
    };

    std::string jump()
    {
        if (current_command_type != CommandType::C_COMMAND)
            return "NULL";
        // define some constant to indicate an non found value
        if (current_command.find(';') > current_command.length()) return nullptr;
        return current_command.substr(current_command.find(';') + 1, current_command.length() - 1);
    };

    // cleanup
    ~Parser()
    {
        readFromFile.close();
    };

private:
    std::string current_command;
    std::fstream readFromFile;
    CommandType current_command_type;
};
