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
int programCounter;
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

/**
 *
 *
 *	Retrieve a contiguous bits of 'bitSize' starting from offset.
 *	Example :
 *		data 	= 1000	1101
 *		offset 	= 0
 *		bitSize	= 8
 *		result	= 0x8d
 *
 */
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

void setBitsAtOffset(uint32 *dataPtr, uint32 dataToWrite, int offset, int bitSize){
	
	*dataPtr = *dataPtr &(~(maskTable[bitSize]<<offset));
	*dataPtr = *dataPtr|((dataToWrite & maskTable[bitSize]) << offset);
}

/**
 *
 *	Based on the getInfoFromOffset to get the bits for address, access, bit
 *	and destinationBit
 *	Example:
 *		code 		= 1100 0011 1010 0101
 *
 *		we want to get the first 8 bit for address
 *		so we use getBitsAtOffset(code, 0, 8)
 *		the 0 is the bit start
 *		the 8 is the bit size
 *
 *		so address	= 1010 0101
 *
 *	Input :
		code is the opcode for instruction word
 *
 **/
int getInfoFromOffset(unsigned int code){
	
	address = getBitsAtOffset(code, 0, 8);			//0xff
	access = getBitsAtOffset(code, 8, 1);			//0x100
	bit = getBitsAtOffset(code, 9, 3);				//0xe0
	destinationBit = getBitsAtOffset(code, 9, 1);	//0x200
	
}

/**
 *
 *	Selecting which function to go in from ExecutionTable based on the bit 10 to bit15
 *
 *	Input :
 *		code is the opcode for instruction word
 *
 **/
int executeInstruction(unsigned int code){

	executionTable[(code & 0xFC00)>>10](code);

}

/**
 *
 *	Not the carry flag of fileRegisters[STATUS] according to the operation of SUBWFB. If
 *	the carry flag of fileRegisters[STATUS] is 0x01 then it should not it become 0x00. If
 *	the carry flag of fileRegisters[STATUS] is 0x00 then it should not it become 0x01.
 *
 *	Return :
 *		carry
 *
 **/
int notCarryFlagForSUBWFB(){
	
	fileRegisters[STATUS] = getBitsAtOffset(fileRegisters[STATUS], 0, 1);
	if(fileRegisters[STATUS] == 1){
		carry = 0;
	}else if(fileRegisters[STATUS] == 0){
		carry = 1;
	}
	
	return carry;
}

/**
 *
 *	Set the carry flag of fileRegisters[STATUS] to 1
 *
 **/
void setNegativeFlag(){
	// - - - N OV Z DC C
	fileRegisters[STATUS] |= 0x10;
}

/**
 *
 *	Clear the carry flag of fileRegisters[STATUS] to 0
 *
 **/
void clearNegativeFlag(){
	// - - - N OV Z DC C
	fileRegisters[STATUS] &= 0xef;
}

/**
 *
 *	Set the over flow flag of fileRegisters[STATUS] to 1
 *
 **/
void setOverFlowFlag(){
	// - - - N OV Z DC C
	fileRegisters[STATUS] |= 0x08;
}

/**
 *
 *	Clear the over flow flag of fileRegisters[STATUS] to 0
 *
 **/
void clearOverFlowFlag(){
	// - - - N OV Z DC C
	fileRegisters[STATUS] &= 0xf7;
}

/**
 *
 *	Set the zero flag of fileRegisters[STATUS] to 1
 *
 **/
void setZeroFlag(){
	// - - - N OV Z DC C
	fileRegisters[STATUS] |= 0x04;
}

/**
 *
 *	Clear the zero flag of fileRegisters[STATUS] to 0
 *
 **/
void clearZeroFlag(){
	// - - - N OV Z DC C
	fileRegisters[STATUS] &= 0xfb;
}

/**
 *
 *	Set the digital carry flag of fileRegisters[STATUS] to 1
 *
 **/
void setDigitalCarryFlag(){
	// - - - N OV Z DC C
	fileRegisters[STATUS] |= 0x02;
}

/**
 *
 *	Clear the digital carry flag of fileRegisters[STATUS] to 0
 *
 **/
void clearDigitalCarryFlag(){
	// - - - N OV Z DC C
	fileRegisters[STATUS] &= 0xfd;
}

/**
 *
 *	Set the carry flag of fileRegisters[STATUS] to 1
 *
 **/
