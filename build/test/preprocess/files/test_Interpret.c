#include "unity.h"
#include "mock_operator.h"
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



 evaluate_CMockExpectAndReturn(25, stringMock, 46);

 test = extractValue(string);



 UnityAssertEqualNumber((_U_SINT)((46)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)28, UNITY_DISPLAY_STYLE_INT);

}



void test_extractValue_should_throw_error_with_empty_argument(void){

 Text *text = textNew("      ; ");

 String *string = stringNew(text);



 int test,e;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  test = extractValue(string);}

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_EMPTY_ARGUMENT)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)40, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_extractValue_should_throw_error_with_empty_argument_semicolon(void){

 Text *text = textNew(";123 ");

 String *string = stringNew(text);



 int test,e;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  test = extractValue(string);}

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_EMPTY_ARGUMENT)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)53, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_extractValue_should_get_thrown_in_evaluate(void){

 Text *text = textNew("    12+34abc   ,yaomie");

 String *string = stringNew(text);



 char *stringMock = "12+34abc";

 int test,e;



 evaluate_CMockExpectAndThrow(64, stringMock, ERR_ILLEGAL_ARGUMENT);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  test = extractValue(string);}

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_ILLEGAL_ARGUMENT)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)69, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_extractDestination_should_return_correct_value_in_integer(void){

 Text *text = textNew("12+34,F,BANKED");

 String *string = stringNew(text);



 char *stringMock = "12+34";

 int test;



 evaluate_CMockExpectAndReturn(80, stringMock, 46);

 test = extractValue(string);

 UnityAssertEqualNumber((_U_SINT)((46)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)82, UNITY_DISPLAY_STYLE_INT);



 test = extractDestination(string);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)85, UNITY_DISPLAY_STYLE_INT);

}



void test_extractDestination_should_throw_error_with_empty_argument(void){

 Text *text = textNew("      ; ");

 String *string = stringNew(text);



 int test,e;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  test = extractDestination(string);}

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_EMPTY_ARGUMENT)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)97, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_extractDestination_should_throw_error_with_empty_argument_semicolon(void){

 Text *text = textNew(";F ");

 String *string = stringNew(text);



 int test,e;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  test = extractDestination(string);}

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_NO_ARGUMENT)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)110, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_extractDestination_should_get_value_from_evaluate(void){

 Text *text = textNew("123,  1    ,BANKED");

 String *string = stringNew(text);



 char *stringMock = "123";

 int test,e;



 evaluate_CMockExpectAndReturn(121, stringMock, 123);

 test = extractValue(string);

 UnityAssertEqualNumber((_U_SINT)((123)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)123, UNITY_DISPLAY_STYLE_INT);



 stringMock = "1";

 evaluate_CMockExpectAndReturn(126, stringMock, 1);

 test = extractDestination(string);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)128, UNITY_DISPLAY_STYLE_INT);



}



void test_extractDestination_should_get_value_from_F(void){

 Text *text = textNew("123,  F   ,BANKED");

 String *string = stringNew(text);



 char *stringMock = "123";

 int test,e;



 evaluate_CMockExpectAndReturn(139, stringMock, 123);

 test = extractValue(string);

 UnityAssertEqualNumber((_U_SINT)((123)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)141, UNITY_DISPLAY_STYLE_INT);



 test = extractDestination(string);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)144, UNITY_DISPLAY_STYLE_INT);



}



void test_extractDestination_should_throw_with_invalid_argument(void){

 Text *text = textNew("123,  FA   ,BANKED");

 String *string = stringNew(text);



 char *stringMock = "123";

 int test,e;



 evaluate_CMockExpectAndReturn(155, stringMock, 123);

 test = extractValue(string);

 UnityAssertEqualNumber((_U_SINT)((123)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)157, UNITY_DISPLAY_STYLE_INT);



 stringMock = "FA";

 evaluate_CMockExpectAndThrow(160, stringMock, ERR_ILLEGAL_ARGUMENT);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  test = extractDestination(string);}

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_ILLEGAL_ARGUMENT)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)165, UNITY_DISPLAY_STYLE_INT);

 }



}



