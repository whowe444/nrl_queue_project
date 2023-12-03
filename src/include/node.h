#ifndef NODE_H
#define NODE_H

typedef struct node_struct
{
    const char *data;
    const struct node_struct* next;
} node;

#endif /* NODE_H */
