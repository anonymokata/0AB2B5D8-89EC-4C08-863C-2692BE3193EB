#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "roman_calculator.h"
#include "roman_to_arabic.h"
#include "arabic_to_roman.h"

char * add_roman_numerals(char *first, char *second) {
	int firstArabic = to_arabic(first);
	int secondArabic = to_arabic(second);
	return to_roman(firstArabic + secondArabic);
}