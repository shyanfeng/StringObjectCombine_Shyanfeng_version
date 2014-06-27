#include "unity.h"
#include "Token.h"
#include "Text.h"
#include "StringObject.h"
#include "CharSet.h"
#include "CustomTypeAssert.h"

void setUp(void) {}
void tearDown(void) {}

void test_getToken_should_get_5(void) {
	Number *number = numberNew(5);
	
	TEST_ASSERT_EQUAL(5,number->value);                                                                                                                                                                                                                                                                                                                                                                                                           
	TEST_ASSERT_EQUAL(NUMBER_TOKEN,number->type);
}

void test_getToken_should_get_100(void) {
	Number *number = numberNew(100);
	
	TEST_ASSERT_EQUAL(100,number->value);                                                                                                                                                                                                                                                                                                                                                                                                           
	TEST_ASSERT_EQUAL(NUMBER_TOKEN,number->type);
}

void test_identifierNew_should_get_return_details(void) {
	int toCompare;
	Text *text = textNew("Yeah");
	Identifier *identifier = identifierNew(text);
	
	toCompare = strcmp("Yeah",identifier->name->string);
	TEST_ASSERT_EQUAL(0,toCompare);
	TEST_ASSERT_EQUAL(IDENTIFIER_TOKEN,identifier->type);
}

void test_identifierNew_should_get_return_details_2(void) {
	int toCompare;
	Text *text = textNew("YaoMie");
	Identifier *identifier = identifierNew(text);
	
	toCompare = strcmp("YaoMie",identifier->name->string);
	TEST_ASSERT_EQUAL(0,toCompare);
	TEST_ASSERT_EQUAL(IDENTIFIER_TOKEN,identifier->type);
}

void test_operatorNewBySymbol_should_create(){
	int toCompare;
	Operator *operator = operatorNewBySymbol("&&");
	
	toCompare = strcmp(operator->info->symbol,"&&");
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,operator->type);
	TEST_ASSERT_EQUAL(30,operator->info->precedence);
	TEST_ASSERT_EQUAL(LOGICAL_AND_OP,operator->info->id);
	TEST_ASSERT_EQUAL(0,toCompare);
}

void test_operatorNewBySymbol_should_create2(){
	int toCompare;
	Operator *operator = operatorNewBySymbol("~");
	
	toCompare = strcmp(operator->info->symbol,"~");
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,operator->type);
	TEST_ASSERT_EQUAL(150,operator->info->precedence);
	TEST_ASSERT_EQUAL(BITWISE_NOT_OP,operator->info->id);
	TEST_ASSERT_EQUAL(0,toCompare);
}

void test_operatorNewBySymbol_should_retun_NULL(){
	int toCompare;
	Operator *operator = operatorNewBySymbol("?");
	
	TEST_ASSERT_EQUAL(NULL,operator);
}

void test_operatorNewByID_should_create(){
	int toCompare;
	Operator *operator = operatorNewByID(BITWISE_NOT_OP);
	
	toCompare = strcmp(operator->info->symbol,"~");
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,operator->type);
	TEST_ASSERT_EQUAL(150,operator->info->precedence);
	TEST_ASSERT_EQUAL(BITWISE_NOT_OP,operator->info->id);
	TEST_ASSERT_EQUAL(0,toCompare);
}

void test_operatorNewByID_should_create2(){
	int toCompare;
	Operator *operator = operatorNewByID(LOGICAL_AND_OP);
	
	toCompare = strcmp(operator->info->symbol,"&&");
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,operator->type);
	TEST_ASSERT_EQUAL(30,operator->info->precedence);
	TEST_ASSERT_EQUAL(LOGICAL_AND_OP,operator->info->id);
	TEST_ASSERT_EQUAL(0,toCompare);
}

void test_operatorNewByID_should_retun_NULL(){
	int toCompare;
	Operator *operator = operatorNewByID(123);
	
	TEST_ASSERT_EQUAL(NULL,operator);
}

void test_getToken(void){
	int test;
	Text *text = textNew("&& ert 01010");
	String *string = stringNew(text);
	Token *token = getToken(string);
	
	// TEST_ASSERT_EQUAL(IDENTIFIER_TOKEN,token->type);
	// printf("%d\n",token->value);
	// TEST_ASSERT_EQUAL(323243451,token->value);

}


