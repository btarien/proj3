#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdlib>
#include "main.h"
#include "reader.h"
#include "registers.h"

using namespace std;

void Reader::fetch(Instruction *instruction, Registers *registers)
{
  int pos;
  
  for(pos = 0; lines[pos].getAddress() != registers.get(eip); pos++);
  
  *instruction = lines[pos];
  registers.set(eip, registers.get(eip) + 4);
} // fetch()

void Reader::read(Registers *registers, const char *filename)
{
  char line[256], *ptr;
  int address = 100, instructionCount = 0;
  string str;

  ifstream inf;
  inf.open(filename);
  
  while (getline(inf,str) != 0)
  {
    for (int j = 0; j < str.length(); ++j)
      line[j] = inf.get(); // read line from file into line[] array


    // *ptr = inf.get();


    for (int i = 0; i < str.length(); ++i)
    {
      if(line[i] == '\t')
        line[i] = ' ';  // replace all tabs with space characters
      else if(line[i] == '\n')
        line[i] == '\0';  // eliminate \n
    }

    for(ptr = line; *ptr == ' '; ptr++);  // get past leading spaces
  
    if(*ptr != '.' && !strstr(line, "main:"))
      {
        lines[instructionCount].setAddress(address);
        address += 4;
        lines[instructionCount++].setInfo(ptr);
      } // if not directive, nor main:
    }  // while more in file

  inf.close();
}  // read()
