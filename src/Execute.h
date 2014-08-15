#ifndef _EXECUTE_H_
#define _EXECUTE_H_

#include "Types.h"

int getInfo(unsigned int code);
int executeInstruction(unsigned int code);
uint32 getBitsAtOffset(uint32 data, int offset, int bitSize);
void setBitsAtOffset(uint32 *dataPtr, uint32 dataToWrite, int offset, int bitSize);

int notCarryFlagForSUBWFB();
void setNegativeFlag();
void clearNegativeFlag();
void setOverFlowFlag();
void clearOverFlowFlag();
void setZeroFlag();
void clearZeroFlag();
void setDigitalCarryFlag();
void clearDigitalCarryFlag();
void setCarryFlag();
void clearCarryFlag();
void checkNegativeStatus(int newData);
void checkZeroStatus(int newData);
void checkCarryStatus(int newData);
int storeDestination(int destination, int address, int access, int data);
void updateProgramCounter();
void updateProgramCounterSkipIfClear(int data);
void updateProgramCounterSkipIfSet(int data);

int executeBCF(unsigned int code);
int executeBSF(unsigned int code);
int executeBTFSC(unsigned int code);
int executeBTFSS(unsigned int code);
int executeBTG(unsigned int code);
int executeSUBWF(unsigned int code);
int executeSUBWFB(unsigned int code);
int executeSWAPF(unsigned int code);
int executeTSTFSZ(unsigned int code);
int executeXORWF(unsigned int code);

#endif //_EXECUTE_H_