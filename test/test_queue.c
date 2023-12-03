#include "test_queue.h"

#include "queue.h"
#include "random_str_gen.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    const char* t_str = "cat";

    assert(strcmp(dequeue(), t_str) == 0);

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
    char* t_str = generate_random_str();

    assert(enqueue(t_str) == 0);
    assert(size() == 1);

    assert(strcmp(dequeue(), t_str) == 0);
    assert(size() == 0);

    free(t_str);

    printf("TEST test_random_enqueue_dequeue(): SUCCESS\n");
}

void
test_random_double_enqueue_double_dequeue()
{
    char* t_str1 = generate_random_str();
    assert(enqueue(t_str1) == 0);
    assert(size() == 1);

    char* t_str2 = generate_random_str();
    assert(enqueue(t_str2) == 0);
    assert(size() == 2);

    assert(strcmp(dequeue(), t_str1) == 0);
    assert(size() == 1);

    assert(strcmp(dequeue(), t_str2) == 0);
    assert(size() == 0);

    free(t_str1);
    free(t_str2);

    printf("TEST test_random_double_enqueue_double_dequeue(): SUCCESS\n");
}

void
test_enqueue_many_elements()
{
    const int t_num_elements = 1000000;
    char* t_elements[t_num_elements];

    for (int i = 0; i < t_num_elements; i++)
    {
        t_elements[i] = generate_random_str();
        assert(size() == i);
        assert(enqueue(t_elements[i]) == 0);
    }
    assert(size() == t_num_elements);

    //cleanup
    for (int i = 0; i < t_num_elements; i++)
    {
        dequeue();
        free(t_elements[t_num_elements -1 - i]);
    }

    assert(size() == 0);

    printf("TEST test_enqueue_many_elements(): SUCCESS\n");
}

void
test_enqueue_dequeue_many_elements()
{
    const int t_num_elements = 1000000;
    char* t_elements[t_num_elements];

    for (int i = 0; i < t_num_elements; i++)
    {
        t_elements[i] = generate_random_str();
        assert(size() == i);
        assert(enqueue(t_elements[i]) == 0);
    }

    assert(size() == t_num_elements);

    for (int i = 0; i < t_num_elements; i++)
    {
        assert(strcmp(dequeue(), t_elements[i]) == 0);
        free(t_elements[i]);
    }

    assert(size() == 0);

    printf("TEST test_enqueue_dequeue_many_elements(): SUCCESS\n");
}
