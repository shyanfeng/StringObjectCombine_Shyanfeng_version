#include <stdio.h>
#include "String.h"
#include "stringObject.h"
#include "malloc.h"


void textDump(Text *text){
	if(text==NULL){
		printf("(NULL)");
		return;
	}
	printf("text[0x%x];%s\n", text->reference, text->string);
}

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

Text *textNew(char *charStr){
	// Character string copy from charStr to text->string
	Text *text = (Text *)malloc(strlen(charStr) + 4 + 1);
	strcpy(text->string,charStr);
	text->reference = 1;
	return text;
}

Text *textAssign(Text *text){
	if(text->reference < 0x80000000)
		text->reference++;
	return text;
}

Text *textDel(Text *text){
	//check if text reference not equals to 0x80000000
	//reduce text reference by one
	//do normal delete
	//else do nth
	if(text->reference < 0x80000000 && text->reference > 0){
		text->reference--;
		if(text->reference == 0){
			free(text);
			return NULL;
		}		
	}
	return text;
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
	string->length -= string->start;
	int i = string->start;
	int l = string->length;
	
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


/*



Text *textNew(Char *CharStr);
Text *textAssign(Text *text);
Text *textDel(Text *text);

String *stringNew(Text *text);
String *stringAssign(String *string);
String *stringDel(String *string);

void stringSkip(String *string, int numChar2Skip);
void stringTrimLeft(String *string);
void stringTrimRight(String *string);
void stringTrim(String *string);


*/
