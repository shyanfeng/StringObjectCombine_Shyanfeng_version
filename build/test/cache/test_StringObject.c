#include "unity.h"
#include "StringObject.h"
#include "String.h"
#include "CustomTypeAssert.h"


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

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((compare)), (((void *)0)), (_U_UINT)90, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((text->reference)), (((void *)0)), (_U_UINT)91, UNITY_DISPLAY_STYLE_INT);

}



void test_textNew_should_create_static_text_properly(void){

 int compare;

 Text *text = (Text *)"\x00\x00\x00\x80""JoonPon";

 compare = strcmp(text->string,"JoonPon");

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((compare)), (((void *)0)), (_U_UINT)98, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(_US32)((0x80000000)), (_U_SINT)(_US32)((text->reference)), (((void *)0)), (_U_UINT)99, UNITY_DISPLAY_STYLE_HEX32);

}



void test_textAssign_should_increase_reference(void){

 int compare;

 Text *text = textNew("LheeCiang");

 Text *text2 = textAssign(text);



 compare = strcmp(text->string,text2->string);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((text->reference)), (((void *)0)), (_U_UINT)108, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((compare)), (((void *)0)), (_U_UINT)109, UNITY_DISPLAY_STYLE_INT);

}



void test_textAssign_should_not_increase_reference(void){

 int compare;

 Text *text = (Text *)"\x00\x00\x00\x80""XingBuan";

 Text *text2 = textAssign(text);



 compare = strcmp(text->string,text2->string);

 UnityAssertEqualNumber((_U_SINT)(_US32)((0x80000000)), (_U_SINT)(_US32)((text->reference)), (((void *)0)), (_U_UINT)118, UNITY_DISPLAY_STYLE_HEX32);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((compare)), (((void *)0)), (_U_UINT)119, UNITY_DISPLAY_STYLE_INT);

}



void test_textDel_should_delete_dynamic_text(void){

 Text *toCompare;

 Text *text = textNew("YhoonCung");

 toCompare = textDel(text);



 UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)127, UNITY_DISPLAY_STYLE_INT);

}



void test_textDel_should_not_delete_static_text(void){

 Text *toCompare;

 Text *text = (Text *)"\x00\x00\x00\x80""WingJen";

 toCompare = textDel(text);



 UnityAssertEqualNumber((_U_SINT)((text)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)135, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(_US32)((0x80000000)), (_U_SINT)(_US32)((toCompare->reference)), (((void *)0)), (_U_UINT)136, UNITY_DISPLAY_STYLE_HEX32);

}



void test_textDel_should_not_delete_when_reference_not_0(void){

 Text *toCompare;

 Text *text = textNew("FhyanSeng");

 Text *text1 = textAssign(text);

 toCompare = textDel(text);



 UnityAssertEqualNumber((_U_SINT)((text)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)145, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((text1)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)146, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((toCompare->reference)), (((void *)0)), (_U_UINT)147, UNITY_DISPLAY_STYLE_INT);

}



void test_textDel_should_not_delete_and_reduce_reference(void){

 Text *toCompare;

 Text *text = (Text *)"\x00\x00\x00\x80""FhyanSeng";

 Text *text1 = textAssign(text);

 toCompare = textDel(text);



 UnityAssertEqualNumber((_U_SINT)((text)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)156, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((text1)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)157, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x80000000)), (_U_SINT)((toCompare->reference)), (((void *)0)), (_U_UINT)158, UNITY_DISPLAY_STYLE_INT);

}



void test_stringNew_should_create_string_with_dynamic_text(void){

 int toCompare;

 Text *text = textNew("FhyanSeng");

 String *str = stringNew(text);



 toCompare = strcmp(str->text->string,text->string);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)167, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((str->reference)), (((void *)0)), (_U_UINT)168, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)169, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((9)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)170, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((str->text->reference)), (((void *)0)), (_U_UINT)171, UNITY_DISPLAY_STYLE_INT);

}



void test_stringNew_should_create_string_with_static_text(void){

 int toCompare;

 Text *text = (Text *)"\x00\x00\x00\x80""DreFick";

 String *str = stringNew(text);

 toCompare = strcmp(str->text->string,text->string);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)179, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((str->reference)), (((void *)0)), (_U_UINT)180, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)181, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)182, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(_US32)((0x80000000)), (_U_SINT)(_US32)((str->text->reference)), (((void *)0)), (_U_UINT)183, UNITY_DISPLAY_STYLE_HEX32);

}



