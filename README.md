# NRL Queue Project

## Code Standard
This project follows the Embedded C Coding Standard found [here](https://barrgroup.com/sites/default/files/barr_c_coding_standard_2018.pdf).

## Additional Requirements
1. All source code and files necessary to build shall be provided in a single zip file.
* The only library that you can use is the standard C library. **Per the code standard, I use the C99 ISO Version ✅**
2. Instructions for building the source code shall be provided. **[Here](https://github.com/whowe444/nrl_queue_project/blob/main/README.md#instructions-for-building-the-source-code) ✅**
3. Instructions for running the test benches shall be provided. **[Here](https://github.com/whowe444/nrl_queue_project/blob/main/README.md#instructions-for-running-the-test-benches) ✅**
4. Sufficient documentation shall be provided such that we can implement our own test cases. **[Here](https://github.com/whowe444/nrl_queue_project/blob/main/README.md#instructions-for-adding-new-test-cases) ✅**
5. The gcc compiler is used for this project ✅
6. The proper code standard is used. See **[here](https://github.com/whowe444/nrl_queue_project/blob/main/README.md#Code-Standard).**
7. Please deliver code as an attachment to an email ✅
8. The code delivered shall be production ready. Defined [here](https://github.com/whowe444/nrl_queue_project/blob/main/README.md#Production-Ready).


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
* New test cases can easily be added in `test/include/test_queue.h` and implemented in `test/test_queue.c`. These already include several additional test cases of my own as well as a random string generator for ease of testing many elements.
* Don't forget to call your new function in `test/test_queue_main.c`.

## Production Ready
For the purposes of this project, I define production ready as:
* Adheres to the specified code standard
* Modular code that is fully unit tested
* Code is checked for memory leaks with valgrind
* Code is checked with cppcheck
* Code compiles without warning

## Functionality (API)
The API for this queue consists of:
* `int enqueue(const char* a_data); // Adds a new string to the queue.`
* `const char* dequeue(); // Remove the first in line at the queue.`
* `int size(); // Returns the current number of elements in the queue.`

Benefits of this API include
* const data so that the caller should not expect their data to be modified
* queue handles memory management
* caller must handle memory management for their data

## Strengths and Weakness of my Implementation
Strengths:
* using linked list based implementation so can handle a dynamic number of elements and avoids array resizing
* sentinel node plus first in line pointer makes enqueue implementation simple to write
* good modularity and unit testing
* error handling for malloc
* shared object library enables easier patching since I may not need to recompile my binaries if I change my .so

Weaknesses:
* since using linked lists based implementation, must handle memory management and pointer manipulation and loses out on direct access of an array based implementation
* int is implementation dependent (C standard only guarantees a minimum length of 16bits) limiting queue length
* pointers are frequently prone to error, hence I should be using a smart pointer implementation to reduce risk and automate memory management
