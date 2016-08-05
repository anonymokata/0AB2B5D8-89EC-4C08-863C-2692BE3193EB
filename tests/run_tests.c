#include <stdlib.h>
#include <check.h>
#include "roman_calculator_suite.h"
#include "roman_to_arabic_suite.h"

int main(void) {
	int failed_count;
	Suite *suite;
	SRunner *runner;

	suite = roman_calculator_suite();
	runner = srunner_create(suite);
	srunner_add_suite(runner, roman_to_arabic_suite());

	srunner_run_all(runner, CK_VERBOSE);
	failed_count = srunner_ntests_failed(runner);
	srunner_free(runner);

	return (failed_count == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}