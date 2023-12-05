# NRL Queue Project

## Code Standard
This project follows the Embedded C Coding Standard found [here](https://barrgroup.com/sites/default/files/barr_c_coding_standard_2018.pdf).

## Additional Requirements
1. All source code and files necessary to build shall be provided in a single zip file.
2. Instructions for building the source code shall be provided.
3. Instructions for running the test benches shall be provided.
4. Sufficient documentation shall be provided such that we can implement our own test cases.
5. The gcc compiler is used for this project
6. The proper code standard is used.
7. Please deliver code as an attachment to an email
8. The code delivered shall be production ready.


## Instructions for building the source code
```
cd nrl_queue_project
bash
source source_me
make
```
This sequence of commands will run make on both the `src` and `test` directories, thereby building libnrlqueue.so and the test binaries (nrl_test_main, test_node_generator_main, test_queue_main) respectively. `make clean` can be run within `src` and `test` but not from the top level. Each directory can be built individually like so:
```
cd nrl_queue_project
bash
source source_me
cd src
make clean && make
cd ../test
make clean && make
```
This builds everything from scratch.

## Instructions for running the test benches
```
# Run tests
./run_tests.sh

# Run tests with valgrind
./run_test_with_valgrind.sh

# Run cppcheck (if installed)
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

## Documentation
This library provides three public function discusses above in the _Functionality (API) _ section. In order to use the library, include the proper header file (namely queue.h) into your source code file. At that point, you are free to call library functions in your source code. To build the library into your project, be sure to add the library onto your library path (use -L) and link against the library in your Makefile (-lnrlqueue). Examples of this are seen in the `test` directory. Using `-Wl,rpath,<LIBRARY_PATH>` in your Makefile will allow your binary to load the library from the specified library path rather than having to set the `$LD_LIBRARY_PATH` environment variable.

## Strengths and Weaknesses of my Implementation
Strengths:
* using linked list based implementation so can handle a dynamic number of elements and avoids array resizing
* sentinel node plus end of line pointer makes enqueue implementation simple to write
* good modularity and unit testing
* error handling for malloc
* shared object library enables easier patching since I may not need to recompile my binaries if I change my .so
* implementation details of node.h not exposed in any h files

Weaknesses:
* since using linked lists based implementation, must handle memory management and pointer manipulation and loses out on direct access of an array based implementation
* int is implementation dependent (C standard only guarantees a minimum length of 16bits) limiting queue length
* pointers are frequently prone to error, hence I should be using a smart pointer implementation to reduce risk and automate memory management
* node_generator.h is exposed to the client. this was mostly since I wanted to unit test it in its own module and I use it in both the queue and
the test code
