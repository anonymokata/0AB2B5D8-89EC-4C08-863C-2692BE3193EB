#include <string.h>
#include <stdbool.h>
#include "roman_validator.h"

bool is_roman_valid(const char *roman) {
	int length = strlen(roman);
	int iCount = 0;
	int mCount = 0;
	int xCount = 0;
	for(int i = 0; i < length; ++i) {
		if(roman[i] == 'I') {
			iCount++;
		}

		if(roman[i] == 'M') {
			mCount++;
		}

		if(roman[i] == 'X') {
			xCount++;
		}
	}
	return iCount < 4
		&& mCount < 4
		&& xCount < 4;
}