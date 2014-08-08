#ifndef _EXECUTE_H_
#define _EXECUTE_H_

#define	WREG 	0xFE8

int getInfo(unsigned int code);
int executeInstruction(unsigned int code);
int executeCarryStatus();
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
int checkStatus(int data);
int storeDestination(int destination, int address, int access, int data);
int executeProgramCounter();
int executeProgramCounterSkipIfClear(int data);
int executeProgramCounterSkipIfSet(int data);

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