#include "unity.h"
#include "mock_OpCodeDecoder.h"
#include "mock_Evaluate.h"
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

  UnityAssertEqualNumber((_U_SINT)((ERR_NO_ARGUMENT)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)40, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_extractValue_should_throw_error_with_empty_argument_semicolon(void){

 Text *text = textNew(";123 ");

 String *string = stringNew(text);



 int test,e;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  test = extractValue(string);}

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_NO_ARGUMENT)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)53, UNITY_DISPLAY_STYLE_INT);

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



void test_extractValue_should_supports_FsFd_instruction(void){

 Text *text = textNew(" 123  , 321");

 String *string = stringNew(text);



 char *stringMock;

 int test;



 stringMock = "123";

 evaluate_CMockExpectAndReturn(81, stringMock, 123);

 test = extractValue(string);

 UnityAssertEqualNumber((_U_SINT)((123)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)83, UNITY_DISPLAY_STYLE_INT);



 stringMock = "321";

 evaluate_CMockExpectAndReturn(86, stringMock, 321);

 test = extractValue(string);

 UnityAssertEqualNumber((_U_SINT)((321)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)88, UNITY_DISPLAY_STYLE_INT);

}



void test_extractDestination_should_return_correct_value_in_integer(void){

 Text *text = textNew("12+34,F,BANKED");

 String *string = stringNew(text);



 char *stringMock = "12+34";

 int test;



 evaluate_CMockExpectAndReturn(98, stringMock, 46);

 test = extractValue(string);

 UnityAssertEqualNumber((_U_SINT)((46)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)100, UNITY_DISPLAY_STYLE_INT);



 test = extractDestination(string);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)103, UNITY_DISPLAY_STYLE_INT);

}



void test_extractDestination_should_throw_error_with_empty_argument(void){

 Text *text = textNew("      ; ");

 String *string = stringNew(text);



 int test,e;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  test = extractDestination(string);}

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_EMPTY_ARGUMENT)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)115, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_extractDestination_should_throw_error_with_empty_argument_semicolon(void){

 Text *text = textNew(";F ");

 String *string = stringNew(text);



 int test,e;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  test = extractDestination(string);}

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_NO_ARGUMENT)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)128, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_extractDestination_should_get_value_from_evaluate(void){

 Text *text = textNew("123,  1    ,BANKED");

 String *string = stringNew(text);



 char *stringMock = "123";

 int test,e;



 evaluate_CMockExpectAndReturn(139, stringMock, 123);

 test = extractValue(string);

 UnityAssertEqualNumber((_U_SINT)((123)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)141, UNITY_DISPLAY_STYLE_INT);



 stringMock = "1";

 evaluate_CMockExpectAndReturn(144, stringMock, 1);

 test = extractDestination(string);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)146, UNITY_DISPLAY_STYLE_INT);



}



void test_extractDestination_should_get_value_from_F(void){

 Text *text = textNew("123,  F   ,BANKED");

 String *string = stringNew(text);



 char *stringMock = "123";

 int test,e;



 evaluate_CMockExpectAndReturn(157, stringMock, 123);

 test = extractValue(string);

 UnityAssertEqualNumber((_U_SINT)((123)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)159, UNITY_DISPLAY_STYLE_INT);



 test = extractDestination(string);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)162, UNITY_DISPLAY_STYLE_INT);



}



void test_extractDestination_should_throw_with_invalid_argument(void){

 Text *text = textNew("123,  FA   ,BANKED");

 String *string = stringNew(text);



 char *stringMock = "123";

 int test,e;



 evaluate_CMockExpectAndReturn(173, stringMock, 123);

 test = extractValue(string);

 UnityAssertEqualNumber((_U_SINT)((123)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)175, UNITY_DISPLAY_STYLE_INT);



 stringMock = "FA";

 evaluate_CMockExpectAndThrow(178, stringMock, ERR_ILLEGAL_ARGUMENT);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  test = extractDestination(string);}

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_ILLEGAL_ARGUMENT)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)183, UNITY_DISPLAY_STYLE_INT);

 }



}



