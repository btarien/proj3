#include <iostream>
#include "registers.h"

void initialize(Registers *registers, int memory[1001])
{
  registers->set(esp, 1000);//registers->regs[esp] = 1000;
  registers->set(ebp, 996);//registers->regs[ebp] = 996;
  registers->set(eip, 100);//registers->regs[eip] = 100;
  registers->set(eax, 0);//registers->regs[eax] = 0;
  memory[1000] = 0;
}  // initialize()

void print(Registers *registers, const char *instruction)
{
  printf("%-20s eip: %3d eax: %3d ebp: %3d esp: %3d\n", instruction,
    registers->get(eip), registers->get(eax), registers->get(ebp),
    registers->get(esp);
}  // print()

int* address(Registers *registers, char *operand, int memory[])
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
    return  &memory[registers->regs[regNum] + index];
  } // if ptr
  else  // direct addressing
    return &(registers->regs[regNum]);

} // address ()
