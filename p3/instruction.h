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
	const int getAddress();
	void setInfo(const char* info); // mutator method
	void setAddress(int addr); // mutator method
};





Instruction::Instruction()
{
	info = 0;
}


Instruction::~Instruction()
{
	if(info != 0)
		delete[] info;
}


const char* Instruction::getInfo()
{
	return info;
}


const int Instruction::getAddress()
{
	return address;
}


void Instruction::setInfo(const char* inf)
{
	int len=sizeof(inf)/sizeof(inf[0]); 
	info = new char[len + 1];

	for(int i=0; i<len; i++)
		info[i]=inf[i]; 
}


void Instruction::setAddress(int addr)
{
	address = addr;
}

#endif	// INSTRUCTION_H 


