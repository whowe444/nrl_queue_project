#ifndef NODE_GENERATOR_H
#define NODE_GENERATOR_H

typedef struct node_struct node;

node*
generate_node(const char *p_data, node* p_next);

#endif /* NODE_GENERATOR_H */
