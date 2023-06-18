#include <fstream>
#include <iostream>
#include <string>
#include <bitset>
// import Parser

#include "Parser.cpp"
#include "Code.cpp"
#include "Symbols.cpp"

int main(int argc, char **argv)
{
    std::string fileName = argv[1];
    std::string outputFileName = fileName.substr(0, fileName.find(".asm")) + ".hack";
    std::fstream outputFile{outputFileName, std::ios::out};

    Parser parser{fileName};
    Code codeTable;
    Symbols symbolsTable;

    int lineCounter = 0;
    // generate the symbols table
    while (parser.hasMoreCommands())
    {
        parser.advance();
        parser.setCommandType();
        if (parser.commandType() == parser.L_COMMAND)
        {
            std::string symbol = parser.symbol();
            symbolsTable.addEntry(symbol, lineCounter);
            continue;
        }
        if (parser.commandType() == parser.SKIP_COMMAND)
            continue;
        lineCounter++;
    }

    std::cout << std::endl
              << std::endl;

    parser.toTop();
    std::string instruction;
    while (parser.hasMoreCommands())
    {
        parser.advance();
        parser.setCommandType();
        if (parser.commandType() == parser.L_COMMAND || parser.commandType() == parser.SKIP_COMMAND)
            continue;

        if (parser.commandType() == parser.A_COMMAND)
        {
            std::string symbol = parser.symbol();
            // if the table contains the symbol then we can just use it
            if (symbolsTable.contains(symbol))
            {
                instruction = std::bitset<16>(symbolsTable.getAddress(symbol)).to_string();
            }
            else if (parser.isNumber(symbol))
            {
                instruction = std::bitset<16>(std::stoi(symbol)).to_string();
            }
            else
            {
                // if the table does not contain the symbol then we need to add it
                symbolsTable.addEntry(symbol, symbolsTable.getNextAddress());
                instruction = std::bitset<16>(symbolsTable.getAddress(symbol)).to_string();
            }
        }
        else if (parser.commandType() == parser.C_COMMAND)
        {
            std::string dest = parser.dest();
            std::string comp = parser.comp();
            std::string jump = parser.jump();
            instruction = "111" + codeTable.comp(comp) + codeTable.dest(dest) + codeTable.jump(jump);
        }
        outputFile << instruction << std::endl;
        instruction = "";
    }

    return 0;
}