void setCarryFlag(){
	// - - - N OV Z DC C
	fileRegisters[STATUS] |= 0x01;
}

/**
 *
 *	Clear the carry flag of fileRegisters[STATUS] to 0
 *
 **/
void clearCarryFlag(){
	// - - - N OV Z DC C
	fileRegisters[STATUS] &= 0xfe;
}

/**
 *
 *	Get the fileRegisters[STATUS] for negative according to newData. If the newData is 0 then 
 *	should go to setNegativeFlag() else should go to clearNegativeFlag().
 *
 *	Input :
 *		newData is the data after the operation
 *
 **/
void getStatusForNegative(int newData){
	
	// Negative
	if(getBitsAtOffset(newData, 7, 1) == 1){
		setNegativeFlag();
	}else{
		clearNegativeFlag();
	}

}

/**
 *
 *	Get the fileRegisters[STATUS] for zero according to newData. If the newData is 0 then 
 *	should go to setZeroFlag() else should go to clearZeroFlag().
 *
 *	Input :
 *		newData is the data after the operation
 *
 **/
void getStatusForZero(int newData){

	// Zero
	if(getBitsAtOffset(newData, 0, 8) == 0){
		setZeroFlag();
	}else{
		clearZeroFlag();
	}

}

/**
 *
 *	Get the fileRegisters[STATUS] for carry according to newData. If the newData bit 8 is 1 then 
 *	should go to setCarryFlag() else should go to clearCarryFlag().
 *
 *	Input :
 *		newData is the data after the operation
 *
 **/
