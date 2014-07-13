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
#include "mock_operator.h"

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
		TEST_ASSERT_EQUAL(ERR_EMPTY_ARGUMENT,e);
	}
}

void test_extractValue_should_throw_error_with_empty_argument_semicolon(void){
	Text *text = textNew(";123 ");
	String *string = stringNew(text);
	
	int test,e;
	
	Try{
		test = extractValue(string);}
	Catch(e){
		TEST_ASSERT_EQUAL(ERR_EMPTY_ARGUMENT,e);
	}
}

void test_extractValue_should_get_thrown_in_evaluate(void){
	Text *text = textNew("    12+34abc   ,yaomie");
	String *string = stringNew(text);
	
	char *stringMock = "12+34abc";
	int test,e;
	
	evaluate_ExpectAndThrow(stringMock,ERR_ILLEGAL_ARGUMENT);
	
	Try{
		test = extractValue(string);}
	Catch(e){
		TEST_ASSERT_EQUAL(ERR_ILLEGAL_ARGUMENT,e);
	}
}

void test_extractDestination_should_return_correct_value_in_integer(void){
	Text *text = textNew("12+34,F,BANKED");
	String *string = stringNew(text);
	
	char *stringMock = "12+34";
	int test;
	
	evaluate_ExpectAndReturn(stringMock,46);
	test = extractValue(string);
	TEST_ASSERT_EQUAL(46,test);
	
	test = extractDestination(string);
	TEST_ASSERT_EQUAL(1,test);
}

void test_extractDestination_should_throw_error_with_empty_argument(void){
	Text *text = textNew("      ; ");
	String *string = stringNew(text);
	
	int test,e;
	
	Try{
		test = extractDestination(string);}
	Catch(e){
		TEST_ASSERT_EQUAL(ERR_EMPTY_ARGUMENT,e);
	}
}

void test_extractDestination_should_throw_error_with_empty_argument_semicolon(void){
	Text *text = textNew(";F ");
	String *string = stringNew(text);
	
	int test,e;
	
	Try{
		test = extractDestination(string);}
	Catch(e){
		TEST_ASSERT_EQUAL(ERR_NO_ARGUMENT,e);
	}
}

void test_extractDestination_should_get_value_from_evaluate(void){
	Text *text = textNew("123,  1    ,BANKED");
	String *string = stringNew(text);
	
	char *stringMock = "123";
	int test,e;
	
	evaluate_ExpectAndReturn(stringMock,123);
	test = extractValue(string);
	TEST_ASSERT_EQUAL(123,test);
	
	stringMock = "1";
	evaluate_ExpectAndReturn(stringMock,1);
	test = extractDestination(string);
	TEST_ASSERT_EQUAL(1,test);
	
}

void test_extractDestination_should_get_value_from_F(void){
	Text *text = textNew("123,  F   ,BANKED");
	String *string = stringNew(text);
	
	char *stringMock = "123";
	int test,e;
	
	evaluate_ExpectAndReturn(stringMock,123);
	test = extractValue(string);
	TEST_ASSERT_EQUAL(123,test);
	
	test = extractDestination(string);
	TEST_ASSERT_EQUAL(1,test);
	
}

void test_extractDestination_should_throw_with_invalid_argument(void){
	Text *text = textNew("123,  FA   ,BANKED");
	String *string = stringNew(text);
	
	char *stringMock = "123";
	int test,e;
	
	evaluate_ExpectAndReturn(stringMock,123);
	test = extractValue(string);
	TEST_ASSERT_EQUAL(123,test);
	
	stringMock = "FA";
	evaluate_ExpectAndThrow(stringMock,ERR_ILLEGAL_ARGUMENT);
	
	Try{
		test = extractDestination(string);}
	Catch(e){
		TEST_ASSERT_EQUAL(ERR_ILLEGAL_ARGUMENT,e);
	}
	
}

void test_extractAccessBanked_should_return_correct_value_in_integer(void){
	Text *text = textNew("12+34,F,3");
	String *string = stringNew(text);
	
	char *stringMock = "12+34";
	int test;
	
	evaluate_ExpectAndReturn(stringMock,46);
	test = extractValue(string);
	TEST_ASSERT_EQUAL(46,test);
	
	test = extractDestination(string);
	TEST_ASSERT_EQUAL(1,test);
	
	stringMock = "3";
	evaluate_ExpectAndReturn(stringMock,3);
	test = extractAccessBanked(string);
	TEST_ASSERT_EQUAL(3,test);
}

void test_extractAccessBanked_should_throw_error_with_empty_argument(void){
	Text *text = textNew(" 123, F,     ; ");
	String *string = stringNew(text);
	
	char *stringMock = "123";
	int test,e;
	
	evaluate_ExpectAndReturn(stringMock,123);
	test = extractValue(string);
	TEST_ASSERT_EQUAL(123,test);
	
	stringMock = "F";
	test = extractDestination(string);
	TEST_ASSERT_EQUAL(1,test);
	
	Try{
		test = extractAccessBanked(string);
	}
	Catch(e){
		TEST_ASSERT_EQUAL(ERR_EMPTY_ARGUMENT,e);
	}
}

void test_extractAccessBanked_should_throw_error_with_empty_argument_semicolon(void){
	Text *text = textNew("123,  F   ;");
	String *string = stringNew(text);
	
	char *stringMock = "123";
	int test,e;
	
	evaluate_ExpectAndReturn(stringMock,123);
	test = extractValue(string);
	TEST_ASSERT_EQUAL(123,test);
	
	stringMock = "F";
	test = extractDestination(string);
	TEST_ASSERT_EQUAL(1,test);
	
	Try{
		test = extractAccessBanked(string);
	}
	Catch(e){
		TEST_ASSERT_EQUAL(ERR_NO_ARGUMENT,e);
	}
}