void test_stringAssign_should_increase_reference(void){

 Text *text = textNew("JaNib");

 String *str = stringNew(text);

 String *str1 = stringAssign(str);

 String *str2 = stringAssign(str);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((str->reference)), (((void *)0)), (_U_UINT)191, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((str->text->reference)), (((void *)0)), (_U_UINT)192, UNITY_DISPLAY_STYLE_INT);

}



void test_stringDel_should_delete_and_reduce_text_reference(void){

 String *toCompare;

 Text *text = textNew("MosRah");

 String *str = stringNew(text);

 String *str1 = stringAssign(str);

 String *str2 = stringAssign(str);

 toCompare = stringDel(str);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((toCompare->reference)), (((void *)0)), (_U_UINT)202, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((str->text->reference)), (((void *)0)), (_U_UINT)203, UNITY_DISPLAY_STYLE_INT);

}



void test_stringDel_should_delete_and_not_reduce_text_reference(void){

 String *toCompare;

 Text *text = (Text *)"\x00\x00\x00\x80""SelNon";

 String *str = stringNew(text);

 String *str1 = stringAssign(str);

 String *str2 = stringAssign(str);

 toCompare = stringDel(str);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((toCompare->reference)), (((void *)0)), (_U_UINT)213, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(_US32)((0x80000000)), (_U_SINT)(_US32)((str->text->reference)), (((void *)0)), (_U_UINT)214, UNITY_DISPLAY_STYLE_HEX32);

}



void test_stringSkip_should_skip(void){

 Text *text = textNew("SelNon");

 String *str = stringNew(text);

 stringSkip(str,2);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)221, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)222, UNITY_DISPLAY_STYLE_INT);

}



void test_stringSkip_should_overload_and_stop_at_Null(void){

 Text *text = textNew("SelNonDan");

 String *str = stringNew(text);

 str->start++;

 stringSkip(str,100);

 UnityAssertEqualNumber((_U_SINT)((9)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)230, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)231, UNITY_DISPLAY_STYLE_INT);

}

void test_stringTrimLeft(void){

 Text *text = textNew("SaJon ");

 String *str = stringNew(text);

 stringTrimLeft(str);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)237, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)238, UNITY_DISPLAY_STYLE_INT);

}



void test_stringTrimLeft2(void){

 Text *text = textNew("    HohnJon ");

 String *str = stringNew(text);

 str->start+=3;

 stringTrimLeft(str);

 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)246, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((8)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)247, UNITY_DISPLAY_STYLE_INT);

}



void test_stringTrimRight(void){

 Text *text = textNew("    LuJian  ");

 String *str = stringNew(text);

 stringTrimRight(str);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)254, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((10)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)255, UNITY_DISPLAY_STYLE_INT);

}



void test_stringTrimRight2(void){

 Text *text = textNew("   DeeFer\t");

 String *str = stringNew(text);

 stringTrimRight(str);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)262, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((9)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)263, UNITY_DISPLAY_STYLE_INT);

}



void test_stringTrim_should_trim_both_sides(void){

 Text *text = textNew("  \t \t \t  VeaLer     ");

 String *str = stringNew(text);

 stringTrim(str);

 UnityAssertEqualNumber((_U_SINT)((9)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)270, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)271, UNITY_DISPLAY_STYLE_INT);

}



void test_stringTrim_should_trim_both_sides2(void){

 Text *text = textNew("  GaLger \t\t    ");

 String *str = stringNew(text);

 stringTrim(str);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)278, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)279, UNITY_DISPLAY_STYLE_INT);

}



void test_stringTrim_should_trim_both_sides3(void){

 Text *text = textNew(" \t\t BeedFack \t\t    ");

 String *str = stringNew(text);

 stringTrim(str);

 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)286, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((8)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)287, UNITY_DISPLAY_STYLE_INT);

}



