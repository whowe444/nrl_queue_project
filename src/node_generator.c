#include "node_generator.h"

#include <stdio.h>
#include <stdlib.h>

node*
generate_node(const char *p_data, node* p_next)
{
    node* p_return = NULL;
    p_return = malloc(sizeof(node));
    if (p_return)
    {
        p_return->p_data = p_data;
        p_return->p_next = p_next;
    }
    else
    {
        fprintf(stderr, "Memory allocation failure.");
    }
    return p_return;
}