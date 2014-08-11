#include <stdio.h>
#include "FileRegister.h"
#include "ExecutionTable.h"
#include "Execute.h"
#include "Types.h"

int address;
int access;
int bit;
int data;
int destinationBit;
int programCounter = 0;
int carry;

uint32 maskTable[32] = { 	0x0, 
							0x1, 0x3, 0x7, 0xf, 
							0x1f, 0x3f, 0x7f, 0xff,
							0x1ff, 0x3ff, 0x7ff, 0xfff, 
							0x1fff, 0x3fff, 0x7fff, 0xffff, 
							0x1ffff, 0x3ffff, 0x7ffff, 0xfffff, 
							0x1fffff, 0x3fffff, 0x7fffff, 0xffffff, 
							0x1ffffff, 0x3ffffff, 0x7ffffff, 0xfffffff, 
							0x1fffffff, 0x3fffffff, 0x7fffffff
						};

uint32 getBitsAtOffset(uint32 data, int offset, int bitSize){
	
	if(offset >= 0 && bitSize > 0){
		if(offset >31)
			offset = 31;
		if(bitSize > 31)
			bitSize = 31;
		
		data = (data >> offset) & maskTable[bitSize];
		
		return data;
	}
	else
		return 0;
}

/**
 *
 *
 *	Retrieve a contiguious bits of 'bitSize' starting from offset.
 *	Example :
 *		data 	= 1000	1101
 *		offset 	= 4
 *		bitSize	= 6
 *		result	= 0x17
 *
 */
void setBitsAtOffset(uint32 *dataPtr, uint32 dataToWrite, int offset, int bitSize){
	
	*dataPtr = *dataPtr &(~(maskTable[bitSize]<<offset));
	*dataPtr = *dataPtr|(dataToWrite<<offset);
}

int getInfoFromOffset(unsigned int code){

	address = getBitsAtOffset(code, 0, 8);
	access = getBitsAtOffset(code, 8, 1);
	bit = getBitsAtOffset(code, 9, 3);
	destinationBit = getBitsAtOffset(code, 9, 1);
	
}

/**
 *
 *	This function is to execute the instruction from executionTable
 *
 **/
