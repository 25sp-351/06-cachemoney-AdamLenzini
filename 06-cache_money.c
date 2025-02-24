#include <stdio.h>
#include <stdlib.h>

#include "text_convert.h"

// Caching
typedef char* (*char_func_ptr)(long long int param);

#define MAX_CENT_AMOUNT 100000000000
#define MAX_MEMOIZED 150000
#define ARRAY_SIZE (MAX_MEMOIZED + 1)
#define UNINITIALIZED NULL
#define STRING_SIZE 100

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
    return memoized[num];
}

char_func_ptr initialize(char_func_ptr provider) {
    for (int ix = 0; ix < ARRAY_SIZE; ix++) {
        memoized[ix] = UNINITIALIZED;
    }

    original_provider = provider;
    return cache_function;
}

int main(int argc, char **argv) {
    long long cents = 0;

    char_func_ptr money_to_words = initialize(cents_to_words);

    printf("Please enter the amount of cents you have. Enter EOF to quit\n"); 
    while (!feof(stdin)) {
        if(1 != fscanf_s(stdin, "%lld", &cents))
            break; 
        //printf("You have %lld cents\n", cents);

        if (cents < 0 || cents >= MAX_CENT_AMOUNT) {
            printf("Cent amount must be positive and less than 1 billion ");
            printf("dollars worth. Please try again\n");
            continue;
        }

        // ProviderFunction money_to_words = cents_to_words;

        // Cache *cache = NULL;

        // cache = load_cache_module;

        char* money_text = (char *)malloc(sizeof(char) * STRING_SIZE);

        *money_text = '\0';

        //money_text = cents_to_words(cents/*, money_text*/);
        money_text = money_to_words(cents);
        //money_to_words(cents, money_text);

        printf("%s\n", money_text);

        free(money_text);
    }
}