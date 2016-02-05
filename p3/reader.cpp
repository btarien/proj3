#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdlib>
#include "reader.h"
#include "registers.h"

using namespace std;

void Reader::fetch(Instruction *instruction, Registers *registers)
{
  int pos;
  
  for(pos = 0; lines[pos].getAddress() != registers->get(eip); pos++);
  
  instruction->setInfo(lines[pos].getInfo());
  registers->set(eip, (registers->get(eip) + 4));

} // fetch()


void Reader::read(Registers *registers, const char *filename)
{
  char line[256], *ptr;
  int address = 100, instructionCount = 0;
  string str;

  ifstream inf;
  inf.open(filename);


  while(inf.getline(line, 256))
  {
    for(ptr = strchr(line, '\t'); ptr; ptr = strchr(line, '\t'))
      *ptr = ' ';  // replace all tabs with space characters
    
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
