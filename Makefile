SHELL = /bin/sh

.SUFFIXES:
.SUFFIXES: .c .o

test : bin/test_driver.o
	g++ -Wall -Wpedantic -o bin/test bin/test_driver.o tests/common.cc \
	tests/sieve_test.cc tests/sort_test.cc sieves/eratosthenes.cc \
	&& ./bin/test

bin/test_driver.o : tests/test_driver.cc
	g++ -c -o bin/test_driver.o tests/test_driver.cc
