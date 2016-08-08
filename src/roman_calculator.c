#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "roman_arabic_map.h"
#include "roman_calculator.h"
#include "roman_to_arabic.h"
#include "arabic_to_roman.h"
#include "roman_validator.h"

char * add_roman_numerals(const char *first, const char *second) {
	if(!is_roman_valid(first)) {
		return "First roman numeral is not valid";
	}

	if(!is_roman_valid(second)) {
		return "Second roman numeral is not valid";
	}

	int firstArabic = to_arabic(first);
	int secondArabic = to_arabic(second);
	return to_roman(firstArabic + secondArabic);
}

char * subtract_roman_numerals(const char *first, const char *second) {
	if(!is_roman_valid(first)) {
		return "First roman numeral is not valid";
	}

	if(!is_roman_valid(second)) {
		return "Second roman numeral is not valid";
	}

	int firstArabic = to_arabic(first);
	int secondArabic = to_arabic(second);

	if(firstArabic < secondArabic) {
		return "Invalid subtraction second number is greater than first number";
	}

	return to_roman(firstArabic - secondArabic);
}

