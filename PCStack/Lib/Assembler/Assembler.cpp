#include <fstream>
#include <iostream>
#include <string>
// import Parser
#include "Parser.cpp"
#include "Code.cpp"

int main() {
    // open the input file
    std::string fileName{"testFile.asm"};
    
    Parser parser{fileName};
    Code codeTables;

    // start parsing
    parser.advance(); // advance to the first line
    
    // define the A instruction code
    std::string symbol = parser.symbol();
    size_t n = 16;
    int precision = n - std::min(n, symbol.size());
    std::string a_instruction = std::string(precision, '0').append(symbol);
    std::cout << "a_instruction : " << a_instruction  << std::endl; // 
    // a_instruction : 0000000000000016 need to convert to binary



    parser.advance(); // advance to the c command
    std::string comp =  parser.comp();
    std::string dest =  parser.dest();
    std::string jmp =  parser.jump();

    // combine the instruction
    std::string c_instruction = "111" + codeTables.aCode(comp) + codeTables.dest(dest) + codeTables.comp(comp) + codeTables.jump(jmp);
    std::cout << "c_instruction : " << c_instruction  << std::endl; // dest=comp;jump
    // terminate called after throwing an instance of 'std::logic_error'
    // what():  basic_string::_M_construct null not valid
    // caused by line M=1, has no jump clause(;jmp)
    // need to correct parser to handle null inputs while searching for a string

    return 0;
}