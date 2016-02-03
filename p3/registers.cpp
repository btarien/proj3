#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "registers.h"

using namespace std;

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
  cout << setw(20) << "eip: " << instruction << "%3d eax: " << registers->get(eip) 
  << "%3d ebp: " << registers->get(eax) << "%3d esp: "<< registers->get(ebp) 
  << "%3d\n" << registers->get(esp) << endl;
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

    for (int i = 0; i < sizeof(operand); ++i)
    {
      if(operand[i] == '(')
      {
        ptr = &operand[i];
        break;
      }
    }

  // ptr = strchr(operand, '(');

  if(ptr) // some form of indirect addressing
  {
    *ptr = '\0';  // terminate operand string at first '('
    index = atoi(operand);  // will return 0 if no number there!
    // return  &memory[registers->regs[regNum] + index];

    return &memory[registers.get(regNum) + index]
  } // if ptr
  else  // direct addressing
    return &(registers.get(regNum));

} // address ()
