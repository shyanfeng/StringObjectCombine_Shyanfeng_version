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

	char *returnChar;
	int returnInt;
	String *string;
	
	if(stringCharAt(arguments,0) == ';')
		Throw(EMPTY_ARGUMENT);
		
	string = stringRemoveWordNotContaining(arguments,",;");
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

int extractDestination(String *arguments){
	
	char location;
	char *returnChar;
	int returnInt;
	String *string;
	
	if(stringCharAt(arguments,0) == ';')
		Throw(EMPTY_ARGUMENT);
		
	string = stringRemoveWordNotContaining(arguments,",;");
	stringTrim(string);
	
	if(stringLength(string) == 0)
		Throw(EMPTY_ARGUMENT);
	
	else if(stringLength(string) == 1){
		location = stringCharAt(string,0);
		if(location == 'F')
			returnInt = 1;
		else if(location == 'W')
			returnInt = 0;
		else{
			returnChar = stringSubstringInChar(string,0,string->length);
			returnInt =  evaluate(returnChar);
		}
	}
	else{
		returnChar = stringSubstringInChar(string,0,string->length);
		returnInt = evaluate(returnChar);
	}
	
	if(stringCharAt(arguments,0) == ',')
		stringRemoveChar(arguments);
	
	free(string);
	return returnInt;
	

}//if f, return 1, w is 0

int extractAccessBanked(String *arguments){
	char location;
	char *returnChar;
	int returnInt;
	String *string;
	String *banked = stringNew(textNew("BANKED")); //1
	String *access = stringNew(textNew("ACCESS")); //0
	
	if(stringCharAt(arguments,0) == ';')
		Throw(EMPTY_ARGUMENT);
		
	string = stringRemoveWordNotContaining(arguments,",;");
	
	stringTrim(string);
	
	if(stringLength(string) == 0)
		Throw(EMPTY_ARGUMENT);
	
	else if(stringLength(string) == 6){
		
		if(stringIsEqual(string,banked))
			returnInt = 1;
		else if(stringIsEqual(string,access))
			returnInt = 0;
		else{
			returnChar = stringSubstringInChar(string,0,string->length);
			returnInt =  evaluate(returnChar);
		}
	}
	else{
		returnChar = stringSubstringInChar(string,0,string->length);
		returnInt = evaluate(returnChar);
	}
	
	if(stringCharAt(arguments,0) == ',')
		stringRemoveChar(arguments);
	
	free(string);
	return returnInt;

}