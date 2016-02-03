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
	 int get(RegName regnum);
	 int set(RegName regnum, int val);
};

int Registers::get(RegName regnum){
	if(eax <= regnum <= eip){
		return regs[regnum];
	}
	else{
		return 0;
	}
}

int Registers::set(RegName regnum, int val){
	if(eax <= regnum <= eip){
		regs[regnum] = val;
	}
	else{
		return 0;	
	}
}

#endif	// REGISTERS_H 

