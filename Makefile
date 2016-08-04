CFLAGS=-Wall -std=c99
CC=gcc
BUILD=build
SOURCE=src
TESTS=tests

all: check

clean:
	rm -r -f $(BUILD)

check: clean roman_calculator_tests.o roman_calculator.o
	$(CC) -o $(BUILD)/tests $(BUILD)/roman_calculator_tests.o -lcheck -pthread -lcheck_pic -lrt -lm -L./$(BUILD) -lroman_calculator
	$(BUILD)/tests

roman_calculator.o: 
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -c $(SOURCE)/roman_calculator.c -o $(BUILD)/roman_calculator.o
	ar rcs $(BUILD)/libroman_calculator.a $(BUILD)/roman_calculator.o

roman_calculator_tests.o:
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -c $(TESTS)/roman_calculator_tests.c -o $(BUILD)/roman_calculator_tests.o