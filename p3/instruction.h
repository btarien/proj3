#ifndef INSTRUCTION_H
#define	INSTRUCTION_H


class Instruction
{
	int address;
	char *info;

public:
	Instruction(); // constructor
	~Instruction(); // destructor
	const char* getInfo(); // accesssor method
	const int getAddress(); // accessor method
	void setInfo(const char* info); // mutator method
	void setAddress(int addr); // mutator method
};

#endif	// INSTRUCTION_H 