void test_all(void){

 String *toCompare;

 Text *text = textNew(" \t\t ahaha \t\t    ");



 String *str = stringNew(text);

 String *str2 = stringAssign(str);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((text->reference)), (((void *)0)), (_U_UINT)296, UNITY_DISPLAY_STYLE_INT);



 toCompare = stringDel(str);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((text->reference)), (((void *)0)), (_U_UINT)299, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((toCompare->reference)), (((void *)0)), (_U_UINT)300, UNITY_DISPLAY_STYLE_INT);



 toCompare = stringDel(str);



 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((text->reference)), (((void *)0)), (_U_UINT)304, UNITY_DISPLAY_STYLE_INT);



 stringTrim(str);

 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)307, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)308, UNITY_DISPLAY_STYLE_INT);

}



void test_stringRemoveChar_should_remove_w(void){

 char toCompare;

 Text *text = textNew("wahaha");

 String *str = stringNew(text);



 toCompare = stringRemoveChar(str);

 UnityAssertEqualNumber((_U_SINT)(('w')), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)317, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)318, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)319, UNITY_DISPLAY_STYLE_INT);

}



void test_stringRemoveChar_should_remove_spacing(void){

 char toCompare;

 Text *text = textNew("   iana");

 String *str = stringNew(text);



 toCompare = stringRemoveChar(str);

 UnityAssertEqualNumber((_U_SINT)((' ')), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)328, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)329, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)330, UNITY_DISPLAY_STYLE_INT);

}



void test_stringRemoveChar_should_return_negative_one_after_deletion(void){

 char toCompare;

 Text *text = textNew("a");

 String *str = stringNew(text);



 toCompare = stringRemoveChar(str);

 UnityAssertEqualNumber((_U_SINT)((-1)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)339, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)340, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)341, UNITY_DISPLAY_STYLE_INT);

}



void test_stringRemoveChar_should_return_negative_one_with_NULL_input(void){

 char toCompare;

 Text *text = textNew("");

 String *str = stringNew(text);



 toCompare = stringRemoveChar(str);

 UnityAssertEqualNumber((_U_SINT)((-1)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)350, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)351, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)352, UNITY_DISPLAY_STYLE_INT);

}



void test_stringLength_should_get_6(void){

 int toCompareLength;

 Text *text = textNew("abcdefg");

 String *str = stringNew(text);



 toCompareLength = stringLength(str);

 UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((toCompareLength)), (((void *)0)), (_U_UINT)361, UNITY_DISPLAY_STYLE_INT);

}



void test_stringLength_should_get_16(void){

 int toCompareLength;

 Text *text = textNew(" \t \t \t 16 length");

 String *str = stringNew(text);



 toCompareLength = stringLength(str);

 UnityAssertEqualNumber((_U_SINT)((16)), (_U_SINT)((toCompareLength)), (((void *)0)), (_U_UINT)370, UNITY_DISPLAY_STYLE_INT);

}



void test_stringRemoveWordNotContaining_remove_abcd(void){

 int toCompare;

 Text *text = textNew("abcdefghi");

 String *str = stringNew(text);

 String *test = stringRemoveWordNotContaining(str,"ei");



 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)379, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)380, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((test->start)), (((void *)0)), (_U_UINT)381, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((test->length)), (((void *)0)), (_U_UINT)382, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((text->reference)), (((void *)0)), (_U_UINT)383, UNITY_DISPLAY_STYLE_INT);

}

void test_stringRemoveWordNotContaining_remove_abcd_static(void){

 int toCompare;

 Text *text = (Text *)"\x00\x00\x00\x80""abcdefghi";

 String *str = stringNew(text);

 String *test = stringRemoveWordNotContaining(str,"ei");



 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)391, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)392, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((test->start)), (((void *)0)), (_U_UINT)393, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((test->length)), (((void *)0)), (_U_UINT)394, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x80000000)), (_U_SINT)((text->reference)), (((void *)0)), (_U_UINT)395, UNITY_DISPLAY_STYLE_INT);

}



void test_stringRemoveWordNotContaining_remove_ww(void){

 int toCompare;

 Text *text = textNew("wwabcdefghi");

 String *str = stringNew(text);

 str->start++;

 str->length--;

 String *test = stringRemoveWordNotContaining(str,"ab");



 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)406, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((9)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)407, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((test->start)), (((void *)0)), (_U_UINT)408, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((test->length)), (((void *)0)), (_U_UINT)409, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((text->reference)), (((void *)0)), (_U_UINT)410, UNITY_DISPLAY_STYLE_INT);

}



