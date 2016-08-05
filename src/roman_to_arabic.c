#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "roman_arabic_map.h"

bool equal(struct RomanArabicMap map, char first, char second) {
	return map.roman[0] == first
		&& (map.roman[1] == second || map.roman[1] == NA);
}

struct RomanArabicMap get_map_from_characters(char first, char second) {
	for(int i = 0; i < get_maps_size; ++i) {
		struct RomanArabicMap map = roman_arabic_maps[i];
		if (equal(map, first, second)) {
			return map;
		}
	}
	return Zero;
}

struct RomanArabicMap get_map_from_string(char *roman, int index, int length) {
	char firstPart = roman[index];
	char secondPart = index < length - 1 ? roman[index + 1] : NA;
	return get_map_from_characters(firstPart, secondPart);
}

int to_arabic(char *roman) {
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