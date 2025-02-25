#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "memoization.h"

#define MAX_MEMOIZED 150000
#define ARRAY_SIZE (MAX_MEMOIZED + 1)
#define UNINITIALIZED NULL

char_func_ptr original_provider;
char* memoized[ARRAY_SIZE];

char* cache_function(long long int num) {
    if (num < 0 || num > MAX_MEMOIZED) {
        return (*original_provider)(num);
        // original_provider(num, money_text);
        // return;
    }

    if (memoized[num] == UNINITIALIZED) {
        memoized[num] = (*original_provider)(num);
        //snprintf(memoized[num], STRING_SIZE, "%s", (*original_provider)(num));
        printf("Memoizing %lld: %s\n", num, memoized[num]);
        //strncpy(memoized[num], (*original_provider)(num), sizeof(memoized[num]));
    }

    //money_text = memoized[num];
    return strdup(memoized[num]);
}

char_func_ptr initialize(char_func_ptr provider) {
    for (int ix = 0; ix < ARRAY_SIZE; ix++) {
        memoized[ix] = UNINITIALIZED;
    }

    original_provider = provider;
    return cache_function;
}