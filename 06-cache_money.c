#include <stdio.h>
#include <stdlib.h>

#include "text_convert.h"
#include "memoization.h"

#define MAX_CENT_AMOUNT 100000000000
#define STRING_SIZE 100

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

        char* money_text = (char *)malloc(sizeof(char) * STRING_SIZE);

        *money_text = '\0';

        //money_text = cents_to_words(cents/*, money_text*/);
        money_text = (*money_to_words)(cents);
        //money_to_words(cents, money_text);

        printf("%s\n", money_text);

        free(money_text);
    }
}
