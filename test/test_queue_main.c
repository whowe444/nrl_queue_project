#include "test_queue.h"

#include "random_str_gen.h"

int
main()
{
    // Seed the random str gen
    init();

    // TEST an empty queue
    test_empty_size();

    // TEST empty dequeue
    test_empty_dequeue();

    // TEST single enqueue
    test_single_enqueue_size();

    // TEST single dequeue
    test_single_dequeue();

    // TEST double enqueue, double dequeue
    test_double_enqueue_double_dequeue();

    // TEST random enqueue / dequeue
    test_random_enqueue_dequeue();

    // TEST random double enqueue / dequeue
    test_random_double_enqueue_double_dequeue();

    // TEST enqueue many elements
    test_enqueue_many_elements();

    // TEST enqueue / dequeue many elements
    test_enqueue_dequeue_many_elements();
}