#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include "registers.h"

using namespace std;

void Registers::initialize(int memory[1001])
{
  set(esp, 1000);
  set(ebp, 996);
  set(eip, 100);
  set(eax, 0);
  memory[1000] = 0;
}  // initialize()


void Registers::print(const char *instruction)
{
  cout  << setw(21) << left << instruction << setw(5) << left << "eip: " 
      << setw(3) << right << get(eip) << setw(5) << left << " eax: " << setw(3)
      << right << get(eax) << setw(5) << left << " ebp: " << setw(2) << right 
      << get(ebp) << setw(5) << left << " esp: "  << left << get(esp) << endl;
}  // print()


int* Registers::address(char *operand, int memory[])
{
  static int value;
  char regNames[4][7] = {"eax", "ebp", "esp", "eip"};
  char *ptr;
  int regNum, index;

  if(operand == NULL)
    return NULL;

  if(operand[0] == '$') // immediate mode
  {
    value = atoi(&operand[1]);
    return &value;
  } // if immediate mode

  for(regNum = eax; regNum <= eip; regNum++)
    if(strstr(operand, regNames[regNum]))
      break;

  ptr = strchr(operand, '(');

  if(ptr) // some form of indirect addressing
  {
    *ptr = '\0';  // terminate operand string at first '('
    index = atoi(operand);  // will return 0 if no number there!
    return &memory[get(regNum) + index];
  } // if ptr
  else  // direct addressing
    return &regs[regNum];
} // address ()





int Registers::get(int regnum){
  if((regnum >= eax) && (regnum <= eip))
    return regs[regnum]; // check regnum between eax and eip
  else
    return 0;
} // get()


void Registers::set(int regnum, int val){
  if((regnum >= eax) && (regnum <= eip))
    regs[regnum] = val; // check regnum between eax and eip
} // set()
