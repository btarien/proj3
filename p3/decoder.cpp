// Author: Sean Davis
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "decoder.h"
#include "instruction.h"
#include "registers.h"
#include "main.h"

using namespace std;

void Decoder::addl(Decoder *decoder)
{
  *decoder->operand2 = *decoder->operand1 + *decoder->operand2;
}  // addl()

void Decoder::andl(Decoder *decoder)
{
  *decoder->operand2 = *decoder->operand1 & *decoder->operand2;
}  // andl()

void Decoder::execute(Decoder *decoder, Registers *registers, int memory[1001])
{
  const char *opcodes[] = { "addl", "andl", "leave", "movl", "pushl", "ret",
    "subl"};
  enum OpcodeNum {ADDL, ANDL, LEAVE, MOVL, PUSHL, RET, SUBL};
  int opcodeNum;
  
  for(opcodeNum = ADDL; 
    strcmp(decoder->opcode, opcodes[opcodeNum]) != 0 || opcodeNum > SUBL;
    ++opcodeNum);
  
  switch (opcodeNum)
  {
    case ADDL: addl(decoder); break;
    case ANDL: andl(decoder); break;
    case LEAVE: leave(registers, memory); break;
    case MOVL: movl(decoder); break;
    case PUSHL: pushl(decoder, registers, memory); break;
    case RET: ret(registers, memory); break;
    case SUBL: subl(decoder); break;
    default: cout << "Invalid opcode!\n";
  } // switch on oncodeNum
 
}  // execute()

void Decoder::leave(Registers *registers, int memory[1001])
{
  registers->regs[esp] = registers->regs[ebp];
  registers->regs[ebp] = memory[registers->regs[esp]];
  registers->regs[esp] += 4;
}  // leave()


void Decoder::movl(Decoder *decoder)
{
  *decoder->operand2 = *decoder->operand1;
}  // movl()


void Decoder::parse(Decoder *decoder, Instruction *instruction, Registers *registers, 
           int memory[1001])
{
  char *ptr, info[1000];
  
  strcpy(info, instruction->info);
  
  
  strcpy(decoder->opcode, strtok(info, " "));
  ptr = strtok(NULL, " ");
  
  if(ptr)
  {
    decoder->operand1 = address(registers, ptr, memory);
    ptr = strtok(NULL, " ");
    
    if(ptr)
      decoder->operand2 = address(registers, ptr, memory);
  } // if there is at least one operand
}  // parse()





void Decoder::pushl(Decoder *decoder, Registers *registers, int memory[1001])
{
  registers->regs[esp] -= 4;
  memory[registers->regs[esp]] = *decoder->operand1;
}  // pushl()


void Decoder::ret(Registers *registers, int memory[1001])
{
  registers->regs[eip] = memory[registers->regs[esp]];
  registers->regs[esp] += 4;
}  // ret()


void Decoder::subl(Decoder *decoder)
{
  *decoder->operand2 = *decoder->operand2 - *decoder->operand1;
}  // subl()
