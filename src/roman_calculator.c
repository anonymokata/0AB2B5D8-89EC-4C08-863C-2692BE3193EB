#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "roman_calculator.h"

struct Map {
	char *roman;
	int arabic;
	int romanLength;
};

struct Map maps[] = {
	{"I", 1, 1},
	{"IV", 4, 2}
};

int get_maps_size() {
	return sizeof(maps) / sizeof(struct Map);
}

bool equal(char *value, char *expected) {
	return strcmp(value, expected) == 0;
}

char * convert_to_roman(int value) {
	char *roman = malloc();
	int remainder = value;
	for (int i = get_maps_size(); i > -1; --i) {
		if (remainder > maps[i].arabic) {
			remainder = remainder - maps[i].arabic;
		}
	}

	return roman;
}

int convert_to_arabic(char *roman) {
	int value = 0;

	int length = strlen(roman);
	for (int i = 0; i < length - 1; ++i) {
		char characters[2] = { roman[i], 0 };
		for(int j = get_maps_size(); j >= 0; j--) {
			if(equal(maps[j].roman, characters)) {
				value += maps[j].arabic;
			}
		}
	}
	return value;
}

char * add_roman_numerals(char *first, char *second) {
	int firstArabic = convert_to_arabic(first);
	int secondArabic = convert_to_arabic(second);
	return convert_to_roman(firstArabic + secondArabic);
}