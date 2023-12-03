#include "test_queue.h"

#include "queue.h"

#include <assert.h>
#include <stdio.h>

void
test_empty_size()
{
    assert(size() == 0);

    printf("TEST test_empty_size(): SUCCESS\n");
}

void
test_empty_dequeue()
{
    assert(dequeue() == NULL);

    assert(size() == 0);

    printf("TEST test_empty_dequeue(): SUCCESS\n");
}

void
test_single_enqueue_size()
{
    assert(enqueue("cat") == 0);

    assert(size() == 1);

    printf("TEST test_single_enqueue_size(): SUCCESS\n");
}
