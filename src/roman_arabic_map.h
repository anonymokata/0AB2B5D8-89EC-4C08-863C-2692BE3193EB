#include <stdbool.h>

#ifndef ROMAN_ARABIC_MAP
#define ROMAN_ARABIC_MAP
typedef struct RomanArabicMap {
	char roman[2];
	int arabic;
	int limit;
} RomanArabicMap;

extern RomanArabicMap roman_arabic_maps[];
extern RomanArabicMap Zero;
extern const char NA;

int get_maps_size();
bool equal(struct RomanArabicMap map, char first, char second);
bool are_equal(struct RomanArabicMap map1, struct RomanArabicMap map2);
struct RomanArabicMap get_map_from_string(const char *roman, int index, int length);
#endif