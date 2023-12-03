#include "test_node_generator.h"

#include "node_generator.h"

#include "assert.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void
test_generate_empty_node()
{
    const char* t_null_str = NULL;
    node* t_next = NULL;
    node* t_node = generate_node(t_null_str, t_next);

    assert(t_node->data == NULL);
    assert(t_node->next == NULL);

    free(t_node);

    printf("TEST test_generate_empty_node(): SUCCESS\n");
}

void
test_generate_empty_str_node()
{
    const char* t_empty_str = "";
    node* t_node = generate_node(t_empty_str, NULL);

    assert(strcmp(t_empty_str, t_node->data) == 0);
    assert(t_node->next == NULL);

    free(t_node);

    printf("TEST test_generate_empty_str_node(): SUCCESS\n");
}

void
test_generate_node_with_str()
{
    const char* t_str = "cat";
    node* t_node = generate_node(t_str, NULL);

    assert(strcmp(t_str, t_node->data) == 0);
    assert(t_node->next == NULL);

    free(t_node);

    printf("TEST test_generate_node_with_str(): SUCCESS\n");
}

void
test_generate_node_then_modify()
{
    const char* t_str = "cat";
    node* t_node = generate_node(t_str, NULL);

    t_node->data = "dog";

    assert(strcmp(t_str, t_node->data) != 0);
    assert(t_node->next == NULL);

    free(t_node);

    printf("TEST test_generate_node_then_modify(): SUCCESS\n");
}

void
test_generate_node_with_next()
{
    const char* t_str1 = "cat";
    node* t_node1 = generate_node(t_str1, NULL);

    const char* t_str2 = "dog";
    node* t_node2 = generate_node(t_str2, NULL);

    t_node1->next = t_node2;

    assert(t_node1->next == t_node2);
    assert(t_node2->next == NULL);

    free(t_node1);
    free(t_node2);

    printf("TEST test_generate_node_with_next(): SUCCESS\n");
}

void
test_generate_node_with_next_arg()
{
    const char* t_str1 = "cat";
    node* t_node1 = generate_node(t_str1, NULL);

    const char* t_str2 = "dog";
    node* t_node2 = generate_node(t_str2, t_node1);

    assert(t_node1->next == NULL);
    assert(t_node2->next == t_node1);

    free(t_node1);
    free(t_node2);

    printf("TEST test_generate_node_with_next_arg(): SUCCESS\n");
}
