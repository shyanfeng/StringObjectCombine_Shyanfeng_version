#include <stdio.h>
#include <malloc.h>
#include "String.h"
#include "Text.h"


void textDump(Text *text){
	if(text==NULL){
		printf("(NULL)");
		return;
	}
	printf("text[0x%x];%s\n", text->reference, text->string);
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