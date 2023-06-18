#include <map> // expensive. use hash map
#include <string>

class Symbols
{
public:
    Symbols(){
        symbolsTable.insert({"SP", 0});
        symbolsTable.insert({"LCL", 1});
        symbolsTable.insert({"ARG", 2});
        symbolsTable.insert({"THIS", 3});
        symbolsTable.insert({"THAT", 4});
        // this is a range so it needs to be defined as such
        symbolsTable.insert({"R0", 0});
        symbolsTable.insert({"R1", 1});
        symbolsTable.insert({"R2", 2});
        symbolsTable.insert({"R3", 3});
        symbolsTable.insert({"R4", 4});
        symbolsTable.insert({"R5", 5});
        symbolsTable.insert({"R6", 6});
        symbolsTable.insert({"R7", 7});
        symbolsTable.insert({"R8", 8});
        symbolsTable.insert({"R9", 9});
        symbolsTable.insert({"R10", 10});
        symbolsTable.insert({"R11", 11});
        symbolsTable.insert({"R12", 12});
        symbolsTable.insert({"R13", 13});
        symbolsTable.insert({"R13", 13});
        symbolsTable.insert({"R14", 14});
        symbolsTable.insert({"R15", 15});
        
        symbolsTable.insert({"SCREEN", 16384});
        symbolsTable.insert({"KBD", 24576});
    };

    void addEntry(std::string &symbol, int address)
    {
        std::cout << "adding symbol - " << symbol << " - " << address << std::endl;
        symbolsTable[symbol] = address;
    };

    bool contains(std::string &symbol)
    {
        return symbolsTable.find(symbol) != symbolsTable.end();
    };

    int getAddress(std::string &symbol) {
        if (contains(symbol)) return symbolsTable[symbol];
        return -1;
    };

    int getNextAddress() {
        int ret_val = next_address;
        next_address++;
        return ret_val;
    }
    
    ~Symbols()
    {
        symbolsTable.clear();
    }

private:
    // convert to hash table at some point
    int next_address = 16; // next address is the first address available in memory
    std::map<std::string, int> symbolsTable;
};