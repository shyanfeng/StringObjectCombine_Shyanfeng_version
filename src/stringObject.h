#ifndef __STRING_OBJECT_H__
#define __STRING_OBJECT_H__

#include "Types.h"
#include "Text.h"

#define isSpace(ch) (ch==' ' || ch=='\t')

typedef struct String{
	uint32 reference;
	Text *text;
	uint32 start;
	uint32 length;
}String;

//test prototype
int stringToInteger(String *str);
char *stringSubstringInChar(String *str, int relativePosition, int length);
Text *stringSubstringInText(String *str, int relativePosition, int length);

String *stringNew(Text *text);
String *stringAssign(String *string);
String *stringDel(String *string);

void stringSkip(String *string, int numChar2Skip);
void stringTrimLeft(String *string);
void stringTrimRight(String *string);
void stringTrim(String *string);

int stringRemoveChar(String *str); // return -l if empty remove by moving index number
int stringLength(String *str); // length of string
String *stringRemoveWordNotContaining(String *str,char delimites[]); 
String *stringRemoveWordContaining(String *str, char containSet[]);
int stringIsEqual(String *str1, String *str2); //1 if same, 0 otherwise do no use string compare
int stringIsEqualCaseInsensitive(String *str1, String *str2); //uses char tolower();

/**
* Return the character at the specified relative index of the String
*
* Input:
* 	str				is the String object
*	relativeIndex	is the relative index into the String.
*					This value must be positive.
*
* Return the character at the relative index if exists.
* Otherwise return -1. If relativeIndex < 0, -1 is returned as well.
*/
int stringCharAt(String *str, int relativeIndex);

/**
* Determine if the character specified by the relative index in the
* String is in the given set of characters.
*
* Input:
*	str				is the String object
*	relativeIndex	is the relative index into the String
*					This value must be positive
*	set				is the set of characters delimited by NULL
* 
* Return 1 if the character that chosen is in the set list.
* Return 0 otherwise
*/
int stringIsCharAtInSet(String *str, int relativeIndex, char set[]); //1 is true, 0 false
	
#endif // __STRING_OBJECT_H__