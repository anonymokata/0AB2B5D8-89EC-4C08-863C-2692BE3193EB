#include <stdlib.h>
#include <string.h>
#include "roman_arabic_map.h"

struct RomanArabicMap get_roman_arabic_map(int remainder) {
	for(int i = 0; i < get_maps_size(); ++i) {
		struct RomanArabicMap map = roman_arabic_maps[i]; 
		if (remainder - map.arabic >= 0) {
			return map;
		}
	}

	return Zero;
}

char *to_roman(int arabic) {
	if(arabic > MAX_ARABIC_VALUE) {
		return "Resulting value is not valid";
	}

	if(arabic == 0) {
		return "Zero is not a valid roman number";
	}

	if(arabic < 0) {
		return "Negative numbers are not allowed";
	}
	
	char *roman;
	roman = (char *) malloc(15);
	int currentIndex = 0;
	while(arabic != 0) {
		struct RomanArabicMap map = get_roman_arabic_map(arabic);
		arabic = arabic - map.arabic;
		roman[currentIndex++] = map.roman[0];
		if (map.roman[1] != NA) {
			roman[currentIndex++] = map.roman[1];
		}
	}
	roman[currentIndex] = '\0';
	return roman;
}