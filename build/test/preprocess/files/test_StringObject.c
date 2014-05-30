#include "unity.h"
#include "stringObject.h"
#include "String.h"


typedef struct FakeText {

 uint32 reference;

 char string[80];

} FakeText;



void setUp(){}

void tearDown(){}





void test_textNew_should_create_dynamic_text_properly(void){

 int compare;

 Text *text = textNew("FooSatt");



 compare = strcmp(text->string,"FooSatt");

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((compare)), (((void *)0)), (_U_UINT)19, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((text->reference)), (((void *)0)), (_U_UINT)20, UNITY_DISPLAY_STYLE_INT);

}



void test_textNew_should_create_static_text_properly(void){

 int compare;

 Text *text = (Text *)"\x00\x00\x00\x80""JoonPon";



 compare = strcmp(text->string,"JoonPon");

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((compare)), (((void *)0)), (_U_UINT)28, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(_US32)((0x80000000)), (_U_SINT)(_US32)((text->reference)), (((void *)0)), (_U_UINT)29, UNITY_DISPLAY_STYLE_HEX32);

}



void test_textAssign_should_increase_reference(void){

 int compare;

 Text *text = textNew("LheeCiang");

 Text *text2 = textAssign(text);



 compare = strcmp(text->string,text2->string);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((text->reference)), (((void *)0)), (_U_UINT)38, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((compare)), (((void *)0)), (_U_UINT)39, UNITY_DISPLAY_STYLE_INT);

}



void test_textAssign_should_not_increase_reference(void){

 int compare;

 Text *text = (Text *)"\x00\x00\x00\x80""XingBuan";

 Text *text2 = textAssign(text);



 compare = strcmp(text->string,text2->string);

 UnityAssertEqualNumber((_U_SINT)(_US32)((0x80000000)), (_U_SINT)(_US32)((text->reference)), (((void *)0)), (_U_UINT)48, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((compare)), (((void *)0)), (_U_UINT)49, UNITY_DISPLAY_STYLE_INT);

}



void test_textDel_should_delete_dynamic_text(void){

 Text *toCompare;

 Text *text = textNew("YhoonCung");

 toCompare = textDel(text);



 UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)57, UNITY_DISPLAY_STYLE_INT);

}



void test_textDel_should_not_delete_static_text(void){

 Text *toCompare;

 Text *text = (Text *)"\x00\x00\x00\x80""WingJen";

 toCompare = textDel(text);



 UnityAssertEqualNumber((_U_SINT)((text)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)65, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(_US32)((0x80000000)), (_U_SINT)(_US32)((toCompare->reference)), (((void *)0)), (_U_UINT)66, UNITY_DISPLAY_STYLE_HEX32);

}



void test_textDel_should_not_delete_when_reference_not_0(void){

 Text *toCompare;

 Text *text = textNew("FhyanSeng");

 Text *text1 = textAssign(text);

 toCompare = textDel(text);



 UnityAssertEqualNumber((_U_SINT)((text)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)75, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((text1)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)76, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((toCompare->reference)), (((void *)0)), (_U_UINT)77, UNITY_DISPLAY_STYLE_INT);

}



void test_textDel_should_not_delete_and_reduce_reference(void){

 Text *toCompare;

 Text *text = (Text *)"\x00\x00\x00\x80""FhyanSeng";

 Text *text1 = textAssign(text);

 toCompare = textDel(text);



 UnityAssertEqualNumber((_U_SINT)((text)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)86, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((text1)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)87, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x80000000)), (_U_SINT)((toCompare->reference)), (((void *)0)), (_U_UINT)88, UNITY_DISPLAY_STYLE_INT);

}



void test_stringNew_should_create_string_with_dynamic_text(void){

 int toCompare;

 Text *text = textNew("FhyanSeng");

 String *str = stringNew(text);



 toCompare = strcmp(str->text->string,text->string);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)97, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((str->reference)), (((void *)0)), (_U_UINT)98, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)99, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((9)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)100, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((str->text->reference)), (((void *)0)), (_U_UINT)101, UNITY_DISPLAY_STYLE_INT);

}



void test_stringNew_should_create_string_with_static_text(void){

 int toCompare;

 Text *text = (Text *)"\x00\x00\x00\x80""DreFick";

 String *str = stringNew(text);

 toCompare = strcmp(str->text->string,text->string);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)109, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((str->reference)), (((void *)0)), (_U_UINT)110, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)111, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)112, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(_US32)((0x80000000)), (_U_SINT)(_US32)((str->text->reference)), (((void *)0)), (_U_UINT)113, UNITY_DISPLAY_STYLE_HEX32);

}



void test_stringAssign_should_increase_reference(void){

 Text *text = textNew("JaNib");

 String *str = stringNew(text);

 String *str1 = stringAssign(str);

 String *str2 = stringAssign(str);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((str->reference)), (((void *)0)), (_U_UINT)121, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((str->text->reference)), (((void *)0)), (_U_UINT)122, UNITY_DISPLAY_STYLE_INT);

}



void test_stringDel_should_delete_and_reduce_text_reference(void){

 String *toCompare;

 Text *text = textNew("MosRah");

 String *str = stringNew(text);

 String *str1 = stringAssign(str);

 String *str2 = stringAssign(str);

 toCompare = stringDel(str);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((toCompare->reference)), (((void *)0)), (_U_UINT)132, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((str->text->reference)), (((void *)0)), (_U_UINT)133, UNITY_DISPLAY_STYLE_INT);

}



void test_stringDel_should_delete_and_not_reduce_text_reference(void){

 String *toCompare;

 Text *text = (Text *)"\x00\x00\x00\x80""SelNon";

 String *str = stringNew(text);

 String *str1 = stringAssign(str);

 String *str2 = stringAssign(str);

 toCompare = stringDel(str);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((toCompare->reference)), (((void *)0)), (_U_UINT)143, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(_US32)((0x80000000)), (_U_SINT)(_US32)((str->text->reference)), (((void *)0)), (_U_UINT)144, UNITY_DISPLAY_STYLE_HEX32);

}



void test_stringSkip_should_skip(void){

 Text *text = textNew("SelNon");

 String *str = stringNew(text);

 stringSkip(str,2);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)151, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)152, UNITY_DISPLAY_STYLE_INT);

}



void test_stringSkip_should_overload_and_stop_at_Null(void){

 Text *text = textNew("SelNonDan");

 String *str = stringNew(text);

 str->start++;

 stringSkip(str,10);

 UnityAssertEqualNumber((_U_SINT)((9)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)160, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)161, UNITY_DISPLAY_STYLE_INT);

}



void test_stringTrimLeft(void){

 Text *text = textNew("    a ");

 String *str = stringNew(text);

 stringTrimLeft(str);



 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)169, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)170, UNITY_DISPLAY_STYLE_INT);

}



void test_stringTrimLeftaf(void){

 Text *text = textNew("    a ");

 String *str = stringNew(text);

 str->start+=3;

 stringTrimLeft(str);



 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)179, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)180, UNITY_DISPLAY_STYLE_INT);

}
