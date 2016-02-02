//P3 main 

#include "registers.h"
#include "decoder.h"
#include "reader.h"
#include "instruction.h"
#include <cstdlib>
#include <cstring>

int main(int argc, char* argv[])
{
  Reader reader;
  Decoder decoder;
  Registers registers;
  Instruction instruction;
  int memory [1001];
  initialize(&registers, memory);
  read(&reader, &registers, argv[1]);
  
  while(registers.regs[eip] != 0)
  {
    fetch(&reader, &instruction, &registers);
    parse(&decoder, &instruction, &registers, memory);
    execute(&decoder, &registers, memory);
    print(&registers, instruction.info);
  } // while eip not zero

  return 0;
}  // main()

