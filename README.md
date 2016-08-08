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