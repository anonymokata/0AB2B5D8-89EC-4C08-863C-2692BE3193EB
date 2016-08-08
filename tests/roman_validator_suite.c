#include <stdlib.h>
#include <check.h>
#include <stdbool.h>
#include <errno.h>
#include "../src/roman_error_codes.h"
#include "../src/roman_validator.h"
#include "roman_validator_suite.h"

START_TEST(given_IIII_when_is_roman_valid_then_false) {
	bool isValid = is_roman_valid("IIII");
	ck_assert(isValid == false);
	ck_assert_int_eq(ROMAN_NUMERAL_LIMIT, errno);
}
END_TEST

START_TEST(given_XXXX_when_is_roman_valid_then_false) {
	bool isValid = is_roman_valid("XXXX");
	ck_assert(isValid == false);
	ck_assert_int_eq(ROMAN_NUMERAL_LIMIT, errno);
}
END_TEST

START_TEST(given_CCCC_when_is_roman_valid_then_false) {
	bool isValid = is_roman_valid("CCCC");
	ck_assert(isValid == false);
	ck_assert_int_eq(ROMAN_NUMERAL_LIMIT, errno);
}
END_TEST

START_TEST(given_MMMM_when_is_roman_valid_then_false) {
	bool isValid = is_roman_valid("MMMM");
	ck_assert(isValid == false);
	ck_assert_int_eq(ROMAN_NUMERAL_LIMIT, errno);
}
END_TEST

START_TEST(given_DD_when_is_roman_valid_then_false) {
	bool isValid = is_roman_valid("DD");
	ck_assert(isValid == false);
	ck_assert_int_eq(ROMAN_NUMERAL_LIMIT, errno);
}
END_TEST

START_TEST(given_LL_when_is_roman_valid_then_false) {
	bool isValid = is_roman_valid("LL");
	ck_assert(isValid == false);
	ck_assert_int_eq(ROMAN_NUMERAL_LIMIT, errno);
}
END_TEST

START_TEST(given_VV_when_is_roman_valid_then_false) {
	bool isValid = is_roman_valid("VV");
	ck_assert(isValid == false);
}
END_TEST

START_TEST(given_MMMCMXCIX_when_is_roman_valid_then_true) {
	bool isValid = is_roman_valid("MMMCMXCIX");
	ck_assert(isValid == true);
}
END_TEST

Suite * roman_validator_suite(void) {
	Suite *suite;
	TCase *testCase;

	suite = suite_create("Roman Validator");
	testCase = tcase_create("Is Roman Valid");

	tcase_add_test(testCase, given_IIII_when_is_roman_valid_then_false);
	tcase_add_test(testCase, given_XXXX_when_is_roman_valid_then_false);
	tcase_add_test(testCase, given_CCCC_when_is_roman_valid_then_false);
	tcase_add_test(testCase, given_MMMM_when_is_roman_valid_then_false);
	
	tcase_add_test(testCase, given_DD_when_is_roman_valid_then_false);
	tcase_add_test(testCase, given_LL_when_is_roman_valid_then_false);
	tcase_add_test(testCase, given_VV_when_is_roman_valid_then_false);

	tcase_add_test(testCase, given_MMMCMXCIX_when_is_roman_valid_then_true);

	suite_add_tcase(suite, testCase);
	return suite;
}