void test_stringRemoveWordNotContaining_remove_ww_static(void){

 int toCompare;

 Text *text = (Text *)"\x00\x00\x00\x80""wwabcdefghi";

 String *str = stringNew(text);

 str->start++;

 str->length--;

 String *test = stringRemoveWordNotContaining(str,"ab");



 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)421, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((9)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)422, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((test->start)), (((void *)0)), (_U_UINT)423, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((test->length)), (((void *)0)), (_U_UINT)424, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x80000000)), (_U_SINT)((text->reference)), (((void *)0)), (_U_UINT)425, UNITY_DISPLAY_STYLE_INT);

}



void test_stringRemoveWordNotContaining_remove_nothing(void){

 int toCompare;

 Text *text = textNew("abcdefghi");

 String *str = stringNew(text);

 String *test = stringRemoveWordNotContaining(str,"ab");



 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)434, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((9)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)435, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((test->start)), (((void *)0)), (_U_UINT)436, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((test->length)), (((void *)0)), (_U_UINT)437, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((text->reference)), (((void *)0)), (_U_UINT)438, UNITY_DISPLAY_STYLE_INT);

}



void test_stringRemoveWordContaining_remove_ab(void){

 int toCompare;

 Text *text = textNew("abcdefghi");

 String *str = stringNew(text);

 String *test = stringRemoveWordContaining(str,"ab");



 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)447, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)448, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((test->start)), (((void *)0)), (_U_UINT)449, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((test->length)), (((void *)0)), (_U_UINT)450, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((text->reference)), (((void *)0)), (_U_UINT)451, UNITY_DISPLAY_STYLE_INT);

}



void test_stringRemoveWordContaining_remove_ab_static(void){

 int toCompare;

 Text *text = (Text *)"\x00\x00\x00\x80""abcdefghi";

 String *str = stringNew(text);

 String *test = stringRemoveWordContaining(str,"ab");



 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)460, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)461, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((test->start)), (((void *)0)), (_U_UINT)462, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((test->length)), (((void *)0)), (_U_UINT)463, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x80000000)), (_U_SINT)((text->reference)), (((void *)0)), (_U_UINT)464, UNITY_DISPLAY_STYLE_INT);

}



void test_stringRemoveWordContaining_remove_abc(void){

 int toCompare;

 Text *text = textNew("abcdefghi");

 String *str = stringNew(text);

 String *test = stringRemoveWordContaining(str,"aaaaaaacb");



 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)473, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)474, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((test->start)), (((void *)0)), (_U_UINT)475, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((test->length)), (((void *)0)), (_U_UINT)476, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((text->reference)), (((void *)0)), (_U_UINT)477, UNITY_DISPLAY_STYLE_INT);

}



void test_stringRemoveWordContaining_remove_abc_static(void){

 int toCompare;

 Text *text = (Text *)"\x00\x00\x00\x80""abcdefghi";

 String *str = stringNew(text);

 String *test = stringRemoveWordContaining(str,"aaaaaaacb");



 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)486, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)487, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((test->start)), (((void *)0)), (_U_UINT)488, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((test->length)), (((void *)0)), (_U_UINT)489, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x80000000)), (_U_SINT)((text->reference)), (((void *)0)), (_U_UINT)490, UNITY_DISPLAY_STYLE_INT);

}



void test_stringRemoveWordContaining_remove_nothing(void){

 int toCompare;

 Text *text = textNew("1234abcdefghi");

 String *str = stringNew(text);

 String *test = stringRemoveWordContaining(str,"ab");



 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)499, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((13)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)500, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((test->start)), (((void *)0)), (_U_UINT)501, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((test->length)), (((void *)0)), (_U_UINT)502, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((text->reference)), (((void *)0)), (_U_UINT)503, UNITY_DISPLAY_STYLE_INT);

}



void test_stringIsEqual_should_return_equal(void){

 int toCompare;

 Text *text = textNew("abc");

 String *str = stringNew(text);

 Text *text1 = textNew("aabc");

 String *str1 = stringNew(text1);

 str1->start++;

 str1->length--;



 toCompare = stringIsEqual(str,str1);



 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)517, UNITY_DISPLAY_STYLE_INT);

}



void test_stringIsEqual_should_return_equal_static(void){

 int toCompare;

 Text *text = (Text *)"\x00\x00\x00\x80""abc";

 String *str = stringNew(text);

 Text *text1 = (Text *)"\x00\x00\x00\x80""aabc";

 String *str1 = stringNew(text1);

 str1->start++;

 str1->length--;



 toCompare = stringIsEqual(str,str1);



 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)531, UNITY_DISPLAY_STYLE_INT);

}



