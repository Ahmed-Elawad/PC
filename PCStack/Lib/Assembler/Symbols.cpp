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
        symbolsTable.insert({"RO-R15", 0-15});
        symbolsTable.insert({"SCREEN", 16384});
        symbolsTable.insert({"KBD", 24576});
    };

    void addEntry(std::string &symbol, int address)
    {
        if (!contains(symbol)) symbolsTable[symbol] = address;
    };

    bool contains(std::string &symbol)
    {
        return symbolsTable.find(symbol) != symbolsTable.end();
    };

    int getAddress(std::string &symbol) {
        if (contains(symbol)) return symbolsTable[symbol];
        return -1;
    };

    ~Symbols()
    {
        symbolsTable.clear();
    }

private:
    // convert to hash table at some point
    int next_address = 16; // next address is the first address available in memory
    std::map<std::string, int> symbolsTable;
};