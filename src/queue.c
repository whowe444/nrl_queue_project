#include "queue.h"
#include "node_generator.h"

#include <stdlib.h>

typedef struct node_struct
{
    const char *p_data;
    struct node_struct* p_next;
} node;

static int g_size = 0;
static node g_sentinel;
static node* gp_end_of_line = &g_sentinel;

static void reset_end_pointer_if_singleton(node* p_node);

int
enqueue(const char* p_data)
{
    int t_return_val = -1;
    node* p_new_node = generate_node(p_data, NULL);
    if (p_new_node)
    {
        gp_end_of_line->p_next = p_new_node;
        gp_end_of_line = p_new_node;
        g_size++;
        t_return_val = 0;
    }
    return t_return_val;
}

const char*
dequeue()
{
    const char* p_return_str = NULL;
    node* p_return_node = g_sentinel.p_next;
    if (p_return_node)
    {
        reset_end_pointer_if_singleton(p_return_node);
        g_sentinel.p_next = p_return_node->p_next;
        p_return_str = p_return_node->p_data;
        free(p_return_node);

        g_size--;
    }
    return p_return_str;
}

int
size()
{
    return g_size;
}

static void reset_end_pointer_if_singleton(node* p_node)
{
    // handle the special case of size == 1
    if (p_node == gp_end_of_line)
    {
        gp_end_of_line = &g_sentinel;
    }
}