void test_extractAccessBanked_should_return_correct_value_in_integer(void){

 Text *text = textNew("12+34,F,3");

 String *string = stringNew(text);



 char *stringMock = "12+34";

 int test;



 evaluate_CMockExpectAndReturn(195, stringMock, 46);

 test = extractValue(string);

 UnityAssertEqualNumber((_U_SINT)((46)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)197, UNITY_DISPLAY_STYLE_INT);



 test = extractDestination(string);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)200, UNITY_DISPLAY_STYLE_INT);



 stringMock = "3";

 evaluate_CMockExpectAndReturn(203, stringMock, 3);

 test = extractAccessBanked(string);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)205, UNITY_DISPLAY_STYLE_INT);

}



void test_extractAccessBanked_should_throw_error_with_empty_argument(void){

 Text *text = textNew(" 123, F,     ; ");

 String *string = stringNew(text);



 char *stringMock = "123";

 int test,e;



 evaluate_CMockExpectAndReturn(215, stringMock, 123);

 test = extractValue(string);

 UnityAssertEqualNumber((_U_SINT)((123)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)217, UNITY_DISPLAY_STYLE_INT);



 stringMock = "F";

 test = extractDestination(string);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)221, UNITY_DISPLAY_STYLE_INT);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  test = extractAccessBanked(string);

 }

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_EMPTY_ARGUMENT)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)227, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_extractAccessBanked_should_throw_error_with_empty_argument_semicolon(void){

 Text *text = textNew("123,  F   ;");

 String *string = stringNew(text);



 char *stringMock = "123";

 int test,e;



 evaluate_CMockExpectAndReturn(238, stringMock, 123);

 test = extractValue(string);

 UnityAssertEqualNumber((_U_SINT)((123)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)240, UNITY_DISPLAY_STYLE_INT);



 stringMock = "F";

 test = extractDestination(string);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)244, UNITY_DISPLAY_STYLE_INT);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  test = extractAccessBanked(string);

 }

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_NO_ARGUMENT)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)250, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_extractAccessBaked_should_get_value_from_ACCESS(void){

 Text *text = textNew("1+2,  F   ,ACCESS");

 String *string = stringNew(text);



 char *stringMock = "1+2";

 int test,e;



 evaluate_CMockExpectAndReturn(261, stringMock, 3);

 test = extractValue(string);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)263, UNITY_DISPLAY_STYLE_INT);



 stringMock = "F";

 test = extractDestination(string);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)267, UNITY_DISPLAY_STYLE_INT);



 stringMock = "ACCESS";

 test = extractAccessBanked(string);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)271, UNITY_DISPLAY_STYLE_INT);



}



