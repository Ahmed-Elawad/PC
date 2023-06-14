// contains the symbols table
#include <map>
#include <string>

class Code
{
public:
    Code()
    {
        // poplate the dest table
        dest_table.insert({"NULL", "000"});
        dest_table.insert({"M", "001"});
        dest_table.insert({"D", "010"});
        dest_table.insert({"DM", "011"});
        dest_table.insert({"A", "100"});
        dest_table.insert({"AM", "101"});
        dest_table.insert({"AD", "110"});
        dest_table.insert({"ADM", "111"});
        // poplate the comp table 
        comp_Table.insert({"NULL", "000000"});
        comp_Table.insert({"0", "101010"});
        comp_Table.insert({"1", "111111"});
        comp_Table.insert({"-1", "111010"});
        comp_Table.insert({"D", "001100"});
        comp_Table.insert({"A", "110000"});
        comp_Table.insert({"M", "110000"});
        comp_Table.insert({"!D", "001101"});
        comp_Table.insert({"!A", "110001"});
        comp_Table.insert({"!M", "110001"});
        comp_Table.insert({"-D", "001111"});
        comp_Table.insert({"-A", "110011"});
        comp_Table.insert({"-M", "110011"});
        comp_Table.insert({"D+1", "011111"});
        comp_Table.insert({"A+1", "110111"});
        comp_Table.insert({"M+1", "110111"});
        comp_Table.insert({"D-1", "001110"});
        comp_Table.insert({"A-1", "110010"});
        comp_Table.insert({"M-1", "110010"});
        comp_Table.insert({"D+A", "000010"});
        comp_Table.insert({"D+M", "000010"});
        comp_Table.insert({"D-A", "010011"});
        comp_Table.insert({"D-M", "010011"});
        comp_Table.insert({"A-D", "000111"});
        comp_Table.insert({"M-D", "000111"});
        comp_Table.insert({"D&A", "000000"});
        comp_Table.insert({"D&M", "000000"});
        comp_Table.insert({"D|A", "010101"});
        comp_Table.insert({"D|M", "010101"});
        comp_Table.insert({"NULL", "000000"});
        // and redundantly an a table. define some tuple later
        a_Table.insert({"NULL", "0"});
        a_Table.insert({"0", "0"});
        a_Table.insert({"1", "0"});
        a_Table.insert({"-1", "0"});
        a_Table.insert({"D", "0"});
        a_Table.insert({"A", "0"});
        a_Table.insert({"M", "1"});
        a_Table.insert({"!D", "0"});
        a_Table.insert({"!A", "0"});
        a_Table.insert({"!M", "1"});
        a_Table.insert({"-D", "0"});
        a_Table.insert({"-A", "0"});
        a_Table.insert({"-M", "1"});
        a_Table.insert({"D+1", "0"});
        a_Table.insert({"A+1", "0"});
        a_Table.insert({"M+1", "1"});
        a_Table.insert({"D-1", "0"});
        a_Table.insert({"A-1", "0"});
        a_Table.insert({"M-1", "1"});
        a_Table.insert({"D+A", "0"});
        a_Table.insert({"D+M", "1"});
        a_Table.insert({"D-A", "0"});
        a_Table.insert({"D-M", "1"});
        a_Table.insert({"A-D", "0"});
        a_Table.insert({"M-D", "1"});
        a_Table.insert({"D&A", "0"});
        a_Table.insert({"D&M", "1"});
        a_Table.insert({"D|A", "0"});
        a_Table.insert({"D|M", "1"});
        // poplate the jump_table table
        jump_table.insert({"NULL", "000"});
        jump_table.insert({"M", "001"});
        jump_table.insert({"D", "010"});
        jump_table.insert({"A", "100"});
        jump_table.insert({"DM", "011"});
        jump_table.insert({"AM", "101"});
        jump_table.insert({"AD", "110"});
        jump_table.insert({"ADM", "111"});
    }

    std::string dest(std::string &destCode)
    {
        if (dest_table.find(destCode) != dest_table.end())
            return dest_table[destCode];

        return dest_table["NULL"];
    }

    std::string comp(std::string &compCode)
    {
        if (comp_Table.find(compCode) != comp_Table.end())
            return comp_Table[compCode];

        return comp_Table["NULL"];
    }

    std::string aCode(std::string &compCode)
    {
        if (a_Table.find(compCode) != a_Table.end())
            return a_Table[compCode];

        return a_Table["NULL"];
    }

    std::string jump(std::string &jumpCode)
    {
        if (jump_table.find(jumpCode) != jump_table.end())
            return jump_table[jumpCode];

        return jump_table["NULL"];
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
