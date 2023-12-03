#include "test_queue.h"

int
main()
{
    // TEST an empty queue
    test_empty_size();

    // TEST empty dequeue
    test_empty_dequeue();

    // TEST single enqueue
    test_single_enqueue_size();

    // TEST single dequeue
    test_single_dequeue();

}