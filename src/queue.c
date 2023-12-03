#include "queue.h"

#include "node_generator.h"

#include <stdlib.h>

static int g_size = 0;

static node g_sentinel;
static node* g_first = &g_sentinel;

int
enqueue(const char* a_data)
{
    node* t_new_node = generate_node(a_data, NULL);

    if (!t_new_node)
    {
        return -1;
    }

    g_first->next = t_new_node;
    g_first = t_new_node;

    g_size++;

    return 0;
}

int
size()
{
    return g_size;
}