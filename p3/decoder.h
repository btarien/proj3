#ifndef DECODER_H
#define	DECODER_H

#include "instruction.h"
#include "registers.h"

class Decoder
{
	char opcode[20];
	int *operand1;
	int *operand2;
  
	void addl();
	void andl();
	void leave(Registers *registers, int memory[1001]);
	void movl();
	void pushl(Registers *registers, int memory[1001]);
	void ret(Registers *registers, int memory[1001]);
	void subl();

public:
	void parse(Instruction *instruction, Registers *registers, 
           int memory[1001]);
	void execute(Registers *registers, int memory[1001]);
	char* getOpcode();
	int getOperand1();
	int getOperand2();
	void setOpcode(char* opcod);
	void setOperand1(int op1);
	void setOperand2(int op2);
};

#endif	// DECODER_H 
