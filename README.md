# Roman Numeral Kata

## Problem
How can we add and subtract roman numeral numbers?

## Overview
Roman numeral values are defined as:
`I  = 1`
`IV = 4`
`V  = 5`
`IX = 9`
`X  = 10`
`XL = 40`
`L  = 50`
`XC = 90`
`C  = 100`
`CD = 400`
`D  = 500`
`CM = 900`
`M  = 1000`

Some rules when adding or subtracting roman numerals are:
	1.) I, X, and C may not appear more than three times. (`II + II is not IIII`, instead `II + II is IV`)
	2.) V, L , and D my only appear once. (`D + D is not DD`, instead `D + D is M`)
	3.) The max roman numeral is `3999` (`MMMCMXCIX`)

## Examples
Some examples of addtion and subraction cases are below:

### Addition
`III + I = IV`
`IX + I = X`

### Subtraction
`IV - I = III`
`C - I = XCIX`