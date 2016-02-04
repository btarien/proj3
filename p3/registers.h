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
	 void set(RegName regnum, int val);
};

int Registers::get(RegName regnum){
	if(eax <= regnum && regnum <= eip){
		return regs[regnum];
	}
	else{
		return 0;
	}
}

void Registers::set(RegName regnum, int val){
	if(eax <= regnum && regnum <= eip){
		regs[regnum] = val;
	}
	else{
	}
}

#endif	// REGISTERS_H 

