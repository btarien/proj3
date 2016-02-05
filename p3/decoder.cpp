#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "decoder.h"
#include "instruction.h"
#include "registers.h"

using namespace std;

void Decoder::addl()
{
  setOperand2(getOperand1() + getOperand2());
}  // addl()


void Decoder::andl()
{
  setOperand2(getOperand1() & getOperand2());
}  // andl()


void Decoder::execute(Registers *registers, int memory[1001])
{

  const char *opcodes[] = { "addl", "andl", "leave", "movl", "pushl", "ret",
    "subl"};

  enum OpcodeNum {ADDL, ANDL, LEAVE, MOVL, PUSHL, RET, SUBL};
  int opcodeNum;

  for(opcodeNum = ADDL; 
    strcmp(opcode, opcodes[opcodeNum]) != 0 || opcodeNum > SUBL;
    ++opcodeNum);
  
  switch (opcodeNum)
  {
    case ADDL: addl(); break;
    case ANDL: andl(); break;
    case LEAVE: leave(registers, memory); break;
    case MOVL: movl(); break;
    case PUSHL: pushl(registers, memory); break;
    case RET: ret(registers, memory); break;
    case SUBL: subl(); break;
    default: cout << "Invalid opcode!\n";
  } // switch on oncodeNum
}  // execute()


void Decoder::leave(Registers *registers, int memory[1001])
{
  registers->set(esp, registers->get(ebp)); 
  registers->set(ebp, memory[registers->get(esp)]);
  registers->set(esp, registers->get(esp)+4);
}  // leave()


void Decoder::movl()
{
  setOperand2(getOperand1());
}  // movl()


void Decoder::parse(Instruction *instruction, Registers *registers, 
           int memory[1001])
{
  char *ptr, info[1000];

  strcpy(info, instruction->getInfo());
  
  
  strcpy(opcode, strtok(info, " "));
  ptr = strtok(NULL, " ");
  
  if(ptr)
  {
    operand1 = registers->address(ptr, memory);
    ptr = strtok(NULL, " ");
    
    if(ptr)
      operand2= registers->address(ptr, memory);
  } // if there is at least one operand
}  // parse()


void Decoder::pushl(Registers *registers, int memory[1001])
{
  registers->set(esp, registers->get(esp)-4);  
  memory[registers->get(esp)] = getOperand1();
}  // pushl()


void Decoder::ret(Registers *registers, int memory[1001])
{
  registers->set(eip, memory[registers->get(esp)]);
  registers->set(esp, registers->get(esp)+4);
}  // ret()


void Decoder::subl()
{
  setOperand2(getOperand2() - getOperand1());
}  // subl()






char* Decoder::getOpcode()
{
  return opcode;
} // getOpcode()


 int Decoder::getOperand1()
{
  return *operand1;
} // getOperand1()


 int Decoder::getOperand2()
{
  return *operand2;
} // getOperand2()


void Decoder::setOpcode(char* opcod)
{
  int len = sizeof(opcod)/sizeof(char); 
  opcod = new char[len + 1];

  for(int i = 0; i < len; i++)
    opcode[i]=opcod[i]; 
} // setOpcode()


void Decoder::setOperand1(int op1)
{
  *operand1 = op1;
} // setOperand1

void Decoder::setOperand2(int op2)
{
  *operand2 = op2;
} // setOperand2


