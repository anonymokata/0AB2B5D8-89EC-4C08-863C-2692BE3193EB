#include <check.h>
#include "../src/roman_calculator.h"

START_TEST(add_one_plus_one_test) {
	ck_assert_int_eq(add_roman_numerals("I", "I"), "II");
}
END_TEST

int main(void){
	return 0;
}