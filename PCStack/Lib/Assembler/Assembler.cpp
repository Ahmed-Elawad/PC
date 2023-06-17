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

        if (parser.commandType() == parser.C_COMMAND)
        {
            std::string comp = parser.comp(); // not correct when: D;JGT, 0;JMP
            std::string dest = parser.dest();
            std::string jmp = parser.jump();
            instruction = "111" + codeTables.aCode(comp) + codeTables.comp(comp) + codeTables.dest(dest) + codeTables.jump(jmp);
        }
        else
        {
            std::string symb = parser.symbol();         
            if (symbolsTables.contains(symb))
            {
                int symbol_addres = symbolsTables.getAddress(symb);
                symb = parser.convertIntToStringBits(symbol_addres);
            }
            parser.padWithZeros(symb, instruction);
        }
        outputFile << instruction << std::endl;
    }

    return 0;
}