
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

    bool hasMoreCommands()
    {
        return !readFromFile.eof();
    }

    void advance()
    {
        if (!hasMoreCommands())
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
        else if (current_command[0] == '(' && current_command[(current_command.size() - 1)] == ')')
        {
            current_command_type = CommandType::L_COMMAND;
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
        {
            return current_command.substr(1, current_command.length() - 2);
        }

        if (current_command_type == CommandType::A_COMMAND)
        {
            // if the table contains the sybmol return it's pointer
            // if the symbol is a number return its binary form
            // convert the string to an int
            // convert the int to it's binary form string
            // couple of ways to do this. Read the string from right to left and do bitshifts, use a library

            // could be @R1, @someSymbol, @Rsomesymbol <- handle all
            int start = current_command.find('R');
            if (start == std::string::npos)
                start = 1;
            else
                start = 2;
            // should test the bound
            std::string symbol = current_command.substr(start, current_command.length() - 1);
            int int_symbol = std::stoi(symbol); // what happens if it isn't an int??
            return convertIntToStringBits(int_symbol);
        }

        return "NULL";
    };

    std::string convertIntToStringBits(int int_symbol)
    {
        // do the loop to build the result
        std::string bit_form = "";
        while (int_symbol != 0)
        {
            int remainder = int_symbol % 2;
            if (remainder != 0)
            {
                bit_form = "1" + bit_form;
                int_symbol--;
            }
            else
                bit_form = "0" + bit_form;
            int_symbol /= 2;
        }
        return bit_form;
    }

    void padWithZeros(std::string &str, std::string &instruction)
    {
        size_t n = 16;
        int precision = n - std::min(n, str.size());
        instruction = std::string(precision, '0').append(str);
    }

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
        if (end == std::string::npos)
            end = current_command.length();

        return current_command.substr(start + 1, end - 2);
    };

    std::string jump()
    {
        if (current_command_type != CommandType::C_COMMAND)
            return "NULL";

        int start = current_command.find(';');
        if (start == std::string::npos)
            return "NULL";

        return current_command.substr(start + 1, current_command.length() - 1);
    };

    void backToTop()
    {
        readFromFile.clear();
        readFromFile.seekg(0);
    }

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
