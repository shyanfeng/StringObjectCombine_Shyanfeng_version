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



void test_extractDestination_should_return_correct_value_in_integer(void){

 Text *text = textNew("12+34,F,BANKED");

 String *string = stringNew(text);



 char *stringMock = "12+34";

 int test;



 evaluate_CMockExpectAndReturn(78, stringMock, 46);

 test = extractValue(string);

 UnityAssertEqualNumber((_U_SINT)((46)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)80, UNITY_DISPLAY_STYLE_INT);



 test = extractDestination(string);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)83, UNITY_DISPLAY_STYLE_INT);

}



void test_extractDestination_should_throw_error_with_empty_argument(void){

 Text *text = textNew("      ; ");

 String *string = stringNew(text);



 int test,e;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  test = extractDestination(string);}

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((EMPTY_ARGUMENT)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)95, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_extractDestination_should_throw_error_with_empty_argument_semicolon(void){

 Text *text = textNew(";F ");

 String *string = stringNew(text);



 int test,e;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  test = extractDestination(string);}

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((EMPTY_ARGUMENT)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)108, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_extractDestination_should_get_value_from_evaluate(void){

 Text *text = textNew("123,  1    ,BANKED");

 String *string = stringNew(text);



 char *stringMock = "123";

 int test,e;



 evaluate_CMockExpectAndReturn(119, stringMock, 123);

 test = extractValue(string);

 UnityAssertEqualNumber((_U_SINT)((123)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)121, UNITY_DISPLAY_STYLE_INT);



 stringMock = "1";

 evaluate_CMockExpectAndReturn(124, stringMock, 1);

 test = extractDestination(string);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)126, UNITY_DISPLAY_STYLE_INT);



}



void test_extractDestination_should_get_value_from_F(void){

 Text *text = textNew("123,  F   ,BANKED");

 String *string = stringNew(text);



 char *stringMock = "123";

 int test,e;



 evaluate_CMockExpectAndReturn(137, stringMock, 123);

 test = extractValue(string);

 UnityAssertEqualNumber((_U_SINT)((123)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)139, UNITY_DISPLAY_STYLE_INT);



 test = extractDestination(string);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)142, UNITY_DISPLAY_STYLE_INT);



}



void test_extractDestination_should_throw_with_invalid_argument(void){

 Text *text = textNew("123,  FA   ,BANKED");

 String *string = stringNew(text);



 char *stringMock = "123";

 int test,e;



 evaluate_CMockExpectAndReturn(153, stringMock, 123);

 test = extractValue(string);

 UnityAssertEqualNumber((_U_SINT)((123)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)155, UNITY_DISPLAY_STYLE_INT);



 stringMock = "FA";

 evaluate_CMockExpectAndThrow(158, stringMock, ILLEGAL_DESTINATION);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  test = extractDestination(string);}

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ILLEGAL_DESTINATION)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)163, UNITY_DISPLAY_STYLE_INT);

 }



}



void test_extractAccessBanked_should_return_correct_value_in_integer(void){

 Text *text = textNew("12+34,F,3");

 String *string = stringNew(text);



 char *stringMock = "12+34";

 int test;



 evaluate_CMockExpectAndReturn(175, stringMock, 46);

 test = extractValue(string);

 UnityAssertEqualNumber((_U_SINT)((46)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)177, UNITY_DISPLAY_STYLE_INT);



 test = extractDestination(string);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)180, UNITY_DISPLAY_STYLE_INT);



 stringMock = "3";

 evaluate_CMockExpectAndReturn(183, stringMock, 3);

 test = extractAccessBanked(string);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)185, UNITY_DISPLAY_STYLE_INT);

}



void test_extractAccessBanked_should_throw_error_with_empty_argument(void){

 Text *text = textNew(" 123, F,     ; ");

 String *string = stringNew(text);



 char *stringMock = "123";

 int test,e;



 evaluate_CMockExpectAndReturn(195, stringMock, 123);

 test = extractValue(string);

 UnityAssertEqualNumber((_U_SINT)((123)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)197, UNITY_DISPLAY_STYLE_INT);



 stringMock = "F";

 test = extractDestination(string);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)201, UNITY_DISPLAY_STYLE_INT);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  test = extractAccessBanked(string);

 }

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((EMPTY_ARGUMENT)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)207, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_extractAccessBanked_should_throw_error_with_empty_argument_semicolon(void){

 Text *text = textNew("123,  F   ;");

 String *string = stringNew(text);



 char *stringMock = "123";

 int test,e;



 evaluate_CMockExpectAndReturn(218, stringMock, 123);

 test = extractValue(string);

 UnityAssertEqualNumber((_U_SINT)((123)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)220, UNITY_DISPLAY_STYLE_INT);



 stringMock = "F";

 test = extractDestination(string);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)224, UNITY_DISPLAY_STYLE_INT);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  test = extractAccessBanked(string);

 }

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((EMPTY_ARGUMENT)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)230, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_extractAccessBaked_should_get_value_from_ACCESS(void){

 Text *text = textNew("1+2,  F   ,ACCESS");

 String *string = stringNew(text);



 char *stringMock = "1+2";

 int test,e;



 evaluate_CMockExpectAndReturn(241, stringMock, 3);

 test = extractValue(string);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)243, UNITY_DISPLAY_STYLE_INT);



 stringMock = "F";

 test = extractDestination(string);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)247, UNITY_DISPLAY_STYLE_INT);



 stringMock = "ACCESS";

 test = extractAccessBanked(string);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)251, UNITY_DISPLAY_STYLE_INT);



}



void test_extractAccessBanked_should_get_value_from_evaluate(void){

 Text *text = textNew("   123   , 1    ,1+2");

 String *string = stringNew(text);



 char *stringMock = "123";

 int test,e;



 evaluate_CMockExpectAndReturn(262, stringMock, 123);

 test = extractValue(string);

 UnityAssertEqualNumber((_U_SINT)((123)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)264, UNITY_DISPLAY_STYLE_INT);



 stringMock = "1";

 evaluate_CMockExpectAndReturn(267, stringMock, 1);

 test = extractDestination(string);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)269, UNITY_DISPLAY_STYLE_INT);



 stringMock = "1+2";

 evaluate_CMockExpectAndReturn(272, stringMock, 3);

 test = extractAccessBanked(string);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)274, UNITY_DISPLAY_STYLE_INT);



}
