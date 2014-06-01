#include "unity.h"
#include "stringObject.h"
#include "String.h"

typedef struct FakeText {
	uint32 reference;
	char string[80];
} FakeText;

void setUp(){}
void tearDown(){}

/*
void test_stringDump_should_print_whole_word(void){
	FakeText fakeText = {
		.reference = 10,
		.string = "hello world!"
	};
	String str = {
		.reference = 20,
		.text = (Text *)&fakeText,
		.start = 0,
		.length = 12
		};
	stringDump(&str);
}

void test_stringDump_should_print_from_fifth_word(void){
	FakeText fakeText = {
		.reference = 10,
		.string = "hello world!"
	};
	String str = {
		.reference = 20,
		.text = (Text *)&fakeText,
		.start = 4,
		.length = 12
		};
	stringDump(&str);
}

void test_stringDump_should_print_only_5_character(void){
	FakeText fakeText = {
		.reference = 10,
		.string = "hello world!"
	};
	String str = {
		.reference = 20,
		.text = (Text *)&fakeText,
		.start = 0,
		.length = 6
		};
	stringDump(&str);
}

void test_stringDump_should_not_print_with_0_length(void){
	FakeText fakeText = {
		.reference = 10,
		.string = "hello world!"
	};
	String str = {
		.reference = 20,
		.text = (Text *)&fakeText,
		.start = 0,
		.length = 0
		};
	stringDump(&str);
}

void test_stringDump_should_not_print_with_overload_start(void){
	FakeText fakeText = {
		.reference = 10,
		.string = "hello world!"
	};
	String str = {
		.reference = 20,
		.text = (Text *)&fakeText,
		.start = 12,
		.length =12
		};
	stringDump(&str);
}
*/

void test_textNew_should_create_dynamic_text_properly(void){
	int compare;
	Text *text = textNew("FooSatt");
	compare = strcmp(text->string,"FooSatt");
	TEST_ASSERT_EQUAL(0,compare);
	TEST_ASSERT_EQUAL(1,text->reference);
}

void test_textNew_should_create_static_text_properly(void){
	int compare;
	Text *text = t"JoonPon";
	compare = strcmp(text->string,"JoonPon");
	TEST_ASSERT_EQUAL(0,compare);
	TEST_ASSERT_EQUAL_HEX32(0x80000000,text->reference);
}

void test_textAssign_should_increase_reference(void){
	int compare;
	Text *text = textNew("LheeCiang");
	Text *text2 = textAssign(text);
	
	compare = strcmp(text->string,text2->string);
	TEST_ASSERT_EQUAL(2,text->reference);
	TEST_ASSERT_EQUAL(0,compare);
}

void test_textAssign_should_not_increase_reference(void){
	int compare;
	Text *text = t"XingBuan";
	Text *text2 = textAssign(text);
	
	compare = strcmp(text->string,text2->string);
	TEST_ASSERT_EQUAL_HEX32(0x80000000,text->reference);
	TEST_ASSERT_EQUAL(0,compare);
}

void test_textDel_should_delete_dynamic_text(void){
	Text *toCompare;
	Text *text = textNew("YhoonCung");
	toCompare = textDel(text);

	TEST_ASSERT_EQUAL(NULL,toCompare);
}

void test_textDel_should_not_delete_static_text(void){
	Text *toCompare;
	Text *text = t"WingJen";
	toCompare = textDel(text);

	TEST_ASSERT_EQUAL(text,toCompare);
	TEST_ASSERT_EQUAL_HEX32(0x80000000,toCompare->reference);
}

void test_textDel_should_not_delete_when_reference_not_0(void){
	Text *toCompare;
	Text *text = textNew("FhyanSeng");
	Text *text1 = textAssign(text);
	toCompare = textDel(text);

	TEST_ASSERT_EQUAL(text,toCompare);
	TEST_ASSERT_EQUAL(text1,toCompare);
	TEST_ASSERT_EQUAL(1,toCompare->reference);
}

void test_textDel_should_not_delete_and_reduce_reference(void){
	Text *toCompare;
	Text *text = t"FhyanSeng";
	Text *text1 = textAssign(text);
	toCompare = textDel(text);

	TEST_ASSERT_EQUAL(text,toCompare);
	TEST_ASSERT_EQUAL(text1,toCompare);
	TEST_ASSERT_EQUAL(0x80000000,toCompare->reference);
}

void test_stringNew_should_create_string_with_dynamic_text(void){
	int toCompare;
	Text *text = textNew("FhyanSeng");
	String *str = stringNew(text);
	
	toCompare = strcmp(str->text->string,text->string);
	TEST_ASSERT_EQUAL(0,toCompare);
	TEST_ASSERT_EQUAL(1,str->reference);
	TEST_ASSERT_EQUAL(0,str->start);
	TEST_ASSERT_EQUAL(9,str->length);
	TEST_ASSERT_EQUAL(2,str->text->reference);
}

