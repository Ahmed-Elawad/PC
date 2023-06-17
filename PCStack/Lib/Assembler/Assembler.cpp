#include <fstream>
#include <iostream>
#include <string>
// import Parser
#include "Parser.cpp"
#include "Code.cpp"
#include "Symbols.cpp"

int main(int argc, char** argv)
{
    // limit input items
    std::string file_name = argv[1];

    std::string read_file_Name{file_name};
    // remove asm
    std::string output_filename = file_name.substr(0, file_name.find('.'))+ ".hack";
    std::string write_file_Name{output_filename};

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

        if (parser.commandType() == parser.COMMENT)
            continue;
        if (parser.commandType() == parser.L_COMMAND)
        {
            std::string symb = parser.symbol();
            symbolsTables.addEntry(symb, lineCounter);
            continue;
        }
        lineCounter++;
    }

    parser.backToTop();

    while (parser.hasMoreCommands())
    {
        parser.advance(); // advance to the first line

        if (parser.commandType() == parser.COMMENT)
            continue;
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
            int symbol_addres;
            if (parser.commandType() == parser.A_COMMAND)
            {

            } else  if (symbolsTables.contains(symb))
            {
                symbol_addres = symbolsTables.getAddress(symb);
                symb = parser.convertIntToStringBits(symbol_addres);
            }
            else
            {
                symbol_addres = symbolsTables.getNextAddress();
                symbolsTables.addEntry(symb, symbol_addres);
                symb = parser.convertIntToStringBits(symbol_addres);
            }

            //std::cout << symb << std::endl;
            parser.padWithZeros(symb, instruction);
        }
        outputFile << instruction << std::endl;
    }
    outputFile.close();
    parser.closeFile();
    return 0;
}