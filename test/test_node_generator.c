#include "test_node_generator.h"

#include "assert.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void
test_generate_empty_node()
{
    const char* t_null_str = NULL;
    node* t_node = generate_node(t_null_str);

    assert(t_node->data == NULL);
    assert(t_node->next == NULL);

    printf("TEST test_generate_empty_node(): SUCCESS\n");
}

void
test_generate_empty_str_node()
{
    const char* t_empty_str = "";
    node* t_node = generate_node(t_empty_str);

    assert(strcmp(t_empty_str, t_node->data) == 0);
    assert(t_node->next == NULL);

    printf("TEST test_generate_empty_str_node(): SUCCESS\n");
}

void
test_generate_node_with_str()
{
    const char* t_str = "cat";
    node* t_node = generate_node(t_str);

    assert(strcmp(t_str, t_node->data) == 0);
    assert(t_node->next == NULL);
    printf("TEST test_generate_node_with_str(): SUCCESS\n");
}