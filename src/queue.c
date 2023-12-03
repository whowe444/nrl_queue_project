#include "queue.h"
#include "node_generator.h"

#include <stdlib.h>

static int g_size = 0;
static node g_sentinel;
static node* gp_end_of_line = &g_sentinel;

int
enqueue(const char* a_data)
{
    int t_return_val = -1;
    node* t_new_node = generate_node(a_data, NULL);
    if (t_new_node)
    {
        gp_end_of_line->next = t_new_node;
        gp_end_of_line = t_new_node;
        g_size++;
        t_return_val = 0;
    }
    return t_return_val;
}

const char*
dequeue()
{
    const char* t_return_str = NULL;
    node* t_return_node = g_sentinel.next;
    if (t_return_node)
    {
        // handle the special case of size == 1
        if (t_return_node == gp_end_of_line)
        {
            gp_end_of_line = &g_sentinel;
        }

        g_sentinel.next = t_return_node->next;
        t_return_str = t_return_node->data;
        free(t_return_node);

        g_size--;
    }
    return t_return_str;
}

int
size()
{
    return g_size;
}