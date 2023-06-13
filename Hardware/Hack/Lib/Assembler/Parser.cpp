
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
            return nullptr;

        if (current_command_type == CommandType::A_COMMAND)
        {
            return current_command.substr(1, current_command.length() - 1);
        }

        if (current_command_type == CommandType::L_COMMAND)
            return nullptr;

        return nullptr;
    };

    std::string dest(){
        // dest=comp;jump
        if (current_command_type != CommandType::C_COMMAND) return nullptr;
        return current_command.substr(0, current_command.find("=") - 1);
    };

    void comp();
    void jump();

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
