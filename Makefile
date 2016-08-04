build: clean	
	mkdir -p build
	gcc -o build/roman_calculator_test.o tests/roman_calculator_test.c

check: build
	gcc -o build/tests -c build/roman_calculator_test.o -lm -lcheck

clean: 
	rm -r -f build