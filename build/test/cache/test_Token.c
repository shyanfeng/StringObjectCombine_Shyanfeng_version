#include "unity.h"
#include "Token.h"
#include "Text.h"
#include "StringObject.h"
#include "CustomTypeAssert.h"
#include "CharSet.h"


void setUp(void) {}

void tearDown(void) {}



void test_getToken_should_get_5(void) {

 Number *number = numberNew(5);



 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((number->value)), (((void *)0)), (_U_UINT)14, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)((number->type)), (((void *)0)), (_U_UINT)15, UNITY_DISPLAY_STYLE_INT);

}



void test_getToken_should_get_100(void) {

 Number *number = numberNew(100);



 UnityAssertEqualNumber((_U_SINT)((100)), (_U_SINT)((number->value)), (((void *)0)), (_U_UINT)21, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)((number->type)), (((void *)0)), (_U_UINT)22, UNITY_DISPLAY_STYLE_INT);

}



void test_identifierNew_should_get_return_details(void) {

 int toCompare;

 Text *text = textNew("Yeah");

 Identifier *identifier = identifierNew(text);



 toCompare = strcmp("Yeah",identifier->name->string);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)31, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((IDENTIFIER_TOKEN)), (_U_SINT)((identifier->type)), (((void *)0)), (_U_UINT)32, UNITY_DISPLAY_STYLE_INT);

}



void test_identifierNew_should_get_return_details_2(void) {

 int toCompare;

 Text *text = textNew("YaoMie");

 Identifier *identifier = identifierNew(text);



 toCompare = strcmp("YaoMie",identifier->name->string);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)41, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((IDENTIFIER_TOKEN)), (_U_SINT)((identifier->type)), (((void *)0)), (_U_UINT)42, UNITY_DISPLAY_STYLE_INT);

}



void test_operatorNewBySymbol_should_create(){

 int toCompare;

 Operator *operator = operatorNewBySymbol("&&");



 toCompare = strcmp(operator->info->symbol,"&&");

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator->type)), (((void *)0)), (_U_UINT)50, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((operator->info->precedence)), (((void *)0)), (_U_UINT)51, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((LOGICAL_AND_OP)), (_U_SINT)((operator->info->id)), (((void *)0)), (_U_UINT)52, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)53, UNITY_DISPLAY_STYLE_INT);

}



void test_operatorNewBySymbol_should_create2(){

 int toCompare;

 Operator *operator = operatorNewBySymbol("~");



 toCompare = strcmp(operator->info->symbol,"~");

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator->type)), (((void *)0)), (_U_UINT)61, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((150)), (_U_SINT)((operator->info->precedence)), (((void *)0)), (_U_UINT)62, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((BITWISE_NOT_OP)), (_U_SINT)((operator->info->id)), (((void *)0)), (_U_UINT)63, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)64, UNITY_DISPLAY_STYLE_INT);

}



void test_operatorNewBySymbol_should_retun_NULL(){

 int toCompare;

 Operator *operator = operatorNewBySymbol("?");



 UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((operator)), (((void *)0)), (_U_UINT)71, UNITY_DISPLAY_STYLE_INT);

}



void test_operatorNewByID_should_create(){

 int toCompare;

 Operator *operator = operatorNewByID(BITWISE_NOT_OP);



 toCompare = strcmp(operator->info->symbol,"~");

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator->type)), (((void *)0)), (_U_UINT)79, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((150)), (_U_SINT)((operator->info->precedence)), (((void *)0)), (_U_UINT)80, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((BITWISE_NOT_OP)), (_U_SINT)((operator->info->id)), (((void *)0)), (_U_UINT)81, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)82, UNITY_DISPLAY_STYLE_INT);

}



void test_operatorNewByID_should_create2(){

 int toCompare;

 Operator *operator = operatorNewByID(LOGICAL_AND_OP);



 toCompare = strcmp(operator->info->symbol,"&&");

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator->type)), (((void *)0)), (_U_UINT)90, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((operator->info->precedence)), (((void *)0)), (_U_UINT)91, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((LOGICAL_AND_OP)), (_U_SINT)((operator->info->id)), (((void *)0)), (_U_UINT)92, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)93, UNITY_DISPLAY_STYLE_INT);

}



void test_operatorNewByID_should_retun_NULL(){

 int toCompare;

 Operator *operator = operatorNewByID(123);



 UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((operator)), (((void *)0)), (_U_UINT)100, UNITY_DISPLAY_STYLE_INT);

}



void test_getToken(void){

 int test;

 Text *text = textNew("323243451 ert");

 String *string = stringNew(text);



 getToken(string);



}
