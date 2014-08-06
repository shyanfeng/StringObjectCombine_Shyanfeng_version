#include <stdio.h>
#include "ExecutionTable.h"
#include "FileRegister.h"
#include "Execute.h"

ExecutionTable executionTable[64] = {
	[0x06] = executeXORWF,
	[0x0e] = executeSWAPF,
	[0x16] = executeSUBWFB,
	[0x17] = executeSUBWF,
	[0x19] = executeTSTFSZ,
	[0x1c] = executeBTG,
	[0x1d] = executeBTG,
	[0x1e] = executeBTG,
	[0x1f] = executeBTG,
	[0x20] = executeBSF,
	[0x21] = executeBSF,
	[0x22] = executeBSF,
	[0x23] = executeBSF,
	[0x24] = executeBCF,
	[0x25] = executeBCF,
	[0x26] = executeBCF,
	[0x27] = executeBCF,
	[0x28] = executeBTFSS,
	[0x29] = executeBTFSS,
	[0x2a] = executeBTFSS,
	[0x2b] = executeBTFSS,
	[0x2c] = executeBTFSC,
	[0x2d] = executeBTFSC,
	[0x2e] = executeBTFSC,
	[0x2f] = executeBTFSC,
	

};