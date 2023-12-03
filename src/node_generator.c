#include <stdio.h>
#include <stdlib.h>

#include "node_generator.h"

node*
generate_node(const char *a_data, node* a_next)
{
    node* t_return = NULL;
    t_return = malloc(sizeof(node));
    if (t_return)
    {
        t_return->data = a_data;
        t_return->next = a_next;
    }
    else
    {
        fprintf(stderr, "Memory allocation failure.");
    }
    return t_return;
}
