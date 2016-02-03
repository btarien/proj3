#ifndef DECODER_H
#define	DECODER_H
// Author: Sean Davis

#include "instruction.h"
#include "registers.h"

class Decoder
{
  	char opcode[20];
  	int *operand1;
  	int *operand2;
  
  	void addl(Decoder *decoder);
	void andl(Decoder *decoder);
	void leave(Registers *registers, int memory[1001]);
	void movl(Decoder *decoder);
	void pushl(Decoder *decoder, Registers *registers, int memory[1001]);
	void ret(Registers *registers, int memory[1001]);
	void subl(Decoder *decoder);

public:
	void parse(Decoder *decoder, Instruction *instruction, Registers *registers, 
           int memory[1001]);
	void execute(Decoder *decoder, Registers *registers, int memory[1001]);
	const char* getOpcode();
	const int getOperand1();
	const int get Operand2();
};


const char* Decoder::getOpcode()
{
	return opcode;
}


const int Decoder::getOperand1()
{
	return operand1;
}


const int Decoder::getOperand2()
{
	return operand2;
}



void Decoder::setOpcode(const char* opcod)
{
	int len=sizeof(opcod)/sizeof(char); 
	opcod = new char[len + 1];

	for(int i=0; i<len; i++)
		opcode[i]=opcod[i]; 
}


void Decoder::setOperator1(int op1)
{
	operator1 = op1;
}

void Decoder::setOperator2(int op2)
{
	operator2 = op2;
}


#endif	// DECODER_H 

