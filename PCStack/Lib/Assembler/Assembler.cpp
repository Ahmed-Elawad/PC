#include <fstream>
#include <iostream>
#include <string>
// import Parser
#include "Parser.cpp"
#include "Code.cpp"
#include "Symbols.cpp"

int main()
{
    // open the input file
    std::string read_file_Name{"testFile.asm"};
    std::string write_file_Name{"testFile.hack"};

    Parser parser{read_file_Name};
    Code codeTables;
    Symbols symbolsTables;
    std::fstream outputFile{write_file_Name, outputFile.out};

    std::string instruction;
    int lineCounter = 0;

    // generate symbols table
    while (parser.hasMoreCommands())
    {
        parser.advance(); // advance to the first line

        if (parser.commandType() == parser.L_COMMAND)
        {
            std::string symb = parser.symbol();
            symbolsTables.addEntry(symb, lineCounter);
        }
        lineCounter++;
    }

    parser.backToTop();

    while (parser.hasMoreCommands())
    {
        parser.advance(); // advance to the first line

        // define the A instruction code
        // get command
        if (parser.commandType() == parser.A_COMMAND)
        {
            std::string symb = parser.symbol();
            parser.padWithZeros(symb, instruction);
        }
        else if (parser.commandType() == parser.C_COMMAND)
        {
            std::string comp = parser.comp();
            std::string dest = parser.dest();
            std::string jmp = parser.jump();
            instruction = "111" + codeTables.aCode(comp) + codeTables.comp(comp) + codeTables.dest(dest) + codeTables.jump(jmp);
        }
        else if (parser.commandType() == parser.L_COMMAND)
        {
            std::string symbol = parser.symbol();
            std::cout << symbol << std::endl;
            if (symbolsTables.contains(symbol))
            {
                int symbol_addres = symbolsTables.getAddress(symbol);
                std::cout << symbol_addres << std::endl;
                std::string symbol_bits = parser.convertIntToStringBits(symbol_addres);
                std::cout << symbol_bits << std::endl;
                parser.padWithZeros(symbol_bits, instruction);
                std::cout << symbol_bits << std::endl;
            }
            std::cout << symbol << std::endl;
        }
    }

    outputFile << instruction << std::endl;
    // write to the line in the output file

    return 0;
}