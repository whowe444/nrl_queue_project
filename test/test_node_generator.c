#include "test_node_generator.h"

#include "node_generator.h"

#include "assert.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node_struct
{
    const char *p_data;
    struct node_struct* p_next;
} node;

void
test_generate_empty_node()
{
    const char* p_null_str = NULL;
    node* p_next = NULL;
    node* p_node = generate_node(p_null_str, p_next);

    assert(p_node->p_data == NULL);
    assert(p_node->p_next == NULL);

    free(p_node);

    printf("TEST test_generate_empty_node(): SUCCESS\n");
}

void
test_generate_empty_str_node()
{
    const char* p_empty_str = "";
    node* p_node = generate_node(p_empty_str, NULL);

    assert(strcmp(p_empty_str, p_node->p_data) == 0);
    assert(p_node->p_next == NULL);

    free(p_node);

    printf("TEST test_generate_empty_str_node(): SUCCESS\n");
}

void
test_generate_node_with_str()
{
    const char* p_str = "cat";
    node* p_node = generate_node(p_str, NULL);

    assert(strcmp(p_str, p_node->p_data) == 0);
    assert(p_node->p_next == NULL);

    free(p_node);

    printf("TEST test_generate_node_with_str(): SUCCESS\n");
}

void
test_generate_node_then_modify()
{
    const char* p_str = "cat";
    node* p_node = generate_node(p_str, NULL);

    p_node->p_data = "dog";

    assert(strcmp(p_str, p_node->p_data) != 0);
    assert(p_node->p_next == NULL);

    free(p_node);

    printf("TEST test_generate_node_then_modify(): SUCCESS\n");
}

void
test_generate_node_with_next()
{
    const char* p_str1 = "cat";
    node* p_node1 = generate_node(p_str1, NULL);

    const char* p_str2 = "dog";
    node* p_node2 = generate_node(p_str2, NULL);

    p_node1->p_next = p_node2;

    assert(p_node1->p_next == p_node2);
    assert(p_node2->p_next == NULL);

    free(p_node1);
    free(p_node2);

    printf("TEST test_generate_node_with_next(): SUCCESS\n");
}

void
test_generate_node_with_next_arg()
{
    const char* p_str1 = "cat";
    node* p_node1 = generate_node(p_str1, NULL);

    const char* p_str2 = "dog";
    node* p_node2 = generate_node(p_str2, p_node1);

    assert(p_node1->p_next == NULL);
    assert(p_node2->p_next == p_node1);

    free(p_node1);
    free(p_node2);

    printf("TEST test_generate_node_with_next_arg(): SUCCESS\n");
}
