CFLAGS=-Wall -std=c99
CC=gcc
BUILD=build
SOURCE=src
TESTS=tests
all: check

clean:
	rm -r -f $(BUILD)

check: clean run_tests.o roman_arabic_map.o roman_calculator.o roman_to_arabic.o arabic_to_roman.o roman_to_arabic_suite.o arabic_to_roman_suite.o roman_calculator_suite.o
	$(CC) -o $(BUILD)/run_tests $(BUILD)/run_tests.o $(BUILD)/roman_arabic_map.o $(BUILD)/roman_calculator.o $(BUILD)/roman_to_arabic.o $(BUILD)/arabic_to_roman.o $(BUILD)/roman_to_arabic_suite.o $(BUILD)/roman_calculator_suite.o $(BUILD)/arabic_to_roman_suite.o -lcheck -pthread -lcheck_pic -lrt -lm -L./$(BUILD) -lroman_calculator
	$(BUILD)/run_tests

roman_arabic_map.o:
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -c $(SOURCE)/roman_arabic_map.c -o $(BUILD)/roman_arabic_map.o
	ar rcs $(BUILD)/libroman_arabic_map.a $(BUILD)/roman_arabic_map.o

roman_calculator.o: 
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -c $(SOURCE)/roman_calculator.c -o $(BUILD)/roman_calculator.o
	ar rcs $(BUILD)/libroman_calculator.a $(BUILD)/roman_calculator.o

roman_to_arabic.o:
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -c $(SOURCE)/roman_to_arabic.c -o $(BUILD)/roman_to_arabic.o
	ar rcs $(BUILD)/libroman_to_arabic.a $(BUILD)/roman_to_arabic.o

arabic_to_roman.o:
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -c $(SOURCE)/arabic_to_roman.c -o $(BUILD)/arabic_to_roman.o
	ar rcs $(BUILD)/libarabic_to_roman.a $(BUILD)/arabic_to_roman.o

roman_to_arabic_suite.o:
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -c $(TESTS)/roman_to_arabic_suite.c -o $(BUILD)/roman_to_arabic_suite.o

arabic_to_roman_suite.o:
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -c $(TESTS)/arabic_to_roman_suite.c -o $(BUILD)/arabic_to_roman_suite.o

roman_calculator_suite.o:
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -c $(TESTS)/roman_calculator_suite.c -o $(BUILD)/roman_calculator_suite.o


run_tests.o:
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -c $(TESTS)/run_tests.c -o $(BUILD)/run_tests.o