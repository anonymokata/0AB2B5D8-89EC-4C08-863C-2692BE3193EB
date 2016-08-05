#include "roman_arabic_map.h"

const char NA = '*';

struct RomanArabicMap Zero = {{'*', '*'}, 0};

struct RomanArabicMap roman_arabic_maps[] = {
	{{'M', '*'}, 1000},
	{{'C', 'M'}, 900},
	{{'D', '*'}, 500},
	{{'C', 'D'}, 400},
	{{'C', '*'}, 100},
	{{'X', 'C'}, 90},
	{{'L', '*'}, 50},
	{{'X', 'L'}, 40},
	{{'X', '*'}, 10},
	{{'I', 'X'}, 9},
	{{'V', '*'}, 5},
	{{'I', 'V'}, 4},
	{{'I', '*'}, 1}
};

int get_maps_size() {
	return sizeof(roman_arabic_maps) / sizeof(RomanArabicMap);
}