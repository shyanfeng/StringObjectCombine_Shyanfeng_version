#include <stdio.h>
#include <malloc.h>
#include "unity.h"
#include "Interpret.h"
#include "String.h"
#include "CException.h"
#include "StringObject.h"
#include "Token.h"
#include "Text.h"
#include "CharSet.h"
#include "ErrorCode.h"
#include "CustomTypeAssert.h"
#include "mock_evaluate.h"


unsigned int interpret(String *instruction);

int extractValue(String *arguments){
	if(stringCharAt(arguments,0) == ';')
		Throw(EMPTY_ARGUMENT);
		
	char *returnChar;
	int returnInt;
	String *string = stringRemoveWordNotContaining(arguments,",;");
	stringTrim(string);
	
	if(stringLength(string) == 0)
		Throw(EMPTY_ARGUMENT);
		
	returnChar = stringSubstringInChar(string,0,string->length);
	returnInt = evaluate(returnChar);
	
	if(stringCharAt(arguments,0) == ',')
		stringRemoveChar(arguments);
		
	free(string);
	
	return returnInt;
} //pass to jason

int extractDestination(String *arguments); //if f, return 1, w is 0

int extractAccessBanked(String *arguments); //folo mplab