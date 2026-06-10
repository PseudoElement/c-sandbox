#include "includes/arrays.h"
#include <stdio.h>
#include <string.h>

char email[] = {"2123123"};
char email2[] = "2313";
char email3[] = {'2', '2', '3', '4', '2'};

int matrix2D[2][3] = {{1, 4, 2}, {3, 6, 8}};
int matrix3D[2][3][4] = {{{1, 4, 2}}, {{3, 6, 8}}};

int main_arrays() {
    int arr[] = {10, 20, 30, 40};
    int len = ARRAY_LENGTH(arr);

    matrix2D[0][1] = 99;
    matrix3D[0][2][3] = 990;

    printf("arr size -> %zu\n", sizeof(arr));

    printf("email -> %s\n", email);
    printf("email2 - > %s\n", email2);
    printf("email3 - > %s\n", email3);
    printf("Array length is %d.\n", len);

    char str1[13] = "Hello ";
    char str2[] = "World!";

    printf("ziseof: %zu\n", sizeof(str1));
    printf("len: %zu\n", strlen(str1));
    // Concatenate str2 to str1 (result is stored in str1)
    strcat(str1, str2);
    // Print str1
    printf("Concatenated: %s\n", str1);

    printf("END OF main_arrays\n\n");

    return 0;
}

int terminal_inputs() {
    char str[10];

    /**
     * сканирует строку до первого пробела или любого \n, \t
     */
    // printf("Enter a string with spaces: ");
    // scanf(" %9[^\n]", str);
    // printf("You entered: %s\n", str);

    printf("Enter a string with spaces 2: ");
    // сканирует строку с пробелами
    fgets(str, sizeof(str), stdin);
    printf("You entered: %s\n", str);

    return 0;
}
