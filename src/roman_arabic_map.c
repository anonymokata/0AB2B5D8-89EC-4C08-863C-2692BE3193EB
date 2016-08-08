#include <stdbool.h>
#include "roman_arabic_map.h"

const char NA = '*';
const int MAX_ARABIC_VALUE = 3999;

struct RomanArabicMap Zero = {{'*', '*'}, 0, 0};

struct RomanArabicMap roman_arabic_maps[] = {
	{{'M', '*'}, 1000, 3},
	{{'C', 'M'}, 900, 1},
	{{'D', '*'}, 500, 1},
	{{'C', 'D'}, 400, 1},
	{{'C', '*'}, 100, 3},
	{{'X', 'C'}, 90, 1},
	{{'L', '*'}, 50, 1},
	{{'X', 'L'}, 40, 1},
	{{'X', '*'}, 10, 3},
	{{'I', 'X'}, 9, 1},
	{{'V', '*'}, 5, 1},
	{{'I', 'V'}, 4, 1},
	{{'I', '*'}, 1, 3}
};

int get_maps_size() {
	return sizeof(roman_arabic_maps) / sizeof(RomanArabicMap);
}

bool equal(struct RomanArabicMap map, char first, char second) {
	return map.roman[0] == first
		&& (map.roman[1] == second || map.roman[1] == NA);
}

bool are_equal(struct RomanArabicMap map1, struct RomanArabicMap map2) {
	return map1.roman[0] == map2.roman[0]
		&& map1.roman[1] == map2.roman[1];
}

struct RomanArabicMap get_map_from_characters(char first, char second) {
	for(int i = 0; i < get_maps_size(); ++i) {
		struct RomanArabicMap map = roman_arabic_maps[i];
		if (equal(map, first, second)) {
			return map;
		}
	}
	return Zero;
}

struct RomanArabicMap get_map_from_string(const char *roman, int index, int length) {
	char firstPart = roman[index];
	char secondPart = index < length - 1 ? roman[index + 1] : NA;
	return get_map_from_characters(firstPart, secondPart);
}