void test_stringIsEqual_should_return_not_equal(void){

 int toCompare;

 Text *text = textNew("aBc");

 String *str = stringNew(text);

 Text *text1 = textNew("aabc");

 String *str1 = stringNew(text1);

 str1->start++;

 str1->length--;



 toCompare = stringIsEqual(str,str1);



 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)545, UNITY_DISPLAY_STYLE_INT);

}



void test_stringIsEqual_should_return_not_equal_static(void){

 int toCompare;

 Text *text = (Text *)"\x00\x00\x00\x80""aBc";

 String *str = stringNew(text);

 Text *text1 = (Text *)"\x00\x00\x00\x80""aabc";

 String *str1 = stringNew(text1);

 str1->start++;

 str1->length--;



 toCompare = stringIsEqual(str,str1);



 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)559, UNITY_DISPLAY_STYLE_INT);

}



void test_stringIsEqualCaseInsensitive_should_equal(void){

 int toCompare;

 Text *text = textNew("ChiCkenNuGGer");

 String *str = stringNew(text);

 Text *text1 = textNew("chickennugger");

 String *str1 = stringNew(text1);



 toCompare = stringIsEqualCaseInsensitive(str,str1);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)570, UNITY_DISPLAY_STYLE_INT);

}



void test_stringIsEqualCaseInsensitive_should_equal_with_different_start(void){

 int toCompare;

 Text *text = textNew("ChiCkenNuGGer");

 String *str = stringNew(text);

 Text *text1 = textNew("hahachickennugger");

 String *str1 = stringNew(text1);

 str1->start+=4;

 str1->length-=4;



 toCompare = stringIsEqualCaseInsensitive(str,str1);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)583, UNITY_DISPLAY_STYLE_INT);

}



void test_stringIsEqualCaseInsensitive_should_not_equal(void){

 int toCompare;

 Text *text = textNew("burger");

 String *str = stringNew(text);

 Text *text1 = textNew("king");

 String *str1 = stringNew(text1);



 toCompare = stringIsEqualCaseInsensitive(str,str1);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)594, UNITY_DISPLAY_STYLE_INT);

}



void test_stringIsEqualCaseInsensitive_should_equal_static(){



 Text *name1 = (Text *)"\x00\x00\x00\x80""pineApPle";

 Text *name2 = (Text *)"\x00\x00\x00\x80""aPPlE";

 String *string1 = stringNew(name1);

 string1->start = 4;

 string1->length = 5;

 String *string2 = stringNew(name2);



 stringIsEqualCaseInsensitive(string1,string2);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((stringIsEqualCaseInsensitive(string1,string2))), (((void *)0)), (_U_UINT)607, UNITY_DISPLAY_STYLE_INT);

}



void test_extra_to_solve_problem_1(void){



 Text *name = (Text *)"\x00\x00\x00\x80""Bulldog";

 String *string1 = stringNew(name);

 String *string2 = stringRemoveWordNotContaining(string1, "gd");



 assertStringEqual(("dog"), (string1), 616, ((void *)0));

 assertStringEqual(("Bull"), (string2), 617, ((void *)0));

}



void test_extra_to_solve_problem_2(){



 Text *name = (Text *)"\x00\x00\x00\x80""BaskinRobbin";

 String *string1 = stringNew(name);

 string1->start++;

 string1->length--;

 String *string2 = stringRemoveWordNotContaining(string1, "onb");



 assertStringEqual(("nRobbin"), (string1), 628, ((void *)0));

 assertStringEqual(("aski"), (string2), 629, ((void *)0));

}



void test_extra_to_solve_problem_3(){



 Text *name1 = textNew("pineApPle");

 Text *name2 = textNew("aPPlE");

 String *string1 = stringNew(name1);

 string1->start = 4;

 string1->length = 5;

 String *string2 = stringNew(name2);



 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((stringIsEqualCaseInsensitive(string1,string2))), (((void *)0)), (_U_UINT)641, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((stringIsEqualCaseInsensitive(string2,string1))), (((void *)0)), (_U_UINT)642, UNITY_DISPLAY_STYLE_INT);

 stringDel(string1);

 stringDel(string2);

}
