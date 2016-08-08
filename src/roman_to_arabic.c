#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "roman_arabic_map.h"

int to_arabic(const char *roman) {
	int value = 0;
	int length = strlen(roman);
	for(int i = 0; i < length; ++i) {
		struct RomanArabicMap map = get_map_from_string(roman, i, length);
		value += map.arabic;
		if(map.roman[1] != NA) {
			i++;
		}
	}
	return value;
}