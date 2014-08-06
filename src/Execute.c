#include <stdio.h>
#include "FileRegister.h"
#include "ExecutionTable.h"
#include "Execute.h"

int address;
int access;
int bit;
int data;
int destination;
int programCounter = 0;
int carry;

/**
 *
 *	This function is to get all the info from code
 *
 **/
int getInfo(int code){

	address = code & 0xff;
	access = ((code & 0x100)>>8);
	bit = ((code & 0xE00)>>9);
	destination = ((code & 0x200)>>9);
	
}

/**
 *
 *	This function is to execute the instruction from executionTable
 *
 **/
int executeInstruction(int code){

	executionTable[(code & 0xFC00)>>10](code);

}

/**
 *
 *	This function is to NOT the carry
 *
 **/
int executeCarryStatus(){
	
	fileRegisters[STATUS] = fileRegisters[STATUS] & 0x01;
	if(fileRegisters[STATUS] == 1){
		carry = 0;
	}else if(fileRegisters[STATUS] == 0){
		carry = 1;
	}
	
	return carry;
}

/**
 *
 *	This function is to get the fileRegisters[STATUS]
 *
 **/
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

/**
 *
 *	This function is to get the destination to store and store into it
 *
 **/
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

/**
 *
 *	This function is to get the programCounter to update 2 program counter 
 *	and set it back
 *
 **/
int executeProgramCounter(){

	programCounter = getProgramCounter();
	programCounter += 2;
	setProgramCounter(programCounter);
	
}

/**
 *
 *	This function is to get the programCounter to update 4 program counter 
 *	if data is 0 otherwise update 2 program counter and set it back
 *
 **/
int executeProgramCounterSkipIfClear(int data){

	programCounter = getProgramCounter();
	
	if(data == 0){
		programCounter += 4;
	}else{
		programCounter += 2;
	}
	
	setProgramCounter(programCounter);
	
}

/**
 *
 *	This function is to get the programCounter to update 4 program counter 
 *	if data is 1 otherwise update 2 program counter and set it back
 *
 **/
int executeProgramCounterSkipIfSet(int data){

	programCounter = getProgramCounter();
	
	if(data == 0){
		programCounter += 2;
	}else{
		programCounter += 4;
	}
	
	setProgramCounter(programCounter);
	
}

/**
 *
 *	This function is execute BCF
 *
 **/
int executeBCF(unsigned int code){
	
	getInfo(code);
	
	data = getFileRegData(address, access);
	data = data & (~(1<<bit));
	data = setFileRegData(address, access, data);
	
	programCounter = executeProgramCounter();

	return data;
	
}

/**
 *
 *	This function is execute BSF
 *
 **/
int executeBSF(unsigned int code){
	
	getInfo(code);
	
	data = getFileRegData(address, access);
	data = data | (1<<bit);
	data = setFileRegData(address, access, data);
	
	programCounter = executeProgramCounter();

	return data;
	
}

/**
 *
 *	This function is execute BTFSC
 *
 **/
int executeBTFSC(unsigned int code){
	
	getInfo(code);
	
	data = getFileRegData(address, access);
	data = ((data & (1<<bit))>>bit);

	programCounter = executeProgramCounterSkipIfClear(data);
	
	return programCounter;
}

/**
 *
 *	This function is execute BTFSS
 *
 **/
int executeBTFSS(unsigned int code){
	
	getInfo(code);
	
	data = getFileRegData(address, access);
	data = ((data & (1<<bit))>>bit);
	
	programCounter = executeProgramCounterSkipIfSet(data);

	return programCounter;
}

/**
 *
 *	This function is execute BTG
 *
 **/
int executeBTG(unsigned int code){
	
	getInfo(code);
	
	data = getFileRegData(address, access);
	data = data ^ (1<<bit);
	data = setFileRegData(address, access, data);
	
	programCounter = executeProgramCounter();

	return data;
	
}

/**
 *
 *	This function is execute SUBWF
 *
 **/
int executeSUBWF(unsigned int code){
	
	getInfo(code);
	
	data = getFileRegData(address, access);
	data = data - fileRegisters[WREG];
	
	fileRegisters[STATUS] = executeStatus(data);
	
	data = executeDestination(destination, address, access, data);
	
	programCounter = executeProgramCounter();

	return data;
}

/**
 *
 *	This function is execute SUBWFB
 *
 **/
int executeSUBWFB(unsigned int code){
	
	getInfo(code);

	carry = executeCarryStatus();
	
	data = getFileRegData(address, access);
	data = data - fileRegisters[WREG] - carry;
	
	fileRegisters[STATUS] = executeStatus(data);
	
	data = executeDestination(destination, address, access, data);
	
	programCounter = executeProgramCounter();

	return data;
}

/**
 *
 *	This function is execute SWAPF
 *
 **/
int executeSWAPF(unsigned int code){
	
	getInfo(code);
	
	data = getFileRegData(address, access);
	data = (((data & 0x0f)<<4) | ((data & 0xf0)>>4));
	
	data = executeDestination(destination, address, access, data);
	
	programCounter = executeProgramCounter();

	return data;
}

/**
 *
 *	This function is execute TSTFSZ
 *
 **/
int executeTSTFSZ(unsigned int code){
	
	getInfo(code);
	
	data = getFileRegData(address, access);
	
	programCounter = executeProgramCounterSkipIfClear(data);

	return programCounter;
}

/**
 *
 *	This function is execute XORWF
 *
 **/
int executeXORWF(unsigned int code){
	
	getInfo(code);
	
	data = getFileRegData(address, access);
	data = data ^ fileRegisters[WREG];
	
	data = executeDestination(destination, address, access, data);
	
	programCounter = executeProgramCounter();

	return data;
}

