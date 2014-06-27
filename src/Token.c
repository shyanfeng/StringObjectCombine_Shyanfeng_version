#include <stdio.h>
#include <malloc.h>
#include "Token.h"
#include "CharSet.h"

#define MAIN_OPERATOR_TABLE_SIZE	(sizeof(mainOperatorTable)/sizeof(OperatorInfo))
#define	ALTERNATIVE_OPERATOR_TABLE_SIZE	(sizeof(alternativeOperatorTable)/sizeof(OperatorInfo))

OperatorInfo mainOperatorTable[] = {
  {.symbol="~", .id=BITWISE_NOT_OP, .precedence=150, .affix=INFIX, .assoc=LEFT_TO_RIGHT},
  {.symbol="!", .id=LOGICAL_NOT_OP, .precedence=150, .affix=INFIX, .assoc=LEFT_TO_RIGHT},
  {.symbol="*", .id=MUL_OP, .precedence=100, .affix=INFIX, .assoc=LEFT_TO_RIGHT},
  {.symbol="/", .id=DIV_OP, .precedence=100, .affix=INFIX, .assoc=LEFT_TO_RIGHT},
  {.symbol="%", .id=MOD_OP, .precedence=100, .affix=INFIX, .assoc=LEFT_TO_RIGHT},
  {.symbol="+", .id=ADD_OP, .precedence=80, .affix=INFIX, .assoc=LEFT_TO_RIGHT},
  {.symbol="-", .id=SUB_OP, .precedence=80, .affix=INFIX, .assoc=LEFT_TO_RIGHT},
  {.symbol="&", .id=BITWISE_AND_OP, .precedence=60, .affix=INFIX, .assoc=LEFT_TO_RIGHT},
  {.symbol="^", .id=BITWISE_XOR_OP, .precedence=50, .affix=INFIX, .assoc=LEFT_TO_RIGHT},
  {.symbol="|", .id=BITWISE_OR_OP, .precedence=40, .affix=INFIX, .assoc=LEFT_TO_RIGHT},  
  {.symbol="&&", .id=LOGICAL_AND_OP, .precedence=30, .affix=INFIX, .assoc=LEFT_TO_RIGHT},
  {.symbol="||", .id=LOGICAL_OR_OP, .precedence=20, .affix=INFIX, .assoc=LEFT_TO_RIGHT},
  // All other symbols MUST have higher precedence than those below:
  {.symbol="(", .id=OPENING_BRACKET_OP, .precedence=10, .affix=PREFIX, .assoc=RIGHT_TO_LEFT},
  {.symbol=")", .id=CLOSING_BRACKET_OP, .precedence=9,  .affix=POSTFIX, .assoc=LEFT_TO_RIGHT}
};

OperatorInfo alternativeOperatorTable[] = {
  {.symbol="+", .id=PLUS_OP, .precedence=150, .affix=PREFIX, .assoc=RIGHT_TO_LEFT},
  {.symbol="-", .id=MINUS_OP, .precedence=150, .affix=PREFIX, .assoc=RIGHT_TO_LEFT}
};

/**
 *
 * Input:
 *   value  is the value to initialized with
 */
Number *numberNew(int value) {
	Number *number = malloc(sizeof(Number));
	number->value = value;
	number->type = NUMBER_TOKEN;
	return number;
}

/**
 * Create an Operator token identified by symbol.
 *
 * Input:
 *   symbol is symbol in string of characters, i.e., "*"
 *          and "&&".
 */
Operator *operatorNewBySymbol(char *symbol) {
	int i;
	Operator *operator = malloc(sizeof(Operator));
	operator->type = OPERATOR_TOKEN;
	
	for(i=0;i < MAIN_OPERATOR_TABLE_SIZE; i++){
		if(strcmp(mainOperatorTable[i].symbol,symbol) == 0){
			operator->info = &mainOperatorTable[i];
			return operator;
		}
	}
	return NULL;
}

/**
 * Create an Operator token identified by the ID.
 *
 * Input:
 *   symbol is symbol in string of characters, i.e., MUL_OP
 *          and CLOSING_BRACKET_OP.
 */
Operator *operatorNewByID(OperatorID id) {
	int i;
	Operator *operator = malloc(sizeof(Operator));
	operator->type = OPERATOR_TOKEN;
	
	for(i=0;i < MAIN_OPERATOR_TABLE_SIZE; i++){
		if(mainOperatorTable[i].id == id){
			operator->info = &mainOperatorTable[i];
			return operator;
		}
	}
	return NULL;
}

/**
 * Create an Identifier token initialized with the name
 * given.
 *
 * Input:
 *   name is the name of the identifier.
 */
Identifier *identifierNew(Text *name) {
  Identifier *identifier = malloc(sizeof(Identifier));
  identifier->name = name;
  identifier->type = IDENTIFIER_TOKEN;
  return identifier;
}

/**
 * Return the one token from the String. The String is updated.
 * If the string is empty, NULL is return.
 *
 * Input:
 *   str  is the String object
 *
 * Possible returned token:
 *    Number, Operator, and Identifier tokens
 */

Token *getToken(String *str) {
	//1 trim left
	//2 check first character
	//	a	-if a number then extract the number string
	//		-convert into integer
	//		-create number token
	//	b	-if alphabetSet then extract the identifier
	//		-create identifier token
	//	c	-if operator set then extract operator symbol
	//		-create operator token
	char charReturn[3];
	Token *tokenReturn;
	String *strReturn = stringNew(str->text);
	stringTrimLeft(str);
	
	
	
	// if(stringIsCharAtInSet(str,str->start,numberSet)){
		// strReturn = stringRemoveWordContaining(str,numberSet);
		// if(isSpace(stringCharAt(str,0))){
			// Number *number = numberNew(stringToInteger(strReturn));
			// tokenReturn = (Token *)number;
			// return tokenReturn;
		// }
		// else
			// return NULL;
	// }
	
	// else if(stringIsCharAtInSet(str,str->start,alphabetSet)){
		// strReturn = stringRemoveWordContaining(str,alphabetSet);
		// if(isSpace(stringCharAt(str,0))){
			// Identifier *identifier = identifierNew(stringSubstringInText(strReturn,strReturn->start,strReturn->length));
			// stringDump(strReturn);
		// }
		// else
			// return NULL;
	// }
	
	if(stringIsCharAtInSet(str,str->start,operatorSet)){
		charReturn[0] = (char )stringRemoveChar(str);
		charReturn[1] = 0;

		if(stringCharAt(str,0) == charReturn[0]){
			printf("%d\n",str->start);	
			if(charReturn[0] == '&'){
				charReturn[0] = '&';
				charReturn[1] = '&';
				charReturn[2] = 0;
			}
			else if(charReturn[0] == '|'){
				charReturn[0] = '|';
				charReturn[1] = '|';
				charReturn[2] = 0;
			}	
			str->start++;
			str->length--;
		}
			
		if(isSpace(stringCharAt(str,0))){
			printf("%d\n",str->start);
			Operator *operator = operatorNewBySymbol(charReturn);
			printf("%s\n",operator->info->symbol);
			printf("%d\n",operator->info->precedence);
			
		}
	}
	
		
}