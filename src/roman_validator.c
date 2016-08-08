#include <string.h>
#include <stdbool.h>
#include "roman_arabic_map.h"
#include "roman_validator.h"

struct RomanLimit {
	char roman;
	int limit;
	int count;
} RomanLimit;

bool is_roman_valid(const char *roman) {
	int length = strlen(roman);
	struct RomanLimit limits[] = {
		{'M', 3, 0},
		{'D', 1, 0},
		{'C', 3, 0},
		{'X', 3, 0},
		{'I', 3, 0}
	};

	int limitSize = sizeof(limits) / sizeof(RomanLimit);

	for(int i = 0; i < length; ++i) {
		for(int j = 0; j < limitSize; ++j) {
			if (limits[j].roman == roman[i]) {
				limits[j].count++;
			}

			if(limits[j].count > limits[j].limit) {
				return false;
			}
		}
	}
	return true;
}