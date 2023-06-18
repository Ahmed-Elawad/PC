// contains the symbols table
#include <map>
#include <string>

class Code
{
public:
    Code()
    {
        dest_table.insert({"NULL", "000"});
        dest_table.insert({"M", "001"});
        dest_table.insert({"D", "010"});
        dest_table.insert({"MD", "011"});
        dest_table.insert({"A", "100"});
        dest_table.insert({"AM", "101"});
        dest_table.insert({"AD", "110"});
        dest_table.insert({"AMD", "111"});

        dest_table.insert({"NULL", "0000000"});
        comp_Table.insert({"0", "0101010"});
        comp_Table.insert({"1", "0111111"});
        comp_Table.insert({"-1", "0111010"});
        comp_Table.insert({"D", "0001100"});
        comp_Table.insert({"A", "0110000"});
        comp_Table.insert({"!D", "0001101"});
        comp_Table.insert({"!A", "0110001"});
        comp_Table.insert({"-D", "0001111"});
        comp_Table.insert({"-A", "0110011"});
        comp_Table.insert({"D+1", "0011111"});
        comp_Table.insert({"A+1", "0110111"});
        comp_Table.insert({"D-1", "0001110"});
        comp_Table.insert({"A-1", "0110010"});
        comp_Table.insert({"D+A", "0000010"});
        comp_Table.insert({"D-A", "0010011"});
        comp_Table.insert({"A-D", "0000111"});
        comp_Table.insert({"D&A", "0000000"});
        comp_Table.insert({"D|A", "0010101"});
        comp_Table.insert({"M", "1110000"});
        comp_Table.insert({"!M", "1110001"});
        comp_Table.insert({"-M", "1110011"});
        comp_Table.insert({"M+1", "1110111"});
        comp_Table.insert({"M-1", "1110010"});
        comp_Table.insert({"D+M", "1000010"});
        comp_Table.insert({"D-M", "1010011"});
        comp_Table.insert({"M-D", "1000111"});
        comp_Table.insert({"D&M", "1000000"});
        comp_Table.insert({"D|M", "1010101"});

        jump_table.insert({"NULL", "000"});
        jump_table.insert({"JGT", "001"});
        jump_table.insert({"JEQ", "010"});
        jump_table.insert({"JGE", "011"});
        jump_table.insert({"JLT", "100"});
        jump_table.insert({"JNE", "101"});
        jump_table.insert({"JLE", "110"});
        jump_table.insert({"JMP", "111"});

       
    }

    std::string dest(std::string &destCode)
    {
        return dest_table[destCode];
    }

    std::string comp(std::string &compCode)
    {
        return comp_Table[compCode];
    }

    std::string aCode(std::string &compCode)
    {
        return a_Table[compCode];
    }

    std::string jump(std::string &jumpCode)
    {
        return jump_table[jumpCode];
    }

    void symbolLocation(std::string &symbol)
    {
        // return the symbols value
    }

    void addSymbol(std::string &symbol)
    {
        // add a symbol with a value
    }

    ~Code()
    {
        // clean up dest table
        if (dest_table.size())
        {
            dest_table.clear();
        }

        // clean up symbols table
        if (comp_Table.size())
        {
            comp_Table.clear();
        }

        // cleanup comp table
        if (jump_table.size())
        {
            jump_table.clear();
        }

        // cleanup jump table
    }

private:
    std::map<std::string, std::string> dest_table;
    std::map<std::string, std::string> comp_Table;
    std::map<std::string, std::string> jump_table;
    std::map<std::string, std::string> a_Table;
};
