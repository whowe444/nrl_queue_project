#include "random_str_gen.h"

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_NUM 1000
#define NUM_CHARS 4

char g_str[NUM_CHARS+1];

void
init()
{
    srand(MAX_NUM + NUM_CHARS);
}

const char*
generate_random_str()
{
    int t_rand = rand() % MAX_NUM;
    sprintf(g_str, "%d", t_rand);
    return g_str;
}