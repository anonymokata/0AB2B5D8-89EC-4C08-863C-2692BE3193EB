#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include "roman_error_codes.h"
#include "roman_arabic_map.h"
#include "roman_validator.h"

int get_map_index(struct RomanArabicMap map) {
	for(int i = 0; i < get_maps_size(); ++i) {
		if (are_equal(roman_arabic_maps[i], map)) {
			return i;
		}
	}

	return -1;
}

bool is_roman_valid(const char *roman) {
	int length = strlen(roman);
	int mapsSize = get_maps_size();
	int counts[mapsSize];

	for(int i = 0; i < mapsSize; ++i) {
		counts[i] = 0;
	}
	
	for(int i = 0; i < length; ++i) {
		struct RomanArabicMap map = get_map_from_string(roman, i, length);
		if(map.roman[1] != NA) {
			i++;
		}
		int mapIndex = get_map_index(map);
		counts[mapIndex]++;

		if(counts[mapIndex] > map.limit) {
			errno = ROMAN_NUMERAL_LIMIT;
			return false;
		}
	}

	errno = 0;
	return true;
}