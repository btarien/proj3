#ifndef REGISTERS_H
#define	REGISTERS_H

typedef enum {eax, ebp, esp, eip} RegName;

class Registers
{
	int regs[4];
	
public:
	int* address(char *ptr, int memory[]);
	void initialize(int memory[1001]);
	void print(const char *instruction);
	int get(int regnum);
	void set(int regnum, int val);
};

#endif	// REGISTERS_H 
