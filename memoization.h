#include <stdio.h>
#include <stdlib.h>

typedef char* (*char_func_ptr)(long long int param);

char* cache_function(long long int num);

char_func_ptr initialize(char_func_ptr provider);