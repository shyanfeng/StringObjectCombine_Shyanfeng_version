#include "unity.h"
#include "Text.h"

void setUp(void){}
void tearDown(void){}


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
