# NRL Queue Project

## Code Standard
This project follows the Embedded C Coding Standard found [here](https://barrgroup.com/sites/default/files/barr_c_coding_standard_2018.pdf).

## Additional Requirements
1. All source code and files necessary to build shall be provided in a single zip file.
* The only library that you can use is the standard C library. **Per the code standard, I use the C99 ISO Version ✅**
2. Instructions for building the source code shall be provided. **[Here](https://github.com/whowe444/nrl_queue_project/blob/main/README.md#instructions-for-building-the-source-code) ✅**
3. Instructions for running the test benches shall be provided. **[Here](https://github.com/whowe444/nrl_queue_project/blob/main/README.md#instructions-for-running-the-test-benches) ✅**
4. Sufficient documentation shall be provided such that we can implement our own test cases. **[Here]() ✅**


## Instructions for building the source code
```
git clone https://github.com/whowe444/nrl_queue_project.git
cd nrl_queue_project
source source_me
make
```

## Instructions for running the test benches
```
/* Run tests */
./run_tests.sh

/* Run tests with valgrind */
./run_test_with_valgrind.sh

/* Run cppcheck */
cppcheck .
```

## Instructions for adding new test cases

