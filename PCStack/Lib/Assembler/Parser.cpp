
class Parser
{
public:
    Parser(std::string &fileName)
    {
        readFromFile.open(fileName, readFromFile.in);
    };

    enum CommandType
    {
        A_COMMAND,
        C_COMMAND,
        L_COMMAND
    };


    void advance()
    {
        if (readFromFile.eof())
            return;

        std::getline(readFromFile, current_command, '\n');
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


        if (current_command_type == CommandType::L_COMMAND)
            return "NULL";

        if (current_command_type == CommandType::A_COMMAND)
        {
            // if the table contains the sybmol return it's pointer
            // if the symbol is a number return its binary form
            // convert the string to an int
            // convert the int to it's binary form string
            // couple of ways to do this. Read the string from right to left and do bitshifts, use a library
            std::string symbol = current_command.substr(1, current_command.length() - 1);
            int intSymbol = std::stoi(symbol); // what happens if it isn't an int??
            // do the loop to build the result
            std::string bit_form = "";
            while (intSymbol != 0) {
                int remainder = intSymbol % 2;
                if (remainder != 0) {
                    bit_form = "1" + bit_form;
                    intSymbol--;
                }
                else bit_form = "0" + bit_form;
                intSymbol /= 2;
            }
            return bit_form;
        }

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

        int end = current_command.find(';');
        int start = current_command.find('=');
        if (end == std::string::npos) end = current_command.length();

        return current_command.substr(start + 1, end - 2);
    };

    std::string jump()
    {
        if (current_command_type != CommandType::C_COMMAND)
            return "NULL";

        int start = current_command.find(';');
        if (start == std::string::npos) return "NULL";

        return current_command.substr(start + 1, current_command.length() - 1);
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