void getStatusForCarry(int newData){

	// Carry
	if(getBitsAtOffset(newData, 8, 1) == 1){
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
 *	Input	:
 *		destinationBit	is the d bit (WREG or fileRegister)
 *		address is the address of fileRegister
 *		access is the a bit(access or banked)
 *		data is the data to write
 *
 *	Return 	:
 *		data
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
 *	Update the program counter + 2 from previous program counter
 *
 **/
void updateProgramCounter(){

	programCounter = getProgramCounter();
	programCounter += 2;
	setProgramCounter(programCounter);
	
}

/**
 *
 *	Update the program counter + 4 from previous program counter if data is 0
 *	otherwise update program counter + 2
 *
 *	Input :
 *		data is the data after the operation
 *
 **/
void updateProgramCounterSkipIfClear(int data){

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
 *	Update the program counter + 2 from previous program counter if data is 0 
 *	otherwise update program counter + 4
 *
 *	Input :
 *		data is the data after the operation
 *
 **/
void updateProgramCounterSkipIfSet(int data){

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
 *	Bit Clear f
 *
 *	Operation : 
 *		0-> f<b>
 *
 *	Status Affected	:
 *		None
 *
 *	Input :
 *		code is the opcode for instruction word
 *	
 *	Return :
 *		data
 *
 **/
int executeBCF(unsigned int code){
	
	getInfoFromOffset(code);
	
	data = getFileRegData(address, access);
	data = data & (~(1<<bit));
	data = setFileRegData(address, access, data);
	
	updateProgramCounter();

	return data;
	
}

/**
 *
 *	Bit Set f
 *
 *	Operation : 
 *		1-> f<b>
 *
 *	Status Affected	:
 *		None
 *
 *	Input :
 *		code is the opcode for instruction word
 *	
 *	Return :
 *		data
 *
 **/
int executeBSF(unsigned int code){
	
	getInfoFromOffset(code);
	
	data = getFileRegData(address, access);
	data = data | (1<<bit);
	data = setFileRegData(address, access, data);
	
	updateProgramCounter();

	return data;
	
}

/**
 *
 *	Bit Test f, skip if clear
 *
 *	Operation : 
 *		skip if f<b> = 0
 *
 *	Status Affected	:
 *		None
 *
 *	Input :
 *		code is the opcode for instruction word
 *	
 *	Return :
 *		data
 *
 **/
int executeBTFSC(unsigned int code){
	
	getInfoFromOffset(code);
	
	data = getFileRegData(address, access);
	data = ((data & (1<<bit))>>bit);

	updateProgramCounterSkipIfClear(data);
	
	return programCounter;
}

/**
 *
 *	Bit Test f, skip if set
 *
 *	Operation : 
 *		skip if f<b> = 1
 *
 *	Status Affected	:
 *		None
 *
 *	Input :
 *		code is the opcode for instruction word
 *	
 *	Return :
 *		data
 *
 **/
int executeBTFSS(unsigned int code){
	
	getInfoFromOffset(code);
	
	data = getFileRegData(address, access);
	data = ((data & (1<<bit))>>bit);
	
	updateProgramCounterSkipIfSet(data);

	return programCounter;
}

/**
 *
 *	Bit Toggle f
 *
 *	Operation : 
 *		~f<b> ->f<b>
 *
 *	Status Affected	:
 *		None
 *
 *	Input :
 *		code is the opcode for instruction word
 *	
 *	Return :
 *		data
 *
 **/
int executeBTG(unsigned int code){
	
	getInfoFromOffset(code);
	
	data = getFileRegData(address, access);
	data = data ^ (1<<bit);
	data = setFileRegData(address, access, data);
	
	updateProgramCounter();

	return data;
	
}

/**
 *
 *	Subtract WREG from f
 *
 *	Operation : 
 *		f - W ->dest
 *
 *	Status Affected	:
 *		N, OV, Z, DC, C
 *
 *	Input :
 *		code is the opcode for instruction word
 *	
 *	Return :
 *		newData
 *
 **/
int executeSUBWF(unsigned int code){
	int newData;
	int overFlowCheck;
	int digitalCarryCheck;
	getInfoFromOffset(code);
	
	data = getFileRegData(address, access);
	newData = (int )data + ((~(fileRegisters[WREG]) + 1) & 0xff);
	
	overFlowCheck = ((((int )data & 0x7f) + ((~(fileRegisters[WREG]) + 1) & 0x7f))>>7);
	digitalCarryCheck = ((((int )data & 0x0f) + ((~(fileRegisters[WREG]) + 1) & 0x0f))>>4);
	
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
	
	updateProgramCounter();

	return newData;
}

/**
 *
 *	Subtract WREG from f with borrow
 *
 *	Operation : 
 *		f - W - C ->dest
 *
 *	Status Affected	:
 *		N, OV, Z, DC, C
 *
 *	Input :
 *		code is the opcode for instruction word
 *	
 *	Return :
 *		newData
 *
 **/
int executeSUBWFB(unsigned int code){
	int newData;
	int overFlowCheck;
	int digitalCarryCheck;
	getInfoFromOffset(code);

	carry = notCarryFlagForSUBWFB();
	
	data = getFileRegData(address, access);
	newData = (int )data + ((~(fileRegisters[WREG]) + 1) & 0xff) + (-carry);
	
	overFlowCheck = ((((int )data & 0x7f) + ((~(fileRegisters[WREG]) + 1) & 0x7f) + (-carry))>>7);
	digitalCarryCheck = ((((int )data & 0x0f) + ((~(fileRegisters[WREG]) + 1) & 0x0f) + (-carry & 0x0f))>>4);
	
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
	
	updateProgramCounter();

	return newData;
}

/**
 *
 *	Swap f
 *
 *	Operation : 
 *		f<3:0> ->dest<7:4>
 *		f<7:4> ->dest<3:0>
 *
 *	Status Affected	:
 *		None
 *
 *	Input :
 *		code is the opcode for instruction word
 *	
 *	Return :
 *		newData
 *
 **/
int executeSWAPF(unsigned int code){
	
	getInfoFromOffset(code);
	
	data = getFileRegData(address, access);
	data = (((data & 0x0f)<<4) | ((data & 0xf0)>>4));
	
	data = storeDestination(destinationBit, address, access, data);
	
	updateProgramCounter();

	return data;
}

/**
 *
 *	Test f, skip if 0
 *
 *	Operation : 
 *		skip if f = 0
 *
 *	Status Affected	:
 *		None
 *
 *	Input :
 *		code is the opcode for instruction word
 *	
 *	Return :
 *		newData
 *
 **/
int executeTSTFSZ(unsigned int code){
	
	getInfoFromOffset(code);
	
	data = getFileRegData(address, access);
	
	updateProgramCounterSkipIfClear(data);

	return programCounter;
}

/**
 *
 *	Exclusive OR W with f
 *
 *	Operation : 
 *		W OR f ->dest
 *
 *	Status Affected	:
 *		N, Z
 *
 *	Input :
 *		code is the opcode for instruction word
 *	
 *	Return :
 *		newData
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
	
	updateProgramCounter();

	return newData;
}

