#include "unity.h"
#include "Text.h"
#include "StringObject.h"
#include "String.h"
#include "CustomTypeAssert.h"


typedef struct FakeText {

 uint32 reference;

 char string[80];

} FakeText;



void setUp(){}

void tearDown(){}

void test_stringNew_should_create_string_with_dynamic_text(void){

 int toCompare;

 Text *text = textNew("FhyanSeng");

 String *str = stringNew(text);



 toCompare = strcmp(str->text->string,text->string);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)94, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((str->reference)), (((void *)0)), (_U_UINT)95, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)96, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((9)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)97, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((str->text->reference)), (((void *)0)), (_U_UINT)98, UNITY_DISPLAY_STYLE_INT);

}



void test_stringNew_should_create_string_with_static_text(void){

 int toCompare;

 Text *text = (Text *)"\x00\x00\x00\x80""DreFick";

 String *str = stringNew(text);

 toCompare = strcmp(str->text->string,text->string);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)106, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((str->reference)), (((void *)0)), (_U_UINT)107, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)108, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)109, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(_US32)((0x80000000)), (_U_SINT)(_US32)((str->text->reference)), (((void *)0)), (_U_UINT)110, UNITY_DISPLAY_STYLE_HEX32);

}



void test_stringAssign_should_increase_reference(void){

 Text *text = textNew("JaNib");

 String *str = stringNew(text);

 String *str1 = stringAssign(str);

 String *str2 = stringAssign(str);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((str->reference)), (((void *)0)), (_U_UINT)118, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((str->text->reference)), (((void *)0)), (_U_UINT)119, UNITY_DISPLAY_STYLE_INT);

}



void test_stringDel_should_delete_and_reduce_text_reference(void){

 String *toCompare;

 Text *text = textNew("MosRah");

 String *str = stringNew(text);

 String *str1 = stringAssign(str);

 String *str2 = stringAssign(str);

 toCompare = stringDel(str);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((toCompare->reference)), (((void *)0)), (_U_UINT)129, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((str->text->reference)), (((void *)0)), (_U_UINT)130, UNITY_DISPLAY_STYLE_INT);

}



void test_stringDel_should_delete_and_not_reduce_text_reference(void){

 String *toCompare;

 Text *text = (Text *)"\x00\x00\x00\x80""SelNon";

 String *str = stringNew(text);

 String *str1 = stringAssign(str);

 String *str2 = stringAssign(str);

 toCompare = stringDel(str);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((toCompare->reference)), (((void *)0)), (_U_UINT)140, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)(_US32)((0x80000000)), (_U_SINT)(_US32)((str->text->reference)), (((void *)0)), (_U_UINT)141, UNITY_DISPLAY_STYLE_HEX32);

}



void test_stringSkip_should_skip(void){

 Text *text = textNew("SelNon");

 String *str = stringNew(text);

 stringSkip(str,2);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)148, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)149, UNITY_DISPLAY_STYLE_INT);

}



void test_stringSkip_should_overload_and_stop_at_Null(void){

 Text *text = textNew("SelNonDan");

 String *str = stringNew(text);

 str->start++;

 stringSkip(str,100);

 UnityAssertEqualNumber((_U_SINT)((9)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)157, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)158, UNITY_DISPLAY_STYLE_INT);

}

void test_stringTrimLeft(void){

 Text *text = textNew("SaJon ");

 String *str = stringNew(text);

 stringTrimLeft(str);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)164, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)165, UNITY_DISPLAY_STYLE_INT);

}



void test_stringTrimLeft2(void){

 Text *text = textNew("    HohnJon ");

 String *str = stringNew(text);

 str->start+=3;

 stringTrimLeft(str);

 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)173, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((8)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)174, UNITY_DISPLAY_STYLE_INT);

}



void test_stringTrimRight(void){

 Text *text = textNew("    LuJian  ");

 String *str = stringNew(text);

 stringTrimRight(str);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)181, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((10)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)182, UNITY_DISPLAY_STYLE_INT);

}



