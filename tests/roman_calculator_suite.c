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

START_TEST(given_IX_and_CM_when_add_then_CMIX) {
	char * result = add_roman_numerals("IX", "CM");
	ck_assert_str_eq(result, "CMIX");
}
END_TEST

START_TEST(given_MCXVI_and_CM_when_add_then_CMIX) {
	// MCXVI      = 1116
	// DCCCLXXXIV = 0884
	// MM         = 2000
	char * result = add_roman_numerals("MCXVI", "DCCCLXXXIV");
	ck_assert_str_eq(result, "MM");
}
END_TEST

START_TEST(given_II_and_I_when_subtract_then_I) {
	char * result = subtract_roman_numerals("II", "I");
	ck_assert_str_eq(result, "I");
}
END_TEST

START_TEST(given_IV_and_I_when_subtract_then_III) {
	char * result = subtract_roman_numerals("IV", "I");
	ck_assert_str_eq(result, "III");
}
END_TEST

START_TEST(given_M_and_CM_when_subtract_then_C) {
	char * result = subtract_roman_numerals("M", "CM");
	ck_assert_str_eq(result, "C");
}
END_TEST

START_TEST(given_CM_and_X_when_subtract_then_DCCCXC) {
	// CM     = 900
	// X      = 10
	// -
	// DCCCXC = 890

	char * result = subtract_roman_numerals("CM", "X");
	ck_assert_str_eq(result, "DCCCXC");
}
END_TEST

TCase *create_add_test_case() {
	TCase *add_case;
	add_case = tcase_create("Add");
	tcase_add_test(add_case, given_I_and_I_when_add_then_II);
	tcase_add_test(add_case, given_II_and_I_when_add_then_III);
	tcase_add_test(add_case, given_II_and_II_when_add_then_IV);
	tcase_add_test(add_case, given_IX_and_CM_when_add_then_CMIX);
	tcase_add_test(add_case, given_MCXVI_and_CM_when_add_then_CMIX);
	return add_case;
}

TCase *create_subtract_test_case() {
	TCase *subtract_case;
	subtract_case = tcase_create("Subtract");
	tcase_add_test(subtract_case, given_II_and_I_when_subtract_then_I);
	tcase_add_test(subtract_case, given_IV_and_I_when_subtract_then_III);
	tcase_add_test(subtract_case, given_M_and_CM_when_subtract_then_C);
	tcase_add_test(subtract_case, given_CM_and_X_when_subtract_then_DCCCXC);
	return subtract_case;
}

Suite * roman_calculator_suite(void) {
	Suite *s;
	s = suite_create("Roman Calculator");
	suite_add_tcase(s, create_add_test_case());
	suite_add_tcase(s, create_subtract_test_case());
	return s;
}