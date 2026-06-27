#include "include/pointers.h"
#include "include/arrays.h"
#include <stdio.h>
#include <stdlib.h>

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

/**
 * INVALID cause myArr is stored on stack allocated for this function scope
 * and it's cleared when you leave a function block
 */
// int *createArray() {
//     int myArr[5] = {11, 22, 33, 44, 55};
//     return myArr;
// }

DynamicArr mockArray() {
    int myArr[5] = {11, 22, 33, 44, 55};
    int len = ARRAY_LENGTH(myArr);
    int *arr = malloc(len * sizeof(int)); // Allocate on the heap
    for (int i = 0; i < len; i++) {
        arr[i] = myArr[i]; // Populate the array
    }
    DynamicArr res = {.ptr = arr, .size = len};
    return res;
}

int main_pointers() {
    int (*funcs[3])(int, int) = {add, subtract, multiply};
    // funcs[0](22, 3345);

    DynamicArr arr = mockArray();

    // arr
    printf("ARR %d\n", arr.ptr[0]);
    printf("ARR %d\n", arr.ptr[1]);
    printf("ARR %d\n", arr.ptr[2]);
    printf("LEN %d\n", arr.size);

    for (int i = 0; i < arr.size; i++) {
        if (i == arr.size - 1) {
            printf("idx_%d:%d\n\n", i, arr.ptr[i]);
        } else {
            printf("idx_%d:%d\n", i, arr.ptr[i]);
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

    printf("&myNumbers[0] == &myNumbers: %d\n", (void *)&myNumbers[0] == (void *)&myNumbers);

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