void test_extractAccessBanked_should_get_value_from_evaluate(void){

 Text *text = textNew("   123   , 1    ,1+2");

 String *string = stringNew(text);



 char *stringMock = "123";

 int test,e;



 evaluate_CMockExpectAndReturn(282, stringMock, 123);

 test = extractValue(string);

 UnityAssertEqualNumber((_U_SINT)((123)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)284, UNITY_DISPLAY_STYLE_INT);



 stringMock = "1";

 evaluate_CMockExpectAndReturn(287, stringMock, 1);

 test = extractDestination(string);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)289, UNITY_DISPLAY_STYLE_INT);



 stringMock = "1+2";

 evaluate_CMockExpectAndReturn(292, stringMock, 3);

 test = extractAccessBanked(string);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)294, UNITY_DISPLAY_STYLE_INT);



}



  void test_extractValue_should_able_to_throw_NO_ARGUMENT_for_both(void){

 Text *text = textNew("123   ");

 String *string = stringNew(text);



 char *stringMock = "123";

 int test,e;



 evaluate_CMockExpectAndReturn(305, stringMock, 123);

 test = extractValue(string);

 UnityAssertEqualNumber((_U_SINT)((123)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)307, UNITY_DISPLAY_STYLE_INT);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  test = extractDestination(string);}

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_NO_ARGUMENT)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)312, UNITY_DISPLAY_STYLE_INT);

 }



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  test = extractAccessBanked(string);}

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_NO_ARGUMENT)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)318, UNITY_DISPLAY_STYLE_INT);

 }

}



 void test_extractValue_should_able_to_throw_EMPTY_ARGUMENT(void){

 Text *text = textNew("123,   , ");

 String *string = stringNew(text);



 char *stringMock = "123";

 int test,e;



 evaluate_CMockExpectAndReturn(329, stringMock, 123);

 test = extractValue(string);

 UnityAssertEqualNumber((_U_SINT)((123)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)331, UNITY_DISPLAY_STYLE_INT);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  test = extractDestination(string);}

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_EMPTY_ARGUMENT)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)336, UNITY_DISPLAY_STYLE_INT);

 }



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  test = extractAccessBanked(string);}

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_EMPTY_ARGUMENT)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)342, UNITY_DISPLAY_STYLE_INT);

 }

}



 void test_extractValue_should_able_to_throw_NO_ARGUMENT(void){

 Text *text = textNew("123,    ");

 String *string = stringNew(text);



 char *stringMock = "123";

 int test,e;



 evaluate_CMockExpectAndReturn(353, stringMock, 123);

 test = extractValue(string);

 UnityAssertEqualNumber((_U_SINT)((123)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)355, UNITY_DISPLAY_STYLE_INT);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  test = extractDestination(string);}

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_EMPTY_ARGUMENT)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)360, UNITY_DISPLAY_STYLE_INT);

 }



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  test = extractAccessBanked(string);}

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_NO_ARGUMENT)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)366, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_getInstruction_should_get_opCode_RLNCF(){



 instructionTable test;



 test = getInstruction("RLNCF");

 UnityAssertEqualNumber((_U_SINT)(_US16)((0x4400)), (_U_SINT)(_US16)((test.opCode)), (((void *)0)), (_U_UINT)375, UNITY_DISPLAY_STYLE_HEX16);

 UnityAssertEqualNumber((_U_SINT)((FDA_TYPE)), (_U_SINT)((test.type)), (((void *)0)), (_U_UINT)376, UNITY_DISPLAY_STYLE_INT);

}



void test_getInstruction_should_get_opCode_RETLW(){



 instructionTable test;



 test = getInstruction("RETLW");

 UnityAssertEqualNumber((_U_SINT)(_US16)((0x0C00)), (_U_SINT)(_US16)((test.opCode)), (((void *)0)), (_U_UINT)384, UNITY_DISPLAY_STYLE_HEX16);

 UnityAssertEqualNumber((_U_SINT)((K_TYPE)), (_U_SINT)((test.type)), (((void *)0)), (_U_UINT)385, UNITY_DISPLAY_STYLE_INT);

}



void test_interpret_should_able_to_get_correct_value(){

 Text *text = textNew(" ADDWF  0x20, F, BANKED");

 String *string = stringNew(text);



 FDA_CMockExpectAndReturn(392, string, 0x320);

 int test = interpret(string);



 UnityAssertEqualNumber((_U_SINT)((0x2720)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)395, UNITY_DISPLAY_STYLE_INT);



}



void test_interpret_should_throw_an_error_for_unexist_instruction(){

 Text *text = textNew(" SUBWFWFWF  0x20, F, BANKED");

 String *string = stringNew(text);

 int e;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  int test = interpret(string);}

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_ILLEGAL_ARGUMENT)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)407, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_interpret_should_throw_an_error_for_invalid_input_instruction(){

 Text *text = textNew(" SUBWF  0x20, HAHA, BANKED");

 String *string = stringNew(text);

 int e;



 FDA_CMockExpectAndThrow(416, string, ERR_ILLEGAL_ARGUMENT);

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  int test = interpret(string);}

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_ILLEGAL_ARGUMENT)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)420, UNITY_DISPLAY_STYLE_INT);

 }

}
