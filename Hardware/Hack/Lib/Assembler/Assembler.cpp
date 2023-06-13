#include <fstream>
#include <iostream>
#include <string>
// import Parser
#include "Parser.cpp"

int main() {
    // open the input file
    std::string fileName{"testFile.asm"};
    
    Parser parser{fileName};

    parser.advance();
    std::cout << "symbol: " << parser.symbol() << std::endl; // 123456
    std::cout << "hasModelines: " << parser.hasMoreCommands() << std::endl;

    parser.advance();
    // resolve error
    /*
        symbol: terminate called after throwing an instance of 'std::logic_error'
        what():  basic_string::_M_construct null not valid
    */
    std::cout << "symbol: " << parser.symbol() << std::endl; // D=M
    parser.advance();
    // for each instruction concatonate the binary code
        // if an A instruction: translate the decimal to binary and write the line to the output file
        // if a C instruction: 
            // concatonate the binary instructions using the code table
            // write the line to the output file
    // close the input file
    // close the output file
    return 0;
}