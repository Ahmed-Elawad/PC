#include <map> // expensive. use hash map
#include <string>

class Symbols
{
public:
    Symbols();

    void addEntry();
    void contains();
    void getAddress();

    ~Symbols(){
        symbolsTable.clear();
    }

private:
    // convert to hash table at some point
    int next_address; // next address is the first address available in memory
    std::map<std::string, std::string> symbolsTable;
};