#include "random_str_gen.h"

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_NUM 10000
#define NUM_CHARS MAX_NUM/10 + 1

char g_str[NUM_CHARS+1];

void
init()
{
    srand(MAX_NUM + NUM_CHARS);
}

char*
generate_random_str()
{
    int t_rand = rand() % MAX_NUM;
    char * p_str = malloc(sizeof(g_str));
    sprintf(p_str, "%d", t_rand);
    return p_str;
}