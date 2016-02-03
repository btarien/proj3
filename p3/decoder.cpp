// Author: Sean Davis
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "decoder.h"
#include "instruction.h"
#include "registers.h"

using namespace std;

void Decoder::addl(Decoder *decoder)
{
  setOperand2(getOperand1() + getOperand2());
}  // addl()

void Decoder::andl(Decoder *decoder)
{
  setOperand2(getOperand1() & getOperand2());
}  // andl()

void Decoder::execute(Decoder *decoder, Registers *registers, int memory[1001])
{
  const char *opcodes[] = { "addl", "andl", "leave", "movl", "pushl", "ret",
    "subl"};
  enum OpcodeNum {ADDL, ANDL, LEAVE, MOVL, PUSHL, RET, SUBL};
  int opcodeNum;
  
  for(opcodeNum = ADDL; 
    strcmp(getOpcode(), opcodes[opcodeNum]) != 0 || opcodeNum > SUBL;
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
  //registers->regs[esp] = registers->regs[ebp];
  registers->set(esp, registers->get(ebp));
  
  //registers->regs[ebp] = memory[registers->regs[esp]];
  registers->set(ebp, memory[registers->get(esp)]);
  
  //registers->regs[esp] += 4;
  registers->set(esp, registers->get(eip)+4);
}  // leave()


void Decoder::movl(Decoder *decoder)
{
  setOperand2(getOperand1());
}  // movl()


void Decoder::parse(Decoder *decoder, Instruction *instruction, Registers *registers, 
           int memory[1001])
{
  char *ptr, info[1000];
  
  strcpy(info, instruction.getInfo());
  
  
  strcpy(getOpcode(), strtok(info, " "));
  ptr = strtok(NULL, " ");
  
  if(ptr)
  {
    setOperand1(address(registers, ptr, memory));
    ptr = strtok(NULL, " ");
    
    if(ptr)
      setOperand2(address(registers, ptr, memory));
  } // if there is at least one operand
}  // parse()





void Decoder::pushl(Decoder *decoder, Registers *registers, int memory[1001])
{
  //registers->regs[esp] -= 4;
  registers.set(esp, registers.get(esp)-4);
  
  //memory[registers->regs[esp]] = *decoder->operand1;
  memory[registers.get(esp)] = getOperand1();
}  // pushl()


void Decoder::ret(Registers *registers, int memory[1001])
{
  //registers->regs[eip] = memory[registers->regs[esp]];
  //registers->regs[esp] += 4;
  registers.set(eip, memory[registers.get(esp)]);
  registers.set(esp, registers.get(esp)+4);
}  // ret()


void Decoder::subl(Decoder *decoder)
{
  setOperand2(getOperand2() - getOperand1());
}  // subl()
