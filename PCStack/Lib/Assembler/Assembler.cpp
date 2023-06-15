#include <fstream>
#include <iostream>
#include <string>
// import Parser
#include "Parser.cpp"
#include "Code.cpp"

int main()
{
    // open the input file
    std::string read_file_Name{"testFile.asm"};
    std::string write_file_Name{"testFile.hack"};

    Parser parser{read_file_Name};
    Code codeTables;
    std::fstream outputFile{write_file_Name, outputFile.out};

    std::string instruction;
    while (parser.hasMoreCommands())
    {
        parser.advance(); // advance to the first line

        // define the A instruction code
        // get command
        if (parser.commandType() == parser.A_COMMAND)
        {
            std::string symbol = parser.symbol();
            size_t n = 16;
            int precision = n - std::min(n, symbol.size());
            instruction = std::string(precision, '0').append(symbol);
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
        }

        outputFile << instruction << std::endl;
        // write to the line in the output file
    }

    return 0;
}