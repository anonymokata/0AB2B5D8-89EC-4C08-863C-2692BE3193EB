#include <stdlib.h>
#include <check.h>
#include "../src/roman_to_arabic.h"
#include "roman_to_arabic_suite.h"

START_TEST(given_I_when_to_arabic_then_1) {
	int result = to_arabic("I");
	ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(given_IV_when_to_arabic_then_4) {
	int result = to_arabic("IV");
	ck_assert_int_eq(result, 4);
}
END_TEST

START_TEST(given_V_when_to_arabic_then_5) {
	int result = to_arabic("V");
	ck_assert_int_eq(result, 5);
}
END_TEST

START_TEST(given_IX_when_to_arabic_then_9) {
	int result = to_arabic("IX");
	ck_assert_int_eq(result, 9);
};
END_TEST

START_TEST(given_X_when_to_arabic_then_10) {
	int result = to_arabic("X");
	ck_assert_int_eq(result, 10);
};
END_TEST

START_TEST(given_XL_when_to_arabic_then_40) {
	int result = to_arabic("XL");
	ck_assert_int_eq(result, 40);
};
END_TEST

START_TEST(given_L_when_to_arabic_then_50) {
	int result = to_arabic("L");
	ck_assert_int_eq(result, 50);
};
END_TEST

START_TEST(given_XC_when_to_arabic_then_90) {
	int result = to_arabic("XC");
	ck_assert_int_eq(result, 90);
}
END_TEST

START_TEST(given_C_when_to_arabic_then_100) {
	int result = to_arabic("C");
	ck_assert_int_eq(result, 100);
}
END_TEST

START_TEST(given_CD_when_to_arabic_then_400) {
	int result = to_arabic("CD");
	ck_assert_int_eq(result, 400);
}
END_TEST

START_TEST(given_D_when_to_arabic_then_500) {
	int result = to_arabic("D");
	ck_assert_int_eq(result, 500);
}
END_TEST

START_TEST(given_CM_when_to_arabic_then_900) {
	int result = to_arabic("CM");
	ck_assert_int_eq(result, 900);
}
END_TEST

START_TEST(given_M_when_to_arabic_then_1000) {
	int result = to_arabic("M");
	ck_assert_int_eq(result, 1000);
}
END_TEST

START_TEST(given_CIII_when_to_arabic_then_103) {
	int result = to_arabic("CIII");
	ck_assert_int_eq(result, 103);
}
END_TEST

START_TEST(given_CMXCIX_when_to_arabic_then_999) {
	int result = to_arabic("CMXCIX");
	ck_assert_int_eq(result, 999);
}
END_TEST

START_TEST(given_MXCIX_when_to_arabic_then_1099) {
	int result = to_arabic("MXCIX");
	ck_assert_int_eq(result, 1099);
}
END_TEST

START_TEST(given_DCCCLXXXIV_when_to_arabic_then_884) {
	int result = to_arabic("DCCCLXXXIV");
	ck_assert_int_eq(result, 884);
}
END_TEST

START_TEST(given_MMMCMXCIX_when_to_arabic_then_3999) {
	int result = to_arabic("MMMCMXCIX");
	ck_assert_int_eq(result, 3999);
}
END_TEST

Suite * roman_to_arabic_suite(void) {
	Suite *suite;
	TCase *testCase;

	suite = suite_create("Roman To Arabic");
	testCase = tcase_create("To Arabic");

	tcase_add_test(testCase, given_I_when_to_arabic_then_1);
	tcase_add_test(testCase, given_IV_when_to_arabic_then_4);
	tcase_add_test(testCase, given_V_when_to_arabic_then_5);
	tcase_add_test(testCase, given_IX_when_to_arabic_then_9);
	tcase_add_test(testCase, given_X_when_to_arabic_then_10);
	tcase_add_test(testCase, given_XL_when_to_arabic_then_40);
	tcase_add_test(testCase, given_L_when_to_arabic_then_50);
	tcase_add_test(testCase, given_XC_when_to_arabic_then_90);
	tcase_add_test(testCase, given_C_when_to_arabic_then_100);
	tcase_add_test(testCase, given_CD_when_to_arabic_then_400);
	tcase_add_test(testCase, given_D_when_to_arabic_then_500);
	tcase_add_test(testCase, given_CM_when_to_arabic_then_900);
	tcase_add_test(testCase, given_M_when_to_arabic_then_1000);

	tcase_add_test(testCase, given_CIII_when_to_arabic_then_103);
	tcase_add_test(testCase, given_CMXCIX_when_to_arabic_then_999);
	tcase_add_test(testCase, given_MXCIX_when_to_arabic_then_1099);
	tcase_add_test(testCase, given_DCCCLXXXIV_when_to_arabic_then_884);
	tcase_add_test(testCase, given_MMMCMXCIX_when_to_arabic_then_3999);

	suite_add_tcase(suite, testCase);
	return suite;
}