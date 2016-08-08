# Roman Numeral Kata

## Problem
How can we add and subtract roman numeral numbers?

## Overview
Roman numeral values are defined as: <br/>
`I  = 1`<br/>
`IV = 4`<br/>
`V  = 5`<br/>
`IX = 9`<br/>
`X  = 10`<br/>
`XL = 40`<br/>
`L  = 50`<br/>
`XC = 90`<br/>
`C  = 100`<br/>
`CD = 400`<br/>
`D  = 500`<br/>
`CM = 900`<br/>
`M  = 1000`<br/>

Some rules when adding or subtracting roman numerals are:<br/>
	1.) I, X, C, and M may not appear more than three times. (`II + II is not IIII`, instead `II + II is IV`)<br/>
	2.) V, L, and D my only appear once. (`D + D is not DD`, instead `D + D is M`)<br/>
	3.) The max roman numeral is `3999` (`MMMCMXCIX`)<br/>

## Examples
Some examples of addtion and subraction cases are below:

### Addition
`III + I = IV`<br/>
`IX + I = X`<br/>

### Subtraction
`IV - I = III`<br/>
`C - I = XCIX`<br/>

## Error Codes
This library will return error codes in the `errno` value. The error codes can be found in the [roman_error_codes.h](src/roman_error_codes.h) and [roman_error_codes.c](src/roman_error_codes.c). The meaning of each is also denoted below:<br/>
|Name 					 | Value | Description																				|
|------------------------|-------|------------------------------------------------------------------------------------------|
|ROMAN_NUMERAL_LIMIT     | 4 	 | The input contained too many of one character, for instance XXXX would have too many X's |
|NEGATIVE_RESULT 		 | 5 	 | The input provided would result in a negative roman numeral which is invalid 			| 
|ROMAN_NUMERAL_TOO_LARGE | 6 	 | The input provided would result in a roman numeral wich is larger than 3999				|