void test_extractAccessBanked_should_return_correct_value_in_integer(void){

 Text *text = textNew("12+34,F,3");

 String *string = stringNew(text);



 char *stringMock = "12+34";

 int test;



 evaluate_CMockExpectAndReturn(177, stringMock, 46);

 test = extractValue(string);

 UnityAssertEqualNumber((_U_SINT)((46)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)179, UNITY_DISPLAY_STYLE_INT);



 test = extractDestination(string);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)182, UNITY_DISPLAY_STYLE_INT);



 stringMock = "3";

 evaluate_CMockExpectAndReturn(185, stringMock, 3);

 test = extractAccessBanked(string);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)187, UNITY_DISPLAY_STYLE_INT);

}



void test_extractAccessBanked_should_throw_error_with_empty_argument(void){

 Text *text = textNew(" 123, F,     ; ");

 String *string = stringNew(text);



 char *stringMock = "123";

 int test,e;



 evaluate_CMockExpectAndReturn(197, stringMock, 123);

 test = extractValue(string);

 UnityAssertEqualNumber((_U_SINT)((123)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)199, UNITY_DISPLAY_STYLE_INT);



 stringMock = "F";

 test = extractDestination(string);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)203, UNITY_DISPLAY_STYLE_INT);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  test = extractAccessBanked(string);

 }

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_EMPTY_ARGUMENT)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)209, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_extractAccessBanked_should_throw_error_with_empty_argument_semicolon(void){

 Text *text = textNew("123,  F   ;");

 String *string = stringNew(text);



 char *stringMock = "123";

 int test,e;



 evaluate_CMockExpectAndReturn(220, stringMock, 123);

 test = extractValue(string);

 UnityAssertEqualNumber((_U_SINT)((123)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)222, UNITY_DISPLAY_STYLE_INT);



 stringMock = "F";

 test = extractDestination(string);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)226, UNITY_DISPLAY_STYLE_INT);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  test = extractAccessBanked(string);

 }

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_NO_ARGUMENT)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)232, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_extractAccessBaked_should_get_value_from_ACCESS(void){

 Text *text = textNew("1+2,  F   ,ACCESS");

 String *string = stringNew(text);



 char *stringMock = "1+2";

 int test,e;



 evaluate_CMockExpectAndReturn(243, stringMock, 3);

 test = extractValue(string);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)245, UNITY_DISPLAY_STYLE_INT);



 stringMock = "F";

 test = extractDestination(string);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)249, UNITY_DISPLAY_STYLE_INT);



 stringMock = "ACCESS";

 test = extractAccessBanked(string);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)253, UNITY_DISPLAY_STYLE_INT);



}