void test_stringNew_should_create_string_with_static_text(void){
	int toCompare;
	Text *text = t"DreFick";
	String *str = stringNew(text);
	toCompare = strcmp(str->text->string,text->string);
	TEST_ASSERT_EQUAL(0,toCompare);
	TEST_ASSERT_EQUAL(1,str->reference);
	TEST_ASSERT_EQUAL(0,str->start);
	TEST_ASSERT_EQUAL(7,str->length);
	TEST_ASSERT_EQUAL_HEX32(0x80000000,str->text->reference);
}

void test_stringAssign_should_increase_reference(void){
	Text *text = textNew("JaNib");
	String *str = stringNew(text);
	String *str1 = stringAssign(str);
	String *str2 = stringAssign(str);
	TEST_ASSERT_EQUAL(3,str->reference);
	TEST_ASSERT_EQUAL(2,str->text->reference);
}

void test_stringDel_should_delete_and_reduce_text_reference(void){
	String *toCompare;
	Text *text = textNew("MosRah");
	String *str = stringNew(text);
	String *str1 = stringAssign(str);
	String *str2 = stringAssign(str);
	toCompare = stringDel(str);
	TEST_ASSERT_EQUAL(2,toCompare->reference);
	TEST_ASSERT_EQUAL(2,str->text->reference);
}

void test_stringDel_should_delete_and_not_reduce_text_reference(void){
	String *toCompare;
	Text *text = t"SelNon";
	String *str = stringNew(text);
	String *str1 = stringAssign(str);
	String *str2 = stringAssign(str);
	toCompare = stringDel(str);
	TEST_ASSERT_EQUAL(2,toCompare->reference);
	TEST_ASSERT_EQUAL_HEX32(0x80000000,str->text->reference);
}

void test_stringSkip_should_skip(void){
	Text *text = textNew("SelNon");
	String *str = stringNew(text);
	stringSkip(str,2);
	TEST_ASSERT_EQUAL(2,str->start);
	TEST_ASSERT_EQUAL(4,str->length);
}

void test_stringSkip_should_overload_and_stop_at_Null(void){
	Text *text = textNew("SelNonDan");
	String *str = stringNew(text);
	str->start++; //1
	stringSkip(str,100);
	TEST_ASSERT_EQUAL(9,str->start);
	TEST_ASSERT_EQUAL(0,str->length);
}
void test_stringTrimLeft(void){
	Text *text = textNew("SaJon ");
	String *str = stringNew(text);
	stringTrimLeft(str);
	TEST_ASSERT_EQUAL(0,str->start);
	TEST_ASSERT_EQUAL(6,str->length);
}

void test_stringTrimLeft2(void){
	Text *text = textNew("    HohnJon ");
	String *str = stringNew(text);
	str->start+=3;
	stringTrimLeft(str);
	TEST_ASSERT_EQUAL(4,str->start);
	TEST_ASSERT_EQUAL(8,str->length);
}

void test_stringTrimRight(void){
	Text *text = textNew("    LuJian  ");
	String *str = stringNew(text);
	stringTrimRight(str);
	TEST_ASSERT_EQUAL(0,str->start);
	TEST_ASSERT_EQUAL(10,str->length);
}

void test_stringTrimRight2(void){
	Text *text = textNew("   DeeFer\t");
	String *str = stringNew(text);
	stringTrimRight(str);
	TEST_ASSERT_EQUAL(0,str->start);
	TEST_ASSERT_EQUAL(9,str->length);
}

void test_stringTrim_should_trim_both_sides(void){
	Text *text = textNew("  \t \t \t  VeaLer     ");
	String *str = stringNew(text);
	stringTrim(str);
	TEST_ASSERT_EQUAL(9,str->start);
	TEST_ASSERT_EQUAL(6,str->length);
}

void test_stringTrim_should_trim_both_sides2(void){
	Text *text = textNew("  GaLger \t\t    ");
	String *str = stringNew(text);
	stringTrim(str);
	TEST_ASSERT_EQUAL(2,str->start);
	TEST_ASSERT_EQUAL(6,str->length);
}

void test_stringTrim_should_trim_both_sides3(void){
	Text *text = textNew(" \t\t BeedFack \t\t    ");
	String *str = stringNew(text);
	stringTrim(str);
	TEST_ASSERT_EQUAL(4,str->start);
	TEST_ASSERT_EQUAL(8,str->length);
}

void test_all(void){
	String *toCompare;
	Text *text = textNew(" \t\t ahaha \t\t    ");
	
	String *str = stringNew(text);
	String *str2 = stringAssign(str);
	TEST_ASSERT_EQUAL(2,text->reference);

	toCompare = stringDel(str); //still got 1
	TEST_ASSERT_EQUAL(2,text->reference);
	TEST_ASSERT_EQUAL(1,toCompare->reference);
	
	toCompare = stringDel(str); //no more
	//unable to TEST_ASSERT_EQUAL, bad memory because already removed
	TEST_ASSERT_EQUAL(1,text->reference);
	
	stringTrim(str);
	TEST_ASSERT_EQUAL(4,str->start);
	TEST_ASSERT_EQUAL(5,str->length);
}