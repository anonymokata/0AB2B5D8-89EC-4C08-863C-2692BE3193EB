#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

const char NA = '*';

struct RomanArabicMap {
	char roman[2];
	int arabic;
} RomanArabicMap;

struct RomanArabicMap Zero = {{'*', '*'}, 0};

struct RomanArabicMap maps[] = {
	{{'I', '*'}, 1},
	{{'I', 'V'}, 4},
	{{'V', '*'}, 5},
	{{'I', 'X'}, 9},
	{{'X', '*'}, 10},
	{{'X', 'L'}, 40},
	{{'L', '*'}, 50},
	{{'X', 'C'}, 90},
	{{'C', '*'}, 100},
	{{'C', 'D'}, 400},
	{{'C', 'M'}, 900},
	{{'D', '*'}, 500},
	{{'M', '*'}, 1000}

};

int get_maps_size() {
	return sizeof(maps) / sizeof(RomanArabicMap);
}

bool equal(struct RomanArabicMap map, char first, char second) {
	return map.roman[0] == first
		&& (map.roman[1] == second || map.roman[1] == NA);
}

struct RomanArabicMap get_map_from_characters(char first, char second) {
	for(int i = get_maps_size() - 1; i > -1; --i) {
		struct RomanArabicMap map = maps[i];
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