void test_extractAccessBanked_should_get_value_from_evaluate(void){

 Text *text = textNew("   123   , 1    ,1+2");

 String *string = stringNew(text);



 char *stringMock = "123";

 int test,e;



 evaluate_CMockExpectAndReturn(264, stringMock, 123);

 test = extractValue(string);

 UnityAssertEqualNumber((_U_SINT)((123)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)266, UNITY_DISPLAY_STYLE_INT);



 stringMock = "1";

 evaluate_CMockExpectAndReturn(269, stringMock, 1);

 test = extractDestination(string);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)271, UNITY_DISPLAY_STYLE_INT);



 stringMock = "1+2";

 evaluate_CMockExpectAndReturn(274, stringMock, 3);

 test = extractAccessBanked(string);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)276, UNITY_DISPLAY_STYLE_INT);



}



  void test_extractValue_should_able_to_throw_NO_ARGUMENT_for_both(void){

 Text *text = textNew("123   ");

 String *string = stringNew(text);



 char *stringMock = "123";

 int test,e;



 evaluate_CMockExpectAndReturn(287, stringMock, 123);

 test = extractValue(string);

 UnityAssertEqualNumber((_U_SINT)((123)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)289, UNITY_DISPLAY_STYLE_INT);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  test = extractDestination(string);}

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_NO_ARGUMENT)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)294, UNITY_DISPLAY_STYLE_INT);

 }



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  test = extractAccessBanked(string);}

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_NO_ARGUMENT)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)300, UNITY_DISPLAY_STYLE_INT);

 }

}



 void test_extractValue_should_able_to_throw_EMPTY_ARGUMENT(void){

 Text *text = textNew("123,   , ");

 String *string = stringNew(text);



 char *stringMock = "123";

 int test,e;



 evaluate_CMockExpectAndReturn(311, stringMock, 123);

 test = extractValue(string);

 UnityAssertEqualNumber((_U_SINT)((123)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)313, UNITY_DISPLAY_STYLE_INT);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  test = extractDestination(string);}

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_EMPTY_ARGUMENT)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)318, UNITY_DISPLAY_STYLE_INT);

 }



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  test = extractAccessBanked(string);}

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_EMPTY_ARGUMENT)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)324, UNITY_DISPLAY_STYLE_INT);

 }

}



 void test_extractValue_should_able_to_throw_NO_ARGUMENT(void){

 Text *text = textNew("123,    ");

 String *string = stringNew(text);



 char *stringMock = "123";

 int test,e;



 evaluate_CMockExpectAndReturn(335, stringMock, 123);

 test = extractValue(string);

 UnityAssertEqualNumber((_U_SINT)((123)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)337, UNITY_DISPLAY_STYLE_INT);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  test = extractDestination(string);}

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_EMPTY_ARGUMENT)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)342, UNITY_DISPLAY_STYLE_INT);

 }



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  test = extractAccessBanked(string);}

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_NO_ARGUMENT)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)348, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_getInstruction_should_get_opCode_RLNCF(){



 instructionTable test;



 test = getInstruction("RLNCF");

 UnityAssertEqualNumber((_U_SINT)(_US16)((0x4400)), (_U_SINT)(_US16)((test.opCode)), (((void *)0)), (_U_UINT)357, UNITY_DISPLAY_STYLE_HEX16);

 UnityAssertEqualNumber((_U_SINT)((FDA_TYPE)), (_U_SINT)((test.type)), (((void *)0)), (_U_UINT)358, UNITY_DISPLAY_STYLE_INT);

}



void test_getInstruction_should_get_opCode_RETLW(){



 instructionTable test;



 test = getInstruction("RETLW");

 UnityAssertEqualNumber((_U_SINT)(_US16)((0x0C00)), (_U_SINT)(_US16)((test.opCode)), (((void *)0)), (_U_UINT)366, UNITY_DISPLAY_STYLE_HEX16);

 UnityAssertEqualNumber((_U_SINT)((K_TYPE)), (_U_SINT)((test.type)), (((void *)0)), (_U_UINT)367, UNITY_DISPLAY_STYLE_INT);

}



void test_interpret_should_able_to_get_correct_value(){

 Text *text = textNew(" ADDWF  0x20, F, BANKED");

 String *string = stringNew(text);



 FDA_CMockExpectAndReturn(374, string, 0x320);

 int test = interpret(string);



 UnityAssertEqualNumber((_U_SINT)((0x2720)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)377, UNITY_DISPLAY_STYLE_INT);



}



void test_interpret_should_throw_an_error_for_unexist_instruction(){

 Text *text = textNew(" SUBWFWFWF  0x20, F, BANKED");

 String *string = stringNew(text);

 int e;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  int test = interpret(string);}

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_ILLEGAL_ARGUMENT)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)389, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_interpret_should_throw_an_error_for_invalid_input_instruction(){

 Text *text = textNew(" SUBWF  0x20, HAHA, BANKED");

 String *string = stringNew(text);

 int e;



 FDA_CMockExpectAndThrow(398, string, ERR_ILLEGAL_ARGUMENT);

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  int test = interpret(string);}

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_ILLEGAL_ARGUMENT)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)402, UNITY_DISPLAY_STYLE_INT);

 }

}
