#ifndef Text_H
#define Text_H

#include "Types.h"
#define t (Text *)"\x00\x00\x00\x80"

typedef struct Text{
	uint32 reference;
	char string[0];
}Text;

//test prototype
Text *textNew(char *CharStr);
Text *textAssign(Text *text);
Text *textDel(Text *text);

#endif // Text_H
