#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void concat(char* s1, const char* s2);

// Calculate the tens place, and whether it is a teen number
// Or a number in the twenties, thirties, etc.
void tens_place(long long dollars, char* money_text);

void calculate_cents(long long cents, char* money_text);

// Goes through each digit of the number (dollars) and determines
// the word associated with that digit
void digits_switch(int digits, long long dollars, char* money_text);

char* cents_to_words(long long cents);

