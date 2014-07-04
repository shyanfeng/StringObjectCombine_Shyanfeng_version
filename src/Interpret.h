#ifndef Interpret_H
#define Interpret_H

#include "StringObject.h"
int mock_evaluate(char *charbla);

unsigned int interpret(String *instruction);
int extractValue(String *arguments);
int extractDestination(String *arguments);
int extractAccessBanked(String *arguments);
#endif // Interpret_H
