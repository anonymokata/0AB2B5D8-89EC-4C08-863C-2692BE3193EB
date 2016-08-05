#ifndef ROMAN_ARABIC_MAP
#define ROMAN_ARABIC_MAP
typedef struct RomanArabicMap {
	char roman[2];
	int arabic;
	char *string;
} RomanArabicMap;

extern RomanArabicMap roman_arabic_maps[];
extern RomanArabicMap Zero;
extern const char NA;

int get_maps_size();
#endif