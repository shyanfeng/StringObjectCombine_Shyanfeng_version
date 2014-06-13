#ifndef __CUSTOM_TYPE_ASSERT_H__
#define __CUSTOM_TYPE_ASSERT_H__

#include "StringObject.h"
//#include "Text.h"

#define TEST_ASSERT_EQUAL_String(expected, actual)										\
		UNITY_TEST_ASSERT_EQUAL_String((expected), (actual), __LINE__, NULL)

#define UNITY_TEST_ASSERT_EQUAL_String(expected, actual, line, msg)		\
												assertStringEqual(expected, actual, line, msg)


void assertStringEqual(const char *expected, String *actual, int line, const char *msg);

#endif	// __CUSTOM_TYPE_ASSERT_H__

