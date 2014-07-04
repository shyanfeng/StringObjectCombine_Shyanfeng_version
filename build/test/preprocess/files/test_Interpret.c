#include "unity.h"
#include "mock_evaluate.h"
#include "Token.h"
#include "Text.h"
#include "StringObject.h"
#include "String.h"
#include "Interpret.h"
#include "ErrorCode.h"
#include "CustomTypeAssert.h"
#include "CharSet.h"
#include "CException.h"


void setUp(void){}

void tearDown(void){}



void test_extractValue_should_return_correct_value_in_integer(void){

 Text *text = textNew("12+34,f,BANKED");

 String *string = stringNew(text);



 char *stringMock = "12+34";

 int test;



 evaluate_CMockExpectAndReturn(23, stringMock, 46);

 test = extractValue(string);



 UnityAssertEqualNumber((_U_SINT)((46)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)26, UNITY_DISPLAY_STYLE_INT);

}



void test_extractValue_should_throw_error_with_empty_argument(void){

 Text *text = textNew("      ; ");

 String *string = stringNew(text);



 int test,e;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  test = extractValue(string);}

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((EMPTY_ARGUMENT)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)38, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_extractValue_should_throw_error_with_empty_argument_semicolon(void){

 Text *text = textNew(";123 ");

 String *string = stringNew(text);



 int test,e;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  test = extractValue(string);}

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((EMPTY_ARGUMENT)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)51, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_extractValue_should_get_thrown_in_evaluate(void){

 Text *text = textNew("    12+34abc   ,yaomie");

 String *string = stringNew(text);



 char *stringMock = "12+34abc";

 int test,e;



 evaluate_CMockExpectAndThrow(62, stringMock, ILLEGAL_DESTINATION);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  test = extractValue(string);}

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ILLEGAL_DESTINATION)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)67, UNITY_DISPLAY_STYLE_INT);

 }

}
