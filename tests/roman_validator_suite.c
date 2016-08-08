#include <stdlib.h>
#include <check.h>
#include <stdbool.h>
#include "../src/roman_validator.h"
#include "roman_validator_suite.h"

Suite * roman_validator_suite(void) {
	Suite *suite;
	TCase *testCase;

	suite = suite_create("Roman Validator");
	testCase = tcase_create("Is Roman Valid");

	suite_add_tcase(suite, testCase);
	return suite;
}