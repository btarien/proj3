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

public:
	void parse(Decoder *decoder, Instruction *instruction, Registers *registers, 
           int memory[1001]);
	void execute(Decoder *decoder, Registers *registers, int memory[1001]);

private:
	void addl(Decoder *decoder);
	void andl(Decoder *decoder);
	void leave(Registers *registers, int memory[1001]);
	void movl(Decoder *decoder);
	void pushl(Decoder *decoder, Registers *registers, int memory[1001]);
	void ret(Registers *registers, int memory[1001]);
	void subl(Decoder *decoder);
};

#endif	// DECODER_H 

