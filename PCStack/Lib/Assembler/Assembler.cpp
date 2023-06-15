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
    // a_instruction : 0000000000000016 need to convert to binary

    parser.advance(); // advance to the c command
    std::string comp =  parser.comp();
    std::string dest =  parser.dest();
    std::string jmp =  parser.jump();

    // combine the instruction
    // don't always want to construct if there is no c instruction
    std::string c_instruction = "111" + codeTables.aCode(comp) +  codeTables.comp(comp) + codeTables.dest(dest) + codeTables.jump(jmp);
    return 0;
}