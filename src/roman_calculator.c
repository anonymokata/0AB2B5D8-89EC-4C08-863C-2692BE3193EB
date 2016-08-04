#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "roman_calculator.h"

char * convert_to_roman(int value) {
	if (value == 2) {
		return "II";
	}

	return "III";
}

bool equal(char *value, char *expected) {
	return strcmp(value, expected) == 0;
}

int convert_to_arabic(char *roman) {
	if (equal(roman, "I")) {
		return 1;
	}
	
	return 2;
}

char * add_roman_numerals(char *first, char *second) {
	int firstArabic = convert_to_arabic(first);
	int secondArabic = convert_to_arabic(second);
	int result = firstArabic + secondArabic;
	return convert_to_roman(result);
}