void test_extractAccessBaked_should_get_value_from_ACCESS(void){
	Text *text = textNew("1+2,  F   ,ACCESS");
	String *string = stringNew(text);
	
	char *stringMock = "1+2";
	int test,e;
	
	evaluate_ExpectAndReturn(stringMock,3);
	test = extractValue(string);
	TEST_ASSERT_EQUAL(3,test);
	
	stringMock = "F";
	test = extractDestination(string);
	TEST_ASSERT_EQUAL(1,test);
	
	stringMock = "ACCESS";
	test = extractAccessBanked(string);
	TEST_ASSERT_EQUAL(0,test);
	
}

void test_extractAccessBanked_should_get_value_from_evaluate(void){
	Text *text = textNew("   123   , 1    ,1+2");
	String *string = stringNew(text);
	
	char *stringMock = "123";
	int test,e;
	
	evaluate_ExpectAndReturn(stringMock,123);
	test = extractValue(string);
	TEST_ASSERT_EQUAL(123,test);
	
	stringMock = "1";
	evaluate_ExpectAndReturn(stringMock,1);
	test = extractDestination(string);
	TEST_ASSERT_EQUAL(1,test);
	
	stringMock = "1+2";
	evaluate_ExpectAndReturn(stringMock,3);
	test = extractAccessBanked(string);
	TEST_ASSERT_EQUAL(3,test);
	
}
 
  void test_extractValue_should_able_to_throw_NO_ARGUMENT_for_both(void){
	Text *text = textNew("123   ");
	String *string = stringNew(text);
	
	char *stringMock = "123";
	int test,e;
	
	evaluate_ExpectAndReturn(stringMock,123);
	test = extractValue(string);
	TEST_ASSERT_EQUAL(123,test);
	
	Try{
		test = extractDestination(string);}
	Catch(e){
		TEST_ASSERT_EQUAL(ERR_NO_ARGUMENT,e);
	}
	
	Try{
		test = extractAccessBanked(string);}
	Catch(e){
		TEST_ASSERT_EQUAL(ERR_NO_ARGUMENT,e);
	}
}
 
 void test_extractValue_should_able_to_throw_EMPTY_ARGUMENT(void){
	Text *text = textNew("123,   , ");
	String *string = stringNew(text);
	
	char *stringMock = "123";
	int test,e;
	
	evaluate_ExpectAndReturn(stringMock,123);
	test = extractValue(string);
	TEST_ASSERT_EQUAL(123,test);
	
	Try{
		test = extractDestination(string);}
	Catch(e){
		TEST_ASSERT_EQUAL(ERR_EMPTY_ARGUMENT,e);
	}
	
	Try{
		test = extractAccessBanked(string);}
	Catch(e){
		TEST_ASSERT_EQUAL(ERR_EMPTY_ARGUMENT,e);
	}
}
 
 void test_extractValue_should_able_to_throw_NO_ARGUMENT(void){
	Text *text = textNew("123,    ");
	String *string = stringNew(text);
	
	char *stringMock = "123";
	int test,e;
	
	evaluate_ExpectAndReturn(stringMock,123);
	test = extractValue(string);
	TEST_ASSERT_EQUAL(123,test);
	
	Try{
		test = extractDestination(string);}
	Catch(e){
		TEST_ASSERT_EQUAL(ERR_EMPTY_ARGUMENT,e);
	}
	
	Try{
		test = extractAccessBanked(string);}
	Catch(e){
		TEST_ASSERT_EQUAL(ERR_NO_ARGUMENT,e);
	}
}

void test_getInstruction_should_get_opCode_RLNCF(){
	
	instructionTable test;
	
	test = getInstruction("RLNCF");
	TEST_ASSERT_EQUAL_HEX16(0x4400,test.opCode);
	TEST_ASSERT_EQUAL(FDA_TYPE,test.type);	
}

void test_getInstruction_should_get_opCode_RETLW(){
	
	instructionTable test;
	
	test = getInstruction("RETLW");
	TEST_ASSERT_EQUAL_HEX16(0x0C00,test.opCode);
	TEST_ASSERT_EQUAL(K_TYPE,test.type);	
}

void test_interpret_should_able_to_get_correct_value(){
	Text *text = textNew(" ADDWF  0x20, F, BANKED");
	String *string = stringNew(text);
	
	FDA_ExpectAndReturn(string,0x320);
	int test = interpret(string);
	
	TEST_ASSERT_EQUAL(0x2720,test);

}

void test_interpret_should_throw_an_error_for_unexist_instruction(){
	Text *text = textNew(" SUBWFWFWF  0x20, F, BANKED");
	String *string = stringNew(text);
	int e;
	
	Try{
		int test = interpret(string);}
	Catch(e){
		TEST_ASSERT_EQUAL(ERR_ILLEGAL_ARGUMENT,e);
	}
}

void test_interpret_should_throw_an_error_for_invalid_input_instruction(){
	Text *text = textNew(" SUBWF  0x20, HAHA, BANKED");
	String *string = stringNew(text);
	int e;
	
	FDA_ExpectAndThrow(string,ERR_ILLEGAL_ARGUMENT);
	Try{
		int test = interpret(string);}
	Catch(e){
		TEST_ASSERT_EQUAL(ERR_ILLEGAL_ARGUMENT,e);
	}
}