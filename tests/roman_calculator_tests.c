#include <stdlib.h>
#include <check.h>
#include "../src/roman_calculator.h"

START_TEST(add_one_plus_one_test) {
	ck_assert_str_eq(add_roman_numerals("I", "I"), "II");
}
END_TEST

Suite * roman_calculator_suite(void) {
	Suite *s;
	TCase *tc_core;

	s = suite_create("Roman Calculator");
	tc_core = tcase_create("Add");

	tcase_add_test(tc_core, add_one_plus_one_test);
	suite_add_tcase(s, tc_core);

	return s;
}

int main(void) {
	int failed_count;
	Suite *suite;
	SRunner *suiteRunner;

	suite = roman_calculator_suite();
	suiteRunner = srunner_create(suite);

	srunner_run_all(suiteRunner, CK_NORMAL);
	failed_count = srunner_ntests_failed(suiteRunner);
	srunner_free(suiteRunner);
	return (failed_count == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}