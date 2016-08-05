#include <stdlib.h>
#include <string.h>
#include "roman_arabic_map.h"

char *get_roman_string(RomanArabicMap map) {
	char *string = (char *)malloc(3);
	string[0] = map.roman[0];
	if (map.roman[1] != NA) {
		string[1] = map.roman[1];
	}
	return string;
}

char *to_roman(int arabic) {
	char *roman;
	roman = (char *) malloc(1000);
	for(int i = 0; i < get_maps_size(); ++i) {
		struct RomanArabicMap map = roman_arabic_maps[i]; 
		int remainder = arabic - map.arabic; 
		if(remainder >= 0) {
			arabic = remainder;
			strcpy(roman, get_roman_string(map));
		}		

		if (arabic == 0) {
			break;
		}
	}
	return roman;
}