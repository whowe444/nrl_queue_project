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
}