void test_stringTrimRight2(void){

 Text *text = textNew("   DeeFer\t");

 String *str = stringNew(text);

 stringTrimRight(str);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)189, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((9)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)190, UNITY_DISPLAY_STYLE_INT);

}



void test_stringTrim_should_trim_both_sides(void){

 Text *text = textNew("  \t \t \t  VeaLer     ");

 String *str = stringNew(text);

 stringTrim(str);

 UnityAssertEqualNumber((_U_SINT)((9)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)197, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)198, UNITY_DISPLAY_STYLE_INT);

}



void test_stringTrim_should_trim_both_sides2(void){

 Text *text = textNew("  GaLger \t\t    ");

 String *str = stringNew(text);

 stringTrim(str);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)205, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)206, UNITY_DISPLAY_STYLE_INT);

}



void test_stringTrim_should_trim_both_sides3(void){

 Text *text = textNew(" \t\t BeedFack \t\t    ");

 String *str = stringNew(text);

 stringTrim(str);

 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)213, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((8)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)214, UNITY_DISPLAY_STYLE_INT);

}



void test_all(void){

 String *toCompare;

 Text *text = textNew(" \t\t ahaha \t\t    ");



 String *str = stringNew(text);

 String *str2 = stringAssign(str);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((text->reference)), (((void *)0)), (_U_UINT)223, UNITY_DISPLAY_STYLE_INT);



 toCompare = stringDel(str);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((text->reference)), (((void *)0)), (_U_UINT)226, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((toCompare->reference)), (((void *)0)), (_U_UINT)227, UNITY_DISPLAY_STYLE_INT);



 toCompare = stringDel(str);



 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((text->reference)), (((void *)0)), (_U_UINT)231, UNITY_DISPLAY_STYLE_INT);



 stringTrim(str);

 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)234, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)235, UNITY_DISPLAY_STYLE_INT);

}



void test_stringRemoveChar_should_remove_w(void){

 char toCompare;

 Text *text = textNew("wahaha");

 String *str = stringNew(text);



 toCompare = stringRemoveChar(str);

 UnityAssertEqualNumber((_U_SINT)(('w')), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)244, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)245, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)246, UNITY_DISPLAY_STYLE_INT);

}



void test_stringRemoveChar_should_remove_spacing(void){

 char toCompare;

 Text *text = textNew("   iana");

 String *str = stringNew(text);



 toCompare = stringRemoveChar(str);

 UnityAssertEqualNumber((_U_SINT)((' ')), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)255, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)256, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)257, UNITY_DISPLAY_STYLE_INT);

}



void test_stringRemoveChar_should_return_negative_one_after_deletion(void){

 char toCompare;

 Text *text = textNew("a");

 String *str = stringNew(text);



 toCompare = stringRemoveChar(str);

 UnityAssertEqualNumber((_U_SINT)((-1)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)266, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)267, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)268, UNITY_DISPLAY_STYLE_INT);

}



void test_stringRemoveChar_should_return_negative_one_with_NULL_input(void){

 char toCompare;

 Text *text = textNew("");

 String *str = stringNew(text);



 toCompare = stringRemoveChar(str);

 UnityAssertEqualNumber((_U_SINT)((-1)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)277, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)278, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)279, UNITY_DISPLAY_STYLE_INT);

}



void test_stringLength_should_get_6(void){

 int toCompareLength;

 Text *text = textNew("abcdefg");

 String *str = stringNew(text);



 toCompareLength = stringLength(str);

 UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((toCompareLength)), (((void *)0)), (_U_UINT)288, UNITY_DISPLAY_STYLE_INT);

}



void test_stringLength_should_get_16(void){

 int toCompareLength;

 Text *text = textNew(" \t \t \t 16 length");

 String *str = stringNew(text);



 toCompareLength = stringLength(str);

 UnityAssertEqualNumber((_U_SINT)((16)), (_U_SINT)((toCompareLength)), (((void *)0)), (_U_UINT)297, UNITY_DISPLAY_STYLE_INT);

}



