#ifndef __STRING_OBJECT_H__
#define __STRING_OBJECT_H__

#include "Types.h"
#define t (Text *)"\x00\x00\x00\x80"
#define isSpace(ch) (ch==' ' || ch=='\t')

typedef struct Text{
	uint32 reference;
	char string[0];
}Text;

typedef struct String{
	uint32 reference;
	Text *text;
	uint32 start;
	uint32 length;
}String;

//test prototype
Text *textNew(char *CharStr);
Text *textAssign(Text *text);
Text *textDel(Text *text);

String *stringNew(Text *text);
String *stringAssign(String *string);
String *stringDel(String *string);

void stringSkip(String *string, int numChar2Skip);
void stringTrimLeft(String *string);
void stringTrimRight(String *string);
void stringTrim(String *string);

	
#endif // __STRING_OBJECT_H__