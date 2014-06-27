#include <stdio.h>
#include <stdlib.h>
#include "String.h"
#include "CustomTypeAssert.h"
#include "StringObject.h"
#include "malloc.h"
#include "CharSet.h"

void stringDump(String *string){
	uint32 index = 0, len = 0;
	char *fullString = "(NULL)";
	char *actualString = "(NULL)";


	if(string == NULL){
		printf("NULL\n");
		return;
	}
	if(string->text != NULL){
		int actualLength;
		fullString = string->text->string;
		index = string->start;
		
		if(index <= strlen(fullString)){
			actualString = &fullString[index];
			actualLength = strlen(actualString);
			len = string->length;
			if(len > actualLength)
				len = actualLength;
		} else{
			actualString = "";
		}
	}
	
	printf("[%d] f_str[:%d]:%s, start:%d, len:%d, str:%.*s\n", \
			string->reference, string->text->reference, fullString, index, \
			string->length, len, actualString);
	return;

}

String *stringNew(Text *text){

	String *newString = malloc(sizeof(String));
	
	newString->text = textAssign(text);
	newString->reference = 1;
	newString->start = 0;
	newString->length = strlen(text->string);
	
	return newString;
}

String *stringAssign(String *string){

	string->reference++;
	return string;
}

String *stringDel(String *string){

	string->reference--;
	if(string->reference == 0){
		free(string);
		textDel(string->text);
		return NULL;
	}
	return string;

}

void stringSkip(String *string, int numChar2Skip){

	int startPoint = string->start + numChar2Skip;
	
	if(startPoint < string->length){
		string->start = startPoint;
		string->length = string->length - string->start;
	}
	else{
		string->start = string->length;
		string->length = string->length - string->start;
	}
}

void stringTrimLeft(String *string){
	
	int i = string->start;
	int l = strlen(string->text->string);
	
	if(string->text->string[i] != 0){
		for(;i<=l;i++){
			if(isSpace(string->text->string[i])){
				string->start++;
				string->length--;
			}
			else
				break;
		}
	}
}

void stringTrimRight(String *string){

	int end = string->start+string->length-1;
	
	for(;;end--){
		if(isSpace(string->text->string[end])){
				string->length--;
		}
		else
			break;
	}
}

void stringTrim(String *string){
	stringTrimLeft(string);
	stringTrimRight(string);
}

// return -l if empty remove by moving index number
int stringRemoveChar(String *str){
	char forReturn = str->text->string[str->start];
	
	if(str->text->string[str->start] != 0 && \
	   str->text->string[str->start+1] != 0){
		str->start++;
		str->length--;
	}
	else{
		if(str->text->string[str->start] != 0)
			str->length--;
		return -1;
	}

	return forReturn;
}

// length of string
int stringLength(String *str){
	return str->length;
}

String *stringRemoveWordNotContaining(String *str,char delimites[]){
	int i,j,count,delimitesLength,strLength;
	String *strReturn = stringNew(str->text);
	
	delimitesLength = strlen(delimites);
	strLength = strlen(str->text->string);
	strReturn->start = str->start;
	strReturn->length = 0;
	
	for(j=str->start;j<strLength;j++){
		for(i=0,count=0;i<delimitesLength;i++){
			if(str->text->string[j] == delimites[i]){
				break;
			}
			else{
				count++;
			}
		}
		if(count>=delimitesLength){
			str->start++;
			str->length--;
			strReturn->length++;
		}
		else
			break;
	}
	return strReturn;
}

String *stringRemoveWordContaining(String *str, char containSet[]){
	int i,j,count,containLength,strLength;
	String *strReturn = stringNew(str->text);
	containLength = strlen(containSet);
	strLength = strlen(str->text->string);
	strReturn->start = str->start;
	strReturn->length = 0;
	
	for(j=str->start;j<strLength;j++){
		for(i=0,count=0;i<containLength;i++){
			if(str->text->string[j] == containSet[i]){
				str->start++;
				str->length--;
				strReturn->length++;
				break;
			}
			else{
				count++;
			}
		}
		if(count>=containLength)
			break;
	}
	return strReturn;
}

int stringIsEqual(String *str1, String *str2){
	int i;
	int actualLength;
	int actualLength2;
	char *actualString;
	char *actualString2;
	
	actualString = &str1->text->string[str1->start];
	actualString2 = &str2->text->string[str2->start];
	
	actualLength = strlen(actualString);
	actualLength2 = strlen(actualString2);
	
	if(actualLength == actualLength2){
		for(i=0;i<actualLength;i++){
			if(actualString[i] != actualString2[i])
				return 0;
		}
		return 1;
	}
	else
		return 0;
}

int stringIsEqualCaseInsensitive(String *str1, String *str2){
	int i;
	int actualLength;
	int actualLength2;
	char *actualString;
	char *actualString2;
	
	actualString = &str1->text->string[str1->start];
	actualString2 = &str2->text->string[str2->start];
	
	actualLength = strlen(actualString);
	actualLength2 = strlen(actualString2);
	
	if(actualLength == actualLength2){
		for(i=0;i<actualLength;i++){
			if(tolower(actualString[i]) != tolower(actualString2[i]))
				return 0;
		}
		return 1;
	}
	else
		return 0;

}

int stringCharAt(String *str, int relativeIndex){
	if(relativeIndex >= 0 && relativeIndex < str->length)
		return str->text->string[str->start+relativeIndex];
	else
		return -1;

}

int stringIsCharAtInSet(String *str, int relativeIndex, char set[]){
	
	int i, setLength = strlen(set);

	if(relativeIndex >= 0 && relativeIndex < str->length){
		for(i=0;i < setLength; i++){
			if(str->text->string[str->start+relativeIndex] == set[i])
				return 1;
		}
	}
	return 0;
}

int stringToInteger(String *str){

	char *string = stringSubstringInChar(str,str->start,str->length);
	int forReturn = atoi(string);

	free(string);
	
	return forReturn;
}

char *stringSubstringInChar(String *str, int relativePosition, int length){
	
	int size;
	if(relativePosition+length > strlen(str->text->string))
		size = str->length - relativePosition+1;
	else
		size = length+1;
		
	char *character = malloc(sizeof(char)*size);
		
	int i,j,h;
	
	for(j=0,i=relativePosition; i < relativePosition+length ; j++,i++){
		character[j] = str->text->string[i];
		h = j;
	}
	character[h+1] = 0;
	return character;
}

Text *stringSubstringInText(String *str, int relativePosition, int length){
	
	char *charStr = stringSubstringInChar(str,relativePosition,length);
	Text *text = textNew(charStr);
	free(charStr);
	return text;
}

/*
String *stringRemoveWordNotContaining(String *str,char delimites[]){
	int i,j = 0,k = 0,length;
	Text *text;
	String *strReturn;
	length = strlen(delimites);
	char forReturn[length];
	
	for( i = str->start; i < str->length && j < length;i++){
		for(;j<length;i++){
			if(str->text->string[i] != delimites[j]){
				forReturn[k] = str->text->string[i];
				k++;
				str->start++;
				str->length--;
			}
			else{
				j++;
			}
		}
	}
	
	text = textNew(forReturn);
	strReturn = stringNew(text);
	return  strReturn;
}
*/
