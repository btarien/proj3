#ifndef REGISTERS_H
#define	REGISTERS_H

typedef enum {eax, ebp, esp, eip} RegName;

class Registers{
	private:
	 int regs[4];
	
	public:
	 int* address(Registers *registers, char *ptr, int memory[]);
	 void initialize(Registers *registers, int memory[1001]);
	 void print(Registers *registers, const char *instruction);
	 int get();
	 int set();
}

Registers::get(RegName regnum){
	if(eax <= regnum <= eip){
		return regs[regnum];
	}
	else{
		return 0;
	}
}

Registers::set(RegName regnum, int val){
	if(eax <= regnum <= eip){
		regs[regnum] = val;
	}
	else{
		return 0;	
	}
}

#endif	// REGISTERS_H 

