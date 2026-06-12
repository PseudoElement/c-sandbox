#include "includes/pointers.h"
#include "includes/arrays.h"
#include <stdio.h>

int add(int a, int b) {
    printf("Result: %d\n", a + b);
    return 5;
}
int subtract(int a, int b) {
    printf("Result: %d\n", a - b);
    return 5;
}
int multiply(int a, int b) {
    printf("Result: %d\n", a * b);
    return 5;
}

char *myFunc() {
    int myArr[5] = {11, 22, 33, 44, 55};
    return myArr;
}

int main_pointers() {
    int (*funcs[3])(int, int) = {add, subtract, multiply};
    // funcs[0](22, 3345);

    int *arr = myFunc();
    int len = ARRAY_LENGTH(arr);

    printf("ARR %d", arr[0]);
    printf("ARR %d", arr[1]);
    printf("ARR %d\n", arr[2]);
    printf("LEN %d", len);
    for (int i = 0; i < len; i++) {
        if (i == len - 1) {
            printf("idx_%d:%d\t", i, arr[i]);
        } else {
            printf("idx_%d:%d\n", i, arr[i]);
        }
    }

    int myAge = 43; // an int variable
    int *ptr = &myAge;
    int **pptr = &ptr; // pointer to pointer

    // Outputs the memory address of myAge (0x7ffe5367e044)
    // printf("myAge memory addr: %p\n", &myAge);
    // printf("myAge value: %d\n", *ptr);

    *ptr += 15;
    // printf("myAge memory addr: %p\n", &myAge);
    // printf("myAge value: %d\n", *ptr);

    int myNumbers[4] = {25, 50, 75, 101};
    int i;

    printf("first: %p\n", &myNumbers);
    for (i = 0; i < 4; i++) {
        printf("%p\n", &myNumbers[i]);
    }

    printf("&myNumbers[0] == &myNumbers: %d\n",
           (void *)&myNumbers[0] == (void *)&myNumbers);

    int *firstElPtr = &myNumbers[0];
    *myNumbers = 229;

    /* Get the value of the second element in myNumbers */
    printf("2nd el by_idx: %d\n", myNumbers[1]);
    /* !IMPORTANT implicitly converts char to ascii code:
     * 'z' -> 22
     * '0' -> 48
     * '9' -> 57
     * */
    myNumbers[1] = 'z';
    printf("2nd el by_ptr:  %d\n", *(myNumbers + 1));
    /* Get the value of the third element in myNumbers */
    printf("%d\n", *(myNumbers + 2));

    int *start = &myNumbers[1]; // points to 20
    int *end = &myNumbers[4];   // points to 50
    printf("end: %d\n", *end);
    printf("minus %ld\n", end - start); // returns 3

    printf("END of main_pointers!\n");

    return 1;
}
