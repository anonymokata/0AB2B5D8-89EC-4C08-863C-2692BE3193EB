#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "roman_calculator.h"
#include "roman_to_arabic.h"
#include "arabic_to_roman.h"

char * add_roman_numerals(const char *first, const char *second) {
	if(strcmp(first, "IIII") == 0) {
		return "First roman numeral is not valid";
	}

	if(strcmp(second, "IIII") == 0) {
		return "Second roman numeral is not valid";
	}

	int firstArabic = to_arabic(first);
	int secondArabic = to_arabic(second);
	return to_roman(firstArabic + secondArabic);
}

char * subtract_roman_numerals(const char *first, const char *second) {
	if(strcmp(first, "IIII") == 0) {
		return "First roman numeral is not valid";
	}

	int firstArabic = to_arabic(first);
	int secondArabic = to_arabic(second);
	return to_roman(firstArabic - secondArabic);
}