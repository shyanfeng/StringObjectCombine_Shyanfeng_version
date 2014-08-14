#include <stdio.h>
#include "FileRegister.h"
#include "ExecutionTable.h"
#include "Execute.h"

#define isInFirstAccessRange (address >= 0x00 && address <= 0x7f)
#define isInSecondAccessRange (address >= 0xf80 && address <= 0xfff)
#define isInBankedRange (address >= 0x80 && address <= 0xf79)
#define isInRangeOfBSR (fileRegisters[BSR] >= 0x0 && fileRegisters[BSR] <= 0x15)
#define isShiftedBSR ((fileRegisters[BSR] & 0x0f)<<8)
#define isMaskedAddress (address & 0xff)

unsigned char fileRegisters[4096];

/**
 *
 *	Get the data from address of file register based on the findActualFileRegister
 *	function. When the data is store in address of file register then it can get the
 *	data from the address of file register
 *
 *	Input	:
 *		address is the address of file register
 *		access is the bit(access or banked)
 *	
 *	Return	:
 *		data
 *
 **/
int getFileRegData(int address, int access){
	int data;
	int getAddress;
	
	getAddress = findActualFileRegister(address, access);
	data = fileRegisters[getAddress];
	// printf("%x\n", data);
	
	return data;
}

/**
 *
 *	Set the data into the address of file register based on the findActualFileRegister
 *	function. The data can be set and store in address of file register then it can get the
 *	newData from the address of file register
 *
 *	Input	:
 *		address is the address of file register
 *		access is the bit(access or banked)
 *	
 *	Return	:
 *		newData
 *
 **/
int setFileRegData(int address, int access, int data){
	int getAddress;
	int newData;
	
	getAddress = findActualFileRegister(address, access);
	fileRegisters[getAddress] = data;
	newData = fileRegisters[getAddress];
	// printf("%x\n", newData);
	
	return newData;
	
}

/**
 *
 *	Find the actual file register based on the access and address. If the access
 *	is 0 then it will go in to Access. If the access is 1 then it will go in to
 *	to Banked. If it is Access then it will check for the range in AccessRange
 *	and return address. If it is not in AccessRange then it will mask the address  
 *	with 0xff and return the address if in AccessRange else it will put in to Banked F.
 *	If in Banked then it will check for the BSR range else it will mask the BSR address
 *	and get the last BSR. After check it will return the address.
 *
 *	Input 	:
 *		address is the address of file register
 *		access is the bit(access or banked)
 *	
 *	Return	:
 *		address
 *
 **/
int findActualFileRegister(int address, int access){
	int actualAddress;
	
	if(access == 0){
		if(isInFirstAccessRange || isInSecondAccessRange){
			return address;
		}else{
			address = isMaskedAddress;
			if(isInFirstAccessRange || isInSecondAccessRange){
				return address;
			}else{
				address = address | (0xf<<8);
				return address;
			}
		}
	}else{
		if(isInRangeOfBSR){
			if(isInBankedRange){
				actualAddress = isShiftedBSR + isMaskedAddress;
				return actualAddress;
			}else{
				actualAddress = isShiftedBSR + isMaskedAddress;
				return actualAddress;
			}
		}else{
			actualAddress = isShiftedBSR + isMaskedAddress;
			return actualAddress;
		}
	}
	
	return address;

}
/**
 *
 *	Clear all the data in FileRegisters
 *
 **/
void clearAllFileRegisters(){
	int i;
	
	for(i = 0; i < 4096; i++){
		fileRegisters[i] = 0;
	}
	
}

int getProgramCounter(){

	return	(fileRegisters[PCLATU]<<16) + 
			(fileRegisters[PCLATH]<<8) + 
			fileRegisters[PCL];
}

void setProgramCounter (int programCounter){

	fileRegisters[PCLATU] = (programCounter & 0xff0000) >> 16;
	fileRegisters[PCLATH] = (programCounter & 0xff00) >> 8;
	fileRegisters[PCL]	  = (programCounter & 0xff);

}