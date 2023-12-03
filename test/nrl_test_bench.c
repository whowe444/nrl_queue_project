#include "nrl_test_bench.h"

#include "queue.h"

#include<stdio.h>

#define NUM_DATA 10
const char* g_data[NUM_DATA];

void
init_data()
{
    g_data[0] = "1111-1111";
    g_data[1] = "When you invoke GCC, it normally does preprocessing, \
                compilation";
    g_data[2] = "assembly and linking. The overall options allow";
    g_data[3] = "the gcc program accepts options and file name";
    g_data[4] = "Many options have long names starting with \
        -f or with -W---for";
    g_data[5] = "language, you can use that options with all supported langu";
    g_data[6] = "not to run the linker. The";
    g_data[7] = "k";
    g_data[8] = "9999";
    g_data[9] =       "0";
}

void
run_nrl_test_bench()
{
    // 1. Print the number of elements in the queue
    printf("Size: %d\n", size());

    // 2. Add Test Data 1 to the queue
    enqueue(g_data[0]);

    // 3. Print the number of elements in the queue
    printf("Size: %d\n", size());

    // 4. Remove element from the queue. Print element removed.
    printf("Removed element: %s\n", dequeue());

    // 5. Try to remove element from queue. Print status of attempt
    // to remove element. If element removed print removed element;
    const char* p_removed_element = dequeue();
    if (p_removed_element)
    {
        printf("Removed element: %s\n", p_removed_element);
    }
    else
    {
        printf("Attempted to remove element, but no element found.\n");
    }

    // 6. Add all 10 Test Data elements to the queue
    for (int t_index = 0; t_index < NUM_DATA; t_index++)
    {
        enqueue(g_data[t_index]);
    }

    // 7. Print the number of elements in the queue
    printf("Size: %d\n", size());

    // 8. Remove an element from the queue
    p_removed_element = dequeue();

    // 9. Print element removed
    printf("Removed element: %s\n", p_removed_element);

    // 10. Print number of elements in the queue
    printf("Size: %d\n", size());

    // 11. Continue removing and printing
    // elements from the queue until none remain
    while (size() > 0)
    {
        printf("Removed element: %s\n", dequeue());
    }
}