void test_stringRemoveWordNotContaining_remove_abcd(void){

 int toCompare;

 Text *text = textNew("abcdefghi");

 String *str = stringNew(text);

 String *test = stringRemoveWordNotContaining(str,"ei");



 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)306, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)307, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((test->start)), (((void *)0)), (_U_UINT)308, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((test->length)), (((void *)0)), (_U_UINT)309, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((text->reference)), (((void *)0)), (_U_UINT)310, UNITY_DISPLAY_STYLE_INT);

}

void test_stringRemoveWordNotContaining_remove_abcd_static(void){

 int toCompare;

 Text *text = (Text *)"\x00\x00\x00\x80""abcdefghi";

 String *str = stringNew(text);

 String *test = stringRemoveWordNotContaining(str,"ei");



 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)318, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)319, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((test->start)), (((void *)0)), (_U_UINT)320, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((test->length)), (((void *)0)), (_U_UINT)321, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x80000000)), (_U_SINT)((text->reference)), (((void *)0)), (_U_UINT)322, UNITY_DISPLAY_STYLE_INT);

}



void test_stringRemoveWordNotContaining_remove_ww(void){

 int toCompare;

 Text *text = textNew("wwabcdefghi");

 String *str = stringNew(text);

 str->start++;

 str->length--;

 String *test = stringRemoveWordNotContaining(str,"ab");



 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)333, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((9)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)334, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((test->start)), (((void *)0)), (_U_UINT)335, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((test->length)), (((void *)0)), (_U_UINT)336, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((text->reference)), (((void *)0)), (_U_UINT)337, UNITY_DISPLAY_STYLE_INT);

}



void test_stringRemoveWordNotContaining_remove_ww_static(void){

 int toCompare;

 Text *text = (Text *)"\x00\x00\x00\x80""wwabcdefghi";

 String *str = stringNew(text);

 str->start++;

 str->length--;

 String *test = stringRemoveWordNotContaining(str,"ab");



 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)348, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((9)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)349, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((test->start)), (((void *)0)), (_U_UINT)350, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((test->length)), (((void *)0)), (_U_UINT)351, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x80000000)), (_U_SINT)((text->reference)), (((void *)0)), (_U_UINT)352, UNITY_DISPLAY_STYLE_INT);

}



void test_stringRemoveWordNotContaining_remove_nothing(void){

 int toCompare;

 Text *text = textNew("abcdefghi");

 String *str = stringNew(text);

 String *test = stringRemoveWordNotContaining(str,"ab");



 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)361, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((9)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)362, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((test->start)), (((void *)0)), (_U_UINT)363, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((test->length)), (((void *)0)), (_U_UINT)364, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((text->reference)), (((void *)0)), (_U_UINT)365, UNITY_DISPLAY_STYLE_INT);

}



void test_stringRemoveWordContaining_remove_ab(void){

 int toCompare;

 Text *text = textNew("abcdefghi");

 String *str = stringNew(text);

 String *test = stringRemoveWordContaining(str,"ab");



 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)374, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)375, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((test->start)), (((void *)0)), (_U_UINT)376, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((test->length)), (((void *)0)), (_U_UINT)377, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((text->reference)), (((void *)0)), (_U_UINT)378, UNITY_DISPLAY_STYLE_INT);

}



void test_stringRemoveWordContaining_remove_ab_static(void){

 int toCompare;

 Text *text = (Text *)"\x00\x00\x00\x80""abcdefghi";

 String *str = stringNew(text);

 String *test = stringRemoveWordContaining(str,"ab");



 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)387, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)388, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((test->start)), (((void *)0)), (_U_UINT)389, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((test->length)), (((void *)0)), (_U_UINT)390, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x80000000)), (_U_SINT)((text->reference)), (((void *)0)), (_U_UINT)391, UNITY_DISPLAY_STYLE_INT);

}



