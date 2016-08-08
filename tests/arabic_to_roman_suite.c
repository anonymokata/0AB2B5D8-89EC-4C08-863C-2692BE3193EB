#include <stdlib.h>
#include <check.h>
#include <errno.h>
#include "../src/arabic_to_roman.h"
#include "../src/roman_error_codes.h"
#include "arabic_to_roman_suite.h"

START_TEST(given_1_when_to_roman_then_I) {
	char *result = to_roman(1);
	ck_assert_str_eq(result, "I");
}
END_TEST

START_TEST(given_4_when_to_roman_then_IV) {
	char *result = to_roman(4);
	ck_assert_str_eq(result, "IV");
}
END_TEST

START_TEST(given_5_when_to_roman_then_V) {
	char *result = to_roman(5);
	ck_assert_str_eq(result, "V");
}
END_TEST

START_TEST(given_9_when_to_roman_then_IX) {
	char *result = to_roman(9);
	ck_assert_str_eq(result, "IX");
};
END_TEST

START_TEST(given_10_when_to_roman_then_X) {
	char *result = to_roman(10);
	ck_assert_str_eq(result, "X");
};
END_TEST

START_TEST(given_40_when_to_roman_then_XL) {
	char *result = to_roman(40);
	ck_assert_str_eq(result, "XL");
};
END_TEST

START_TEST(given_50_when_to_roman_then_L) {
	char *result = to_roman(50);
	ck_assert_str_eq(result, "L");
};
END_TEST

START_TEST(given_90_when_to_roman_then_XC) {
	char *result = to_roman(90);
	ck_assert_str_eq(result, "XC");
}
END_TEST

START_TEST(given_100_when_to_roman_then_C) {
	char *result = to_roman(100);
	ck_assert_str_eq(result, "C");
}
END_TEST

START_TEST(given_400_when_to_roman_then_CD) {
	char *result = to_roman(400);
	ck_assert_str_eq(result, "CD");
}
END_TEST

START_TEST(given_500_when_to_roman_then_D) {
	char *result = to_roman(500);
	ck_assert_str_eq(result, "D");
}
END_TEST

START_TEST(given_900_when_to_roman_then_CM) {
	char *result = to_roman(900);
	ck_assert_str_eq(result, "CM");
}
END_TEST

START_TEST(given_1000_when_to_roman_then_M) {
	char *result = to_roman(1000);
	ck_assert_str_eq(result, "M");
}
END_TEST

START_TEST(given_103_when_to_roman_then_CIII) {
	char *result = to_roman(103);
	ck_assert_str_eq(result, "CIII");
}
END_TEST

START_TEST(given_999_when_to_roman_then_CMXCIX) {
	char *result = to_roman(999);
	ck_assert_str_eq(result, "CMXCIX");
}
END_TEST

START_TEST(given_1099_when_to_roman_then_MXCIX) {
	char *result = to_roman(1099);
	ck_assert_str_eq(result, "MXCIX");
}
END_TEST

START_TEST(given_3999_when_to_roman_then_MMMCMXCIX) {
	char *result = to_roman(3999);
	ck_assert_str_eq(result, "MMMCMXCIX");
}
END_TEST

START_TEST(given_4000_when_to_roman_then_roman_number_too_large) {
	char *result = to_roman(4000);
	ck_assert_str_eq(result, "Resulting value is not valid");
	ck_assert_int_eq(errno, ROMAN_NUMERAL_TOO_LARGE);
}
END_TEST

START_TEST(given_0_when_to_roman_then_zero_is_not_a_valid_roman_number) {
	char *result = to_roman(0);
	ck_assert_str_eq(result, "Zero is not a valid roman number");
	ck_assert_int_eq(errno, ROMAN_ZERO_IS_NOT_VALID);
}
END_TEST

START_TEST(given_negative_1_when_to_roman_then_negative_numbers_are_not_allowed) {
	char *result = to_roman(-1);
	ck_assert_str_eq(result, "Negative numbers are not allowed");
	ck_assert_int_eq(errno, ROMAN_NEGATIVE_NOT_VALID);
}	
END_TEST

Suite * arabic_to_roman_suite(void) {
	Suite *suite;
	TCase *testCase;

	suite = suite_create("Arabic To Roman");
	testCase = tcase_create("To Roman");

	tcase_add_test(testCase, given_1_when_to_roman_then_I);
	tcase_add_test(testCase, given_4_when_to_roman_then_IV);
	tcase_add_test(testCase, given_5_when_to_roman_then_V);
	tcase_add_test(testCase, given_9_when_to_roman_then_IX);
	tcase_add_test(testCase, given_10_when_to_roman_then_X);
	tcase_add_test(testCase, given_40_when_to_roman_then_XL);
	tcase_add_test(testCase, given_50_when_to_roman_then_L);
	tcase_add_test(testCase, given_90_when_to_roman_then_XC);
	tcase_add_test(testCase, given_100_when_to_roman_then_C);
	tcase_add_test(testCase, given_400_when_to_roman_then_CD);
	tcase_add_test(testCase, given_500_when_to_roman_then_D);
	tcase_add_test(testCase, given_900_when_to_roman_then_CM);
	tcase_add_test(testCase, given_1000_when_to_roman_then_M);

	tcase_add_test(testCase, given_103_when_to_roman_then_CIII);
	tcase_add_test(testCase, given_999_when_to_roman_then_CMXCIX);
	tcase_add_test(testCase, given_1099_when_to_roman_then_MXCIX);
	tcase_add_test(testCase, given_3999_when_to_roman_then_MMMCMXCIX);

	tcase_add_test(testCase, given_4000_when_to_roman_then_roman_number_too_large);
	tcase_add_test(testCase, given_0_when_to_roman_then_zero_is_not_a_valid_roman_number);
	tcase_add_test(testCase, given_negative_1_when_to_roman_then_negative_numbers_are_not_allowed);

	suite_add_tcase(suite, testCase);
	return suite;
}