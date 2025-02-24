#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
//#include <math.h>

#include "text_convert.h"

#define STRING_SIZE 100

const char ones[10][10] = { "one ", "two ", "three ", "four ", "five ", "six ",
    "seven ", "eight ", "nine " };
const char teens[10][20] = { "ten ", "eleven ", "twelve ", "thirteen ", "fourteen ",
    "fifteen ", "sixteen ", "seventeen ", "eighteen ",
    "nineteen " };
const char tens[10][10] = {"twenty ", "thirty ", "forty ", "fifty ", "sixty ",
    "seventy ", "eighty ", "ninety " };

void concat(char* s1, const char* s2) {
    memcpy(s1 + strlen(s1), s2, strlen(s2) + 1);
}

// Calculate the tens place, and whether it is a teen number
// Or a number in the twenties, thirties, etc.
void tens_place(long long dollars, char* money_text) {
    if (dollars >= 10 && dollars < 20) {
        concat(money_text, teens[dollars % 10]);
    } else {
        concat(money_text, tens[dollars / 10 - 2]);
    }
}

// Goes through each digit of the number (dollars) and determines
// the word associated with that digit
void digits_switch(int digits, long long dollars, char* money_text) {
    int add_million = 0;
    int add_thousand = 0;

    while (digits > 0) {
        if (dollars / pow(10, digits - 1) != 0) {
            switch (digits) {
                case 1:     // ones
                    concat(money_text, ones[dollars - 1]);
                    break;
                case 2:     // tens
                    tens_place(dollars, money_text);

                    if (dollars >= 10 && dollars < 20)
                        digits--;
                    break;
                case 3:     // hundreds
                    concat(money_text, ones[dollars / 100 - 1]);
                    if (dollars % 100 != 0)
                        concat(money_text, "hundred ");
                    break;
                case 4:     // thousands
                    concat(money_text, ones[dollars / 1000 - 1]);
                    add_thousand = 1;
                    //concat(money_text, "thousand ");
                    break;
                case 5:     // ten thousands
                    tens_place(dollars / 1000, money_text);

                    // 1000? 10000?
                    if (dollars / 1000 >= 10 && dollars / 1000 < 20) {
                        //concat(money_text, "thousand ");
                        add_thousand = 1;
                        digits--;
                    }
                    break;
                case 6:     // hundred thousands
                    concat(money_text, ones[dollars / 100000 - 1]);
                    concat(money_text, "hundred ");
                    add_thousand = 1;
                    break;
                case 7:     // millions
                    concat(money_text, ones[dollars / 1000000 - 1]);
                    //concat(money_text, "million ");
                    add_million = 1;
                    break;
                case 8:     // ten millions
                    tens_place(dollars / 1000000, money_text);

                    if (dollars / 1000000 >= 10 && dollars / 1000000 < 20) {
                        //concat(money_text, "million ");
                        add_million = 1;
                        digits--;
                    }
                    break;
                case 9:     // hundred millions
                    concat(money_text, ones[dollars / 100000000 - 1]);
                    concat(money_text, "hundred ");
                    add_million = 1;
                    break;
            }
        }

        if (digits <= 4 && add_thousand == 1)
        {
            concat(money_text, "thousand ");
            add_thousand = 0;
        }

        if (digits <= 7 && add_million == 1)
        {
            concat(money_text, "million ");
            add_million = 0;
        }

        digits--;

        long long decrease_digits = pow(10, digits);

        dollars %= decrease_digits;
    }
}

void calculate_cents(long long cents, char* money_text) {
    if (cents < 10) {
        concat(money_text, ones[cents - 1]);
    }
    else if (cents < 20) {
        concat(money_text, teens[cents % 10]);
    } else {
        concat(money_text, tens[cents / 10 - 2]);
        concat(money_text, ones[cents % 10 - 1]);
    }

    if (cents == 1)
        concat(money_text, "cent");
    else
        concat(money_text, "cents");
}

char* cents_to_words(long long cents) {
    char* money_text = (char *)malloc(sizeof(char) * STRING_SIZE);

    *money_text = '\0';

    if (cents == 0) {
        concat(money_text, "zero dollars");
        return money_text;
        //return;
    }

    if (cents < 100) {
        calculate_cents(cents, money_text);
        return money_text;
        //return;
    }

    int digits = 0;  // number of digits cents is comprised of

    long long dollars = cents / 100;

    // Find out how many digits are in cents
    while (dollars > 0) {
        dollars /= 10;
        digits++;
    }

    dollars = cents / 100;

    // printf("Digits: %d\n", digits);

    // Call helper function or use a while loop, and use digits to determine placement

    digits_switch(digits, dollars, money_text);

    if (dollars == 1)
        concat(money_text, "dollar");
    else
        concat(money_text, "dollars");

    // Calculating the remaining cents
    cents = cents % 100;

    if (cents != 0) {
        concat(money_text, " and ");
        calculate_cents(cents, money_text);
    }
    
    return money_text;
}