#ifndef NODE_H
#define NODE_H

typedef struct node_struct
{
    const char *p_data;
    struct node_struct* p_next;
} node;

#endif /* NODE_H */
