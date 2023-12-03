#include "test_queue.h"

#include <assert.h>
#include <stdio.h>

void
test_empty_size()
{
    assert(size() == 0);

    printf("TEST test_empty_size(): SUCCESS\n");
}