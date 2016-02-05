#include <cstring>
#include "instruction.h"


Instruction::Instruction()
{
	info = 0;
} // constructor


Instruction::~Instruction()
{
	if(info != 0)
		delete[] info;
} // destructor


const char* Instruction::getInfo()
{
	return info;
} // getInfo()


const int Instruction::getAddress()
{
	return address;
} // getAddress()


void Instruction::setInfo(const char* inf)
{
	int len=strlen(inf); 
	info = new char[len + 1];

	strcpy(info, inf);
} // setInfo()


void Instruction::setAddress(int addr)
{
	address = addr;
} //setAddress()
