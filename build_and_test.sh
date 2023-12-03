#!/bin/sh

# make
make

./run_tests.sh

./run_tests_with_valgrind.sh

cppcheck .




