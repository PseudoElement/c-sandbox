#include "./includes/ariphmetic.h"
#include <stdbool.h>
#include <stdio.h>

const int TIER_1 = 11;
const int TIER_2 = 12;

typedef enum Tier {
    FIRST,
    SECOND,
} Tier;

int main_ariphmetic() {
    double dVal = 10.0;
    float fVal = 10.0;
    bool loggedIn = false; // in printf returned as %d
    // printf("boolean %d\n", loggedIn);

    int x = 228, y = 999;
    x ^= y;
    y ^= x;
    x ^= y;
    // it swaps x<->y
    // printf("more or less %d\n", (x > y) == true);
    // printf("double %zu\n", sizeof(dVal));
    // printf("float size %zu\n", sizeof(fVal));

    my_int userScore = 100;
    int maxScore = 500;
    float percentage = (float)userScore / maxScore * 100.0;
    // printf("percentage is %.1f%c.\n", percentage, '%');

    if (!1) {
        // printf("preincrement %d\n", z++ + z++); // 11
    } else {
        // printf("preincrement %d\n", ++z + ++z); // 13
    }

    // you can cast any integer type for switch(expression)
    enum Tier tier = FIRST;
    Tier tierWithoutKeyWord = FIRST;

    switch (tier) {
    case FIRST:
        printf("FIRST callded\n");
        break;
    case SECOND:
        printf("SECOND callded\n");
        break;
    default:
        printf("default callded\n");
    }

    printf("END OF main_ariphmetic\n\n");

    return 0;
}
