#include "includes/pointers.h"
#include <stdio.h>

int main_pointers() {
    int myAge = 43; // an int variable
    int *ptr = &myAge;

    // Outputs the memory address of myAge (0x7ffe5367e044)
    printf("myAge memory addr: %p\n", &myAge);
    printf("myAge value: %d\n", *ptr);

    *ptr += 15;
    printf("myAge memory addr: %p\n", &myAge);
    printf("myAge value: %d\n", *ptr);

    int myNumbers[4] = {25, 50, 75, 100};
    int i;

    printf("first: %p\n", &myNumbers);
    for (i = 0; i < 4; i++) {
        printf("%p\n", &myNumbers[i]);
    }

    printf("&myNumbers[0] == &myNumbers: %d\n",
           (void *)&myNumbers[0] == (void *)&myNumbers);

    int *firstElPtr = &myNumbers[0];
    *myNumbers = 229;

    // Get the value of the second element in myNumbers
    printf("%d\n", *(myNumbers + 1));
    // Get the value of the third element in myNumbers
    printf("%d", *(myNumbers + 2));

    printf("END of main_pointers!\n");

    return 1;
}