int executeInstruction(unsigned int code){

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

void setNegativeFlag(){
	// - - - N OV Z DC C
	fileRegisters[STATUS] |= 0x10;
}

void clearNegativeFlag(){
	// - - - N OV Z DC C
	fileRegisters[STATUS] &= 0xef;
}

void setOverFlowFlag(){
	// - - - N OV Z DC C
	fileRegisters[STATUS] |= 0x08;
}

void clearOverFlowFlag(){
	// - - - N OV Z DC C
	fileRegisters[STATUS] &= 0xf7;
}

void setZeroFlag(){
	// - - - N OV Z DC C
	fileRegisters[STATUS] |= 0x04;
}

void clearZeroFlag(){
	// - - - N OV Z DC C
	fileRegisters[STATUS] &= 0xfb;
}

void setDigitalCarryFlag(){
	// - - - N OV Z DC C
	fileRegisters[STATUS] |= 0x02;
}

void clearDigitalCarryFlag(){
	// - - - N OV Z DC C
	fileRegisters[STATUS] &= 0xfd;
}

void setCarryFlag(){
	// - - - N OV Z DC C
	fileRegisters[STATUS] |= 0x01;
}

void clearCarryFlag(){
	// - - - N OV Z DC C
	fileRegisters[STATUS] &= 0xfe;
}

/**
 *
 *	Get the fileRegisters[STATUS] according to the newData. The setNegativeFlag() and
 *	clearNegativeFlag() are used to detect the negative bit if bit 7 is 1 or 0. The 
 *	setZeroFlag() and clearZeroFlag() are used to detect the zero bit if the newData 
 *	is 0 or not 0. The setCarryFlag() and clearCarryFlag() are used to detect the carry
 *	bit if the bit 8 is 1 or 0.
 *
 *	Input :
 *		newData is the data of after operation
 *
 **/
void getStatusForNegative(int newData){
	
	// Negative
	if(((newData & 0x80)>>7) == 1){
		setNegativeFlag();
	}else{
		clearNegativeFlag();
	}

}

void getStatusForZero(int newData){

	// Zero
	if((newData & 0xff)== 0){
		setZeroFlag();
	}else{
		clearZeroFlag();
	}

}

void getStatusForCarry(int newData){

	// Carry
	if((newData>>8) == 1){
		setCarryFlag();
	}else{
		clearCarryFlag();
	}
}

/**
 *
 *	Store to destination according to destination bit. If the destinationBit
 *	is 0 (WREG) then the data is stored into the WREG. If is 1 (fileRegister)
 *	then data is stored into the specific fileRegister
 *
 *	Input :
 *		destinationBit	is the d bit (WREG or fileRegister)
 *		address is the address of fileRegister
 *		access is the a bit(access or banked)
 *		data is the data to write
 *
 **/
int storeDestination(int destinationBit, int address, int access, int data){
	
	if(destinationBit == 0){
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
	
	getInfoFromOffset(code);
	
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
	
	getInfoFromOffset(code);
	
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
	
	getInfoFromOffset(code);
	
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
	
	getInfoFromOffset(code);
	
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
	
	getInfoFromOffset(code);
	
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
	int newData;
	int overFlowCheck;
	int digitalCarryCheck;
	getInfoFromOffset(code);
	
	data = getFileRegData(address, access);
	newData = (int )data + ((-fileRegisters[WREG]) & 0xff);
	
	overFlowCheck = ((((int )data & 0x7f) + ((-fileRegisters[WREG]) & 0x7f))>>7);
	digitalCarryCheck = ((((int )data & 0x0f) + ((-fileRegisters[WREG]) & 0x0f))>>4);
	
	getStatusForNegative(newData);
	getStatusForZero(newData);
	getStatusForCarry(newData);

	// Over Flow
	if((newData>>8) != overFlowCheck){
		setOverFlowFlag();
	}else{
		clearOverFlowFlag();
	}
	
	// Digital Carry
	if(digitalCarryCheck == 1){
		setDigitalCarryFlag();
	}else{
		clearDigitalCarryFlag();
	}
	
	newData = storeDestination(destinationBit, address, access, newData);
	
	programCounter = executeProgramCounter();

	return newData;
}

/**
 *
 *	This function is execute SUBWFB
 *
 **/
int executeSUBWFB(unsigned int code){
	int newData;
	int overFlowCheck;
	int digitalCarryCheck;
	getInfoFromOffset(code);

	carry = executeCarryStatus();
	
	data = getFileRegData(address, access);
	newData = (int )data - ((fileRegisters[WREG]) & 0xff) - carry;
	
	overFlowCheck = ((((int )data & 0x7f) + ((-fileRegisters[WREG]) & 0x7f) - carry)>>7);
	digitalCarryCheck = ((((int )data & 0x0f) + ((-fileRegisters[WREG]) & 0x0f) - carry)>>4);
	
	getStatusForNegative(newData);
	getStatusForZero(newData);
	getStatusForCarry(newData);

	// Over Flow
	if((newData>>8) != overFlowCheck){
		setOverFlowFlag();
	}else{
		clearOverFlowFlag();
	}
	
	// Digital Carry
	if(digitalCarryCheck == 1){
		setDigitalCarryFlag();
	}else{
		clearDigitalCarryFlag();
	}
	
	newData = storeDestination(destinationBit, address, access, newData);
	
	programCounter = executeProgramCounter();

	return newData;
}

/**
 *
 *	This function is execute SWAPF
 *
 **/
int executeSWAPF(unsigned int code){
	
	getInfoFromOffset(code);
	
	data = getFileRegData(address, access);
	data = (((data & 0x0f)<<4) | ((data & 0xf0)>>4));
	
	data = storeDestination(destinationBit, address, access, data);
	
	programCounter = executeProgramCounter();

	return data;
}

/**
 *
 *	This function is execute TSTFSZ
 *
 **/
int executeTSTFSZ(unsigned int code){
	
	getInfoFromOffset(code);
	
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
	int newData;
	int overFlowCheck;
	int digitalCarryCheck;
	getInfoFromOffset(code);
	
	data = getFileRegData(address, access);
	newData = (int )data ^ (fileRegisters[WREG] & 0xff);
	
	getStatusForNegative(newData);
	getStatusForZero(newData);
	
	newData = storeDestination(destinationBit, address, access, newData);
	
	programCounter = executeProgramCounter();

	return newData;
}

