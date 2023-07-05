/* VM Translator file.
 * Handles constructing the Parser, and code writer - then constructs the data file
 * - Parser<vmformat>
 * Memory Segments
 * SP - stack pointer
 *    Points to RAM[0]. references the next address in the stack
 * LCL - local segment
 *    points the the base address within the host RAM of the local segment. RAM[1] stores the referenced address
 * ARG - Arguments
 *    Points to the base address withint the arguments segment. RAM[2] stores the referenced address
 * THIS
 *    points to the base address of the this segment. RAM[3] holds this reference
 * THAT
 *    points to the base address of the that segment. RAM[4] holds this reference
 * temp
 *    Points to temporary referential addresses. RAM[5-12]
 * RAM[13-15]
 *    General purpose registers
 * xxx. symbols
 *    References the static segment(available to the whole program.) RAM[16-255] store these variables.
 * stack
 *    Stack implementation for the VM Machine. RAM[256-2047]
 *
 *
 * This program translates high level jack programs to byte code run by the VM machine. The machine will
 * handle the translation to machine code at runtime.
 *
 * input: jack program definition file
 * output: assembly file(.asm) using the hack asm semantic
 *
 * line translation:
 * PUSH const 7 => @7 D=A, @CONSTANT A=M, M=D => binary instructions...
 */

#include <fstream>
#include <iostream>
#include <string>
#include <bitset>

#include <string>
#include "Parser.cpp"
#include "CodeWriter.cpp"

int main(int argc, char **argv)
{
  std::string SPSegment = "SP";
  std::string staticSegment = "STATIC";
  std::string thisSegment = "THIS";
  std::string thatSegment = "THAT";
  std::string argSegment = "ARG";

  std::string fileName = argv[1];
  std::string outputFileName = fileName.substr(0, fileName.find(".vm")) + ".asm";
  // Parser parser{fileName};
  CodeWriter writer{outputFileName};
  Parser parser{fileName};

  while (parser.hasMoreLines())
  {
    // advance to the next line
    parser.advance();
    CommandType commandType = parser.commandTyoe();
    if (commandType  == CommandType::C_ARITHMATIC)
    {
      std::cout << "writing arithmatic - " << parser.arg0() << std::endl;
      writer.writeArithmatic(parser.arg0());
    }
    else if (commandType  == CommandType::C_PUSH || commandType  == CommandType::C_POP)
    {
      std::string segment = parser.arg1();
      std::cout << "writing push/pop - " << segment << " - " <<  parser.arg2() << std::endl;
      writer.writePushPop(commandType , segment, parser.arg2());
    }
  }

  return 0;
}
