#include "test_queue.h"

#include "queue.h"
#include "random_str_gen.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM_ELEMENTS 1000000

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

void
test_single_dequeue()
{
    const char* p_str = "cat";

    assert(strcmp(dequeue(), p_str) == 0);

    assert(size() == 0);

    printf("TEST test_single_dequeue(): SUCCESS\n");
}

void
test_double_enqueue_double_dequeue()
{
    assert(enqueue("cat") == 0);
    assert(enqueue("dog") == 0);
    assert(size() == 2);

    assert(strcmp(dequeue(), "cat") == 0);
    assert(size() == 1);

    assert(strcmp(dequeue(), "dog") == 0);
    assert(size() == 0);

    assert(dequeue() == NULL);

    printf("TEST test_double_enqueue_double_dequeue(): SUCCESS\n");
}

void
test_random_enqueue_dequeue()
{
    char* p_str = generate_random_str();

    assert(enqueue(p_str) == 0);
    assert(size() == 1);

    assert(strcmp(dequeue(), p_str) == 0);
    assert(size() == 0);

    free(p_str);

    printf("TEST test_random_enqueue_dequeue(): SUCCESS\n");
}

void
test_random_double_enqueue_double_dequeue()
{
    char* p_str1 = generate_random_str();
    assert(enqueue(p_str1) == 0);
    assert(size() == 1);

    char* p_str2 = generate_random_str();
    assert(enqueue(p_str2) == 0);
    assert(size() == 2);

    assert(strcmp(dequeue(), p_str1) == 0);
    assert(size() == 1);

    assert(strcmp(dequeue(), p_str2) == 0);
    assert(size() == 0);

    free(p_str1);
    free(p_str2);

    printf("TEST test_random_double_enqueue_double_dequeue(): SUCCESS\n");
}

void
test_enqueue_many_elements()
{
    char* t_elements[NUM_ELEMENTS];

    for (int t_index = 0; t_index < NUM_ELEMENTS; t_index++)
    {
        t_elements[t_index] = generate_random_str();
        assert(size() == t_index);
        assert(enqueue(t_elements[t_index]) == 0);
    }
    assert(size() == NUM_ELEMENTS);

    //cleanup
    for (int t_index = 0; t_index < NUM_ELEMENTS; t_index++)
    {
        dequeue();
        free(t_elements[NUM_ELEMENTS -1 - t_index]);
    }

    assert(size() == 0);

    printf("TEST test_enqueue_many_elements(): SUCCESS\n");
}

void
test_enqueue_dequeue_many_elements()
{
    char* t_elements[NUM_ELEMENTS];

    for (int t_index = 0; t_index < NUM_ELEMENTS; t_index++)
    {
        t_elements[t_index] = generate_random_str();
        assert(size() == t_index);
        assert(enqueue(t_elements[t_index]) == 0);
    }

    assert(size() == NUM_ELEMENTS);

    for (int t_index = 0; t_index < NUM_ELEMENTS; t_index++)
    {
        assert(strcmp(dequeue(), t_elements[t_index]) == 0);
        free(t_elements[t_index]);
    }

    assert(size() == 0);

    printf("TEST test_enqueue_dequeue_many_elements(): SUCCESS\n");
}
