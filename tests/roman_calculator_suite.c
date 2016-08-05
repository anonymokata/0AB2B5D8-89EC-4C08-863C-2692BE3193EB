#include <stdlib.h>
#include <check.h>
#include "../src/roman_calculator.h"
#include "roman_calculator_suite.h"

START_TEST(given_I_and_I_when_add_then_II) {
	char * result = add_roman_numerals("I", "I");
	ck_assert_str_eq(result, "II");
}
END_TEST

START_TEST(given_II_and_I_when_add_then_III) {
	char * result = add_roman_numerals("II", "I");
	ck_assert_str_eq(result, "III");
}
END_TEST

START_TEST(given_II_and_II_when_add_then_IV) {
	char * result = add_roman_numerals("II", "II");
	ck_assert_str_eq(result, "IV");
}
END_TEST

Suite * roman_calculator_suite(void) {
	Suite *s;
	TCase *tc_core;

	s = suite_create("Roman Calculator");
	tc_core = tcase_create("Add");

	tcase_add_test(tc_core, given_I_and_I_when_add_then_II);
	tcase_add_test(tc_core, given_II_and_I_when_add_then_III);
	tcase_add_test(tc_core, given_II_and_II_when_add_then_IV);
	suite_add_tcase(s, tc_core);

	return s;
}