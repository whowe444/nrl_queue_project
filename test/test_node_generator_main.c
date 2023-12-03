#include "test_node_generator.h"

int
main()
{
    // TEST empty node
    test_generate_empty_node();

    // TEST empty str as data
    test_generate_empty_str_node();

    // TEST non-empty str as data
    test_generate_node_with_str();

    // TEST generate node then modify
    test_generate_node_then_modify();

    // TEST node with next
    test_generate_node_with_next();

    //TEST next argument
    test_generate_node_with_next_arg();
}