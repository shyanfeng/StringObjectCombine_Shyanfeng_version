#include "unity.h"
#include "Text.h"


void setUp(void){}

void tearDown(void){}





void test_textNew_should_create_dynamic_text_properly(void){

 int compare;

 Text *text = textNew("FooSatt");

 compare = strcmp(text->string,"FooSatt");

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((compare)), (((void *)0)), (_U_UINT)12, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((text->reference)), (((void *)0)), (_U_UINT)13, UNITY_DISPLAY_STYLE_INT);

}



void test_textNew_should_create_static_text_properly(void){

 int compare;

 Text *text = (Text *)"\x00\x00\x00\x80""JoonPon";

 compare = strcmp(text->string,"JoonPon");

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((compare)), (((void *)0)), (_U_UINT)20, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(_US32)((0x80000000)), (_U_SINT)(_US32)((text->reference)), (((void *)0)), (_U_UINT)21, UNITY_DISPLAY_STYLE_HEX32);

}



void test_textAssign_should_increase_reference(void){

 int compare;

 Text *text = textNew("LheeCiang");

 Text *text2 = textAssign(text);



 compare = strcmp(text->string,text2->string);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((text->reference)), (((void *)0)), (_U_UINT)30, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((compare)), (((void *)0)), (_U_UINT)31, UNITY_DISPLAY_STYLE_INT);

}



void test_textAssign_should_not_increase_reference(void){

 int compare;

 Text *text = (Text *)"\x00\x00\x00\x80""XingBuan";

 Text *text2 = textAssign(text);



 compare = strcmp(text->string,text2->string);

 UnityAssertEqualNumber((_U_SINT)(_US32)((0x80000000)), (_U_SINT)(_US32)((text->reference)), (((void *)0)), (_U_UINT)40, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((compare)), (((void *)0)), (_U_UINT)41, UNITY_DISPLAY_STYLE_INT);

}



void test_textDel_should_delete_dynamic_text(void){

 Text *toCompare;

 Text *text = textNew("YhoonCung");

 toCompare = textDel(text);



 UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)49, UNITY_DISPLAY_STYLE_INT);

}



void test_textDel_should_not_delete_static_text(void){

 Text *toCompare;

 Text *text = (Text *)"\x00\x00\x00\x80""WingJen";

 toCompare = textDel(text);



 UnityAssertEqualNumber((_U_SINT)((text)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)57, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(_US32)((0x80000000)), (_U_SINT)(_US32)((toCompare->reference)), (((void *)0)), (_U_UINT)58, UNITY_DISPLAY_STYLE_HEX32);

}



void test_textDel_should_not_delete_when_reference_not_0(void){

 Text *toCompare;

 Text *text = textNew("FhyanSeng");

 Text *text1 = textAssign(text);

 toCompare = textDel(text);



 UnityAssertEqualNumber((_U_SINT)((text)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)67, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((text1)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)68, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((toCompare->reference)), (((void *)0)), (_U_UINT)69, UNITY_DISPLAY_STYLE_INT);

}



void test_textDel_should_not_delete_and_reduce_reference(void){

 Text *toCompare;

 Text *text = (Text *)"\x00\x00\x00\x80""FhyanSeng";

 Text *text1 = textAssign(text);

 toCompare = textDel(text);



 UnityAssertEqualNumber((_U_SINT)((text)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)78, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((text1)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)79, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x80000000)), (_U_SINT)((toCompare->reference)), (((void *)0)), (_U_UINT)80, UNITY_DISPLAY_STYLE_INT);

}
