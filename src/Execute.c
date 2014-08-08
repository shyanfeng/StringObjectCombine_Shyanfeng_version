#include <stdio.h>
#include "FileRegister.h"
#include "ExecutionTable.h"
#include "Execute.h"

int address;
int access;
int bit;
int data;
int destinationBit;
int programCounter = 0;
int carry;

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
/*void setBitsAtOffset(unit32 *dataPtr, unit32 dataToWrite, int offset, int bitSize){

}*/

/**
 *
 *	This function is to get all the info from code
 *
 **/
int getInfo(unsigned int code){

	address = code & 0xff;
	access = ((code & 0x100)>>8);
	bit = ((code & 0xE00)>>9);
	destinationBit = ((code & 0x200)>>9);
	
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
 *	Check the fileRegisters[STATUS] according to the data. If the data is 0
 *	then the fileRegisters[STATUS] is 0x04. If the data is less than 0 then
 *	the fileRegisters[STATUS] is 0x10. If the data bit0 is 1 then
 *	fileRegisters[STATUS] is 0x01. 
 *
 *	Input :
 *
 **/
int checkStatus(int data){
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
	int newData;
	int overFlowCheck;
	int digitalCarryCheck;
	getInfo(code);
	
	data = getFileRegData(address, access);
	newData = (int )data + ((-fileRegisters[WREG]) & 0xff);
	
	overFlowCheck = ((((int )data & 0x7f) + ((-fileRegisters[WREG]) & 0xff))>>7);
	digitalCarryCheck = ((((int )data & 0x7f) + ((-fileRegisters[WREG]) & 0xff))>>3);
	
	// Negative
	if(((newData & 0x80)>>7) == 1){
		setNegativeFlag();
	}else{
		clearNegativeFlag();
	}

	// Over Flow
	if((newData>>8) != overFlowCheck){
		setOverFlowFlag();
	}else{
		clearOverFlowFlag();
	}
	
	// Zero
	if(newData == 0){
		setZeroFlag();
	}else{
		clearZeroFlag();
	}
	
	// Digital Carry
	if((newData & 0x08) != (data & 0x08)){
		setDigitalCarryFlag();
	}else{
		clearDigitalCarryFlag();
	}
	
	// Carry
	if((newData>>8)){
		setCarryFlag();
	}else{
		clearCarryFlag();
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
	getInfo(code);

	carry = executeCarryStatus();
	
	data = getFileRegData(address, access);
	newData = (int )data - fileRegisters[WREG] - carry;
	
	// Negative
	if(newData < 0){
		setNegativeFlag();
	}else{
		clearNegativeFlag();
	}

	// Over Flow
	if((newData>>8) != (newData & 0x80 != data & 0x80)){
		setOverFlowFlag();
	}else{
		clearOverFlowFlag();
	}
	
	// Zero
	if(newData == 0){
		setZeroFlag();
	}else{
		clearZeroFlag();
	}
	
	// Digital Carry
	if((newData & 0x08) != (data & 0x08)){
		setDigitalCarryFlag();
	}else{
		clearDigitalCarryFlag();
	}
	
	// Carry
	if((newData>>8)){
		setCarryFlag();
	}else{
		clearCarryFlag();
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
	
	getInfo(code);
	
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
	
	data = storeDestination(destinationBit, address, access, data);
	
	programCounter = executeProgramCounter();

	return data;
}

