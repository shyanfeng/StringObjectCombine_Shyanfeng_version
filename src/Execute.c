#include <stdio.h>
#include "FileRegister.h"
#include "ExecutionTable.h"
#include "Execute.h"

int executeInstruction(int code){

	executionTable[(code & 0xFC00)>>10](code);

}

int executeCarryStatus(){
	int carry;
	
	fileRegisters[STATUS] = fileRegisters[STATUS] & 0x01;
	if(fileRegisters[STATUS] == 1){
		carry = 0;
	}else if(fileRegisters[STATUS] == 0){
		carry = 1;
	}
	
	return carry;
}

int executeStatus(int data){
	// - - - N OV Z DC C
	
	if(data == 0x0){
		fileRegisters[STATUS] = 0x04;	// Zero
	}else if(data < 0x0){
		fileRegisters[STATUS] = 0x10;	// Negative
	}else if((data & 0x01) == 1){
		fileRegisters[STATUS] = 0x01;	// Carry
	}else{
		fileRegisters[STATUS] = 0x0;	// OV and DC
	}
	
	return fileRegisters[STATUS];
}

int executeDestination(int destination, int address, int access, int data){
	
	if(destination == 0){
		fileRegisters[WREG] = data;
		data = fileRegisters[WREG];
	}else{
		fileRegisters[address] = data;
		data = fileRegisters[address];
		data = setFileRegData(address, access, data);
	}
	
	return data;
	
}

int executeBCF(unsigned int code){
	int address;
	int access;
	int bit;
	int data;
	
	address = code & 0xff;
	access = ((code & 0x100)>>8);
	bit = ((code & 0xE00)>>9);
	
	data = getFileRegData(address, access);
	data = data & (~(1<<bit));
	data = setFileRegData(address, access, data);

	return data;
	
}

int executeBSF(unsigned int code){
	int address;
	int access;
	int bit;
	int data;
	
	address = code & 0xff;
	access = ((code & 0x100)>>8);
	bit = ((code & 0xE00)>>9);
	
	data = getFileRegData(address, access);
	data = data | (1<<bit);
	data = setFileRegData(address, access, data);

	return data;
	
}

int executeBTFSC(unsigned int code){
	int address;
	int access;
	int bit;
	int data;
	int programCounter = 0;
	
	address = code & 0xff;
	access = ((code & 0x100)>>8);
	bit = ((code & 0xE00)>>9);
	programCounter = getProgramCounter();
	
	data = getFileRegData(address, access);
	data = ((data & (1<<bit))>>bit);
	
	if(data == 1){
		programCounter += 2;
	}else{
		programCounter += 4;
	}
	
	setProgramCounter(programCounter);

	return programCounter;
}

int executeBTFSS(unsigned int code){
	int address;
	int access;
	int bit;
	int data;
	int programCounter = 0;
	
	address = code & 0xff;
	access = ((code & 0x100)>>8);
	bit = ((code & 0xE00)>>9);
	programCounter = getProgramCounter();
	
	data = getFileRegData(address, access);
	data = ((data & (1<<bit))>>bit);
	
	if(data == 0){
		programCounter += 2;
	}else{
		programCounter += 4;
	}
	
	setProgramCounter(programCounter);

	return programCounter;
}

int executeBTG(unsigned int code){
	int address;
	int access;
	int bit;
	int data;
	
	address = code & 0xff;
	access = ((code & 0x100)>>8);
	bit = ((code & 0xE00)>>9);
	
	data = getFileRegData(address, access);
	data = data ^ (1<<bit);
	data = setFileRegData(address, access, data);

	return data;
	
}

int executeSUBWF(unsigned int code){
	int address;
	int access;
	int bit;
	int data;
	int destination;
	int carry;
	
	address = code & 0xff;
	access = ((code & 0x100)>>8);
	destination = ((code & 0x200)>>9);
	
	data = getFileRegData(address, access);
	data = data - fileRegisters[WREG];
	
	fileRegisters[STATUS] = executeStatus(data);
	
	data = executeDestination(destination, address, access, data);

	return data;
}

int executeSUBWFB(unsigned int code){
	int address;
	int access;
	int bit;
	int data;
	int destination;
	int carry;
	
	address = code & 0xff;
	access = ((code & 0x100)>>8);
	destination = ((code & 0x200)>>9);

	carry = executeCarryStatus();
	
	data = getFileRegData(address, access);
	data = data - fileRegisters[WREG] - carry;
	
	fileRegisters[STATUS] = executeStatus(data);
	
	data = executeDestination(destination, address, access, data);

	return data;
}

int executeSWAPF(unsigned int code){
	int address;
	int access;
	int destination;
	int bit;
	int data;
	
	address = code & 0xff;
	access = ((code & 0x100)>>8);
	destination = ((code & 0x200)>>9);
	
	data = getFileRegData(address, access);
	data = (((data & 0x0f)<<4) | ((data & 0xf0)>>4));
	
	data = executeDestination(destination, address, access, data);

	return data;
}

int executeTSTFSZ(unsigned int code){
	int address;
	int access;
	int data;
	int programCounter = 0;
	
	address = code & 0xff;
	access = ((code & 0x100)>>8);
	programCounter = getProgramCounter();
	
	data = getFileRegData(address, access);
	
	if(data == 0){
		programCounter += 4;
	}else{
		programCounter += 2;
	}
	
	setProgramCounter(programCounter);

	return programCounter;
}

int executeXORWF(unsigned int code){
	int address;
	int access;
	int bit;
	int data;
	int destination;
	
	address = code & 0xff;
	access = ((code & 0x100)>>8);
	destination = ((code & 0x200)>>9);
	
	data = getFileRegData(address, access);
	data = data ^ fileRegisters[WREG];
	
	data = executeDestination(destination, address, access, data);

	return data;
}