void test_stringRemoveWordContaining_remove_abc(void){

 int toCompare;

 Text *text = textNew("abcdefghi");

 String *str = stringNew(text);

 String *test = stringRemoveWordContaining(str,"aaaaaaacb");



 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)400, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)401, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((test->start)), (((void *)0)), (_U_UINT)402, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((test->length)), (((void *)0)), (_U_UINT)403, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((text->reference)), (((void *)0)), (_U_UINT)404, UNITY_DISPLAY_STYLE_INT);

}



void test_stringRemoveWordContaining_remove_abc_static(void){

 int toCompare;

 Text *text = (Text *)"\x00\x00\x00\x80""abcdefghi";

 String *str = stringNew(text);

 String *test = stringRemoveWordContaining(str,"aaaaaaacb");



 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)413, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)414, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((test->start)), (((void *)0)), (_U_UINT)415, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((test->length)), (((void *)0)), (_U_UINT)416, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0x80000000)), (_U_SINT)((text->reference)), (((void *)0)), (_U_UINT)417, UNITY_DISPLAY_STYLE_INT);

}



void test_stringRemoveWordContaining_remove_nothing(void){

 int toCompare;

 Text *text = textNew("1234abcdefghi");

 String *str = stringNew(text);

 String *test = stringRemoveWordContaining(str,"ab");



 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str->start)), (((void *)0)), (_U_UINT)426, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((13)), (_U_SINT)((str->length)), (((void *)0)), (_U_UINT)427, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((test->start)), (((void *)0)), (_U_UINT)428, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((test->length)), (((void *)0)), (_U_UINT)429, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((text->reference)), (((void *)0)), (_U_UINT)430, UNITY_DISPLAY_STYLE_INT);

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



 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)444, UNITY_DISPLAY_STYLE_INT);

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



 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)458, UNITY_DISPLAY_STYLE_INT);

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



 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)472, UNITY_DISPLAY_STYLE_INT);

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



 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)486, UNITY_DISPLAY_STYLE_INT);

}



void test_stringIsEqualCaseInsensitive_should_equal(void){

 int toCompare;

 Text *text = textNew("ChiCkenNuGGer");

 String *str = stringNew(text);

 Text *text1 = textNew("chickennugger");

 String *str1 = stringNew(text1);



 toCompare = stringIsEqualCaseInsensitive(str,str1);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)497, UNITY_DISPLAY_STYLE_INT);

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

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)510, UNITY_DISPLAY_STYLE_INT);

}



void test_stringIsEqualCaseInsensitive_should_not_equal(void){

 int toCompare;

 Text *text = textNew("burger");

 String *str = stringNew(text);

 Text *text1 = textNew("king");

 String *str1 = stringNew(text1);



 toCompare = stringIsEqualCaseInsensitive(str,str1);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)521, UNITY_DISPLAY_STYLE_INT);

}



void test_stringIsEqualCaseInsensitive_should_equal_static(){



 Text *name1 = (Text *)"\x00\x00\x00\x80""pineApPle";

 Text *name2 = (Text *)"\x00\x00\x00\x80""aPPlE";

 String *string1 = stringNew(name1);

 string1->start = 4;

 string1->length = 5;

 String *string2 = stringNew(name2);



 stringIsEqualCaseInsensitive(string1,string2);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((stringIsEqualCaseInsensitive(string1,string2))), (((void *)0)), (_U_UINT)534, UNITY_DISPLAY_STYLE_INT);

}



void test_extra_to_solve_problem_1(void){



 Text *name = (Text *)"\x00\x00\x00\x80""Bulldog";

 String *string1 = stringNew(name);

 String *string2 = stringRemoveWordNotContaining(string1, "gd");



 assertStringEqual(("dog"), (string1), 543, ((void *)0));

 assertStringEqual(("Bull"), (string2), 544, ((void *)0));

}



void test_extra_to_solve_problem_2(){



 Text *name = (Text *)"\x00\x00\x00\x80""BaskinRobbin";

 String *string1 = stringNew(name);

 string1->start++;

 string1->length--;

 String *string2 = stringRemoveWordNotContaining(string1, "onb");



 assertStringEqual(("nRobbin"), (string1), 555, ((void *)0));

 assertStringEqual(("aski"), (string2), 556, ((void *)0));

}



