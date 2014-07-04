#include "unity.h"
#include "Interpret.h"
#include "CException.h"
#include "String.h"
#include "StringObject.h"
#include "Token.h"
#include "Text.h"
#include "CharSet.h"
#include "ErrorCode.h"
#include "CustomTypeAssert.h"
#include "mock_evaluate.h"

void setUp(void){}
void tearDown(void){}

void test_extractValue_should_return_correct_value_in_integer(void){
	Text *text = textNew("12+34,f,BANKED");
	String *string = stringNew(text);
	
	char *stringMock = "12+34";
	int test;
	
	evaluate_ExpectAndReturn(stringMock,46);
	test = extractValue(string);
	
	TEST_ASSERT_EQUAL(46,test);
}

void test_extractValue_should_throw_error_with_empty_argument(void){
	Text *text = textNew("      ; ");
	String *string = stringNew(text);
	
	int test,e;
	
	Try{
		test = extractValue(string);}
	Catch(e){
		TEST_ASSERT_EQUAL(EMPTY_ARGUMENT,e);
	}
}

void test_extractValue_should_throw_error_with_empty_argument_semicolon(void){
	Text *text = textNew(";123 ");
	String *string = stringNew(text);
	
	int test,e;
	
	Try{
		test = extractValue(string);}
	Catch(e){
		TEST_ASSERT_EQUAL(EMPTY_ARGUMENT,e);
	}
}

void test_extractValue_should_get_thrown_in_evaluate(void){
	Text *text = textNew("    12+34abc   ,yaomie");
	String *string = stringNew(text);
	
	char *stringMock = "12+34abc";
	int test,e;
	
	evaluate_ExpectAndThrow(stringMock,ILLEGAL_DESTINATION);
	
	Try{
		test = extractValue(string);}
	Catch(e){
		TEST_ASSERT_EQUAL(ILLEGAL_DESTINATION,e);
	}
}
