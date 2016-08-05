#include <stdlib.h>
#include <string.h>
#include "roman_arabic_map.h"

char *to_roman(int arabic) {
	char *roman;
	roman = (char *) malloc(1000);
	int currentIndex = 0;
	while(arabic != 0) {
		for(int i = 0; i < get_maps_size(); ++i) {
			struct RomanArabicMap map = roman_arabic_maps[i]; 
			int remainder = arabic - map.arabic; 
			if(remainder >= 0) {
				arabic = remainder;
				roman[currentIndex++] = map.roman[0];
				if (map.roman[1] != NA) {
					roman[currentIndex++] = map.roman[1];
				}
			}
		}
	}
	roman[currentIndex] = '\0';
	return roman;
}