void test_extra_to_solve_problem_3(){



 Text *name1 = textNew("pineApPle");

 Text *name2 = textNew("aPPlE");

 String *string1 = stringNew(name1);

 string1->start = 4;

 string1->length = 5;

 String *string2 = stringNew(name2);



 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((stringIsEqualCaseInsensitive(string1,string2))), (((void *)0)), (_U_UINT)568, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((stringIsEqualCaseInsensitive(string2,string1))), (((void *)0)), (_U_UINT)569, UNITY_DISPLAY_STYLE_INT);

 stringDel(string1);

 stringDel(string2);

}



void test_stringCharAt_should_return_index(void){



 Text *text = textNew("PoonJiyeon");

 String *string = stringNew(text);



 UnityAssertEqualNumber((_U_SINT)(('J')), (_U_SINT)((stringCharAt(string,4))), (((void *)0)), (_U_UINT)579, UNITY_DISPLAY_STYLE_INT);

}



void test_stringCharAt_should_return_index_static(void){



 Text *text = (Text *)"\x00\x00\x00\x80""PoonJiyeon";

 String *string = stringNew(text);



 UnityAssertEqualNumber((_U_SINT)(('J')), (_U_SINT)((stringCharAt(string,4))), (((void *)0)), (_U_UINT)587, UNITY_DISPLAY_STYLE_INT);

}



void test_stringCharAt_should_return_negative_1_over_string_length(void){



 Text *text = textNew("TanSooFatt");

 String *string = stringNew(text);



 UnityAssertEqualNumber((_U_SINT)((-1)), (_U_SINT)((stringCharAt(string,15))), (((void *)0)), (_U_UINT)595, UNITY_DISPLAY_STYLE_INT);

}



void test_stringCharAt_should_return_negative_1_over_string_length_static(void){



 Text *text = (Text *)"\x00\x00\x00\x80""TanSooFatt";

 String *string = stringNew(text);



 UnityAssertEqualNumber((_U_SINT)((-1)), (_U_SINT)((stringCharAt(string,15))), (((void *)0)), (_U_UINT)603, UNITY_DISPLAY_STYLE_INT);

}



void test_stringCharAt_should_return_negative_1_negative_input(void){



 Text *text = textNew("ChiewWingGum");

 String *string = stringNew(text);



 UnityAssertEqualNumber((_U_SINT)((-1)), (_U_SINT)((stringCharAt(string,-1))), (((void *)0)), (_U_UINT)611, UNITY_DISPLAY_STYLE_INT);

}



void test_stringCharAt_should_return_negative_1_negative_input_static(void){



 Text *text = (Text *)"\x00\x00\x00\x80""ChiewWingGum";

 String *string = stringNew(text);



 UnityAssertEqualNumber((_U_SINT)((-1)), (_U_SINT)((stringCharAt(string,-1))), (((void *)0)), (_U_UINT)619, UNITY_DISPLAY_STYLE_INT);

}



void test_stringIsCharAtInSet_should_return_1_contain_in_set(void){



 Text *text = textNew("StoneSir");

 String *string = stringNew(text);



 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((stringIsCharAtInSet(string,2,"abcdefghijklmno"))), (((void *)0)), (_U_UINT)627, UNITY_DISPLAY_STYLE_INT);

}



void test_stringIsCharAtInSet_should_return_0_error_input(void){



 Text *text = textNew("StoneSir");

 String *string = stringNew(text);

 string->start++;

 string->length--;



 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((stringIsCharAtInSet(string,-1,"abcdefghijklmno"))), (((void *)0)), (_U_UINT)637, UNITY_DISPLAY_STYLE_INT);

}



void test_stringIsCharAtInSet_should_return_0_not_found_in_set(void){



 Text *text = textNew("StoneSir");

 String *string = stringNew(text);

 string->start++;

 string->length--;



 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((stringIsCharAtInSet(string,0,"abcdefghijklmno"))), (((void *)0)), (_U_UINT)647, UNITY_DISPLAY_STYLE_INT);

}
