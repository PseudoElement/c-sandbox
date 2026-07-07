#include "include/arrays.h"
#include "build/_deps/collections-c-src/src/include/cc_array.h"
// #include "build/_deps/collections-c-src/src/include/cc_common.h"
#include <stdio.h>
#include <string.h>

char email[] = {"2123123"};
char email2[] = "2313";
char email3[] = {'2', '2', '3', '4', '2'};

int matrix2D[2][3] = {
    {1, 4, 2},
    {3, 6, 8}
};
int matrix3D[2][3][4] = {{{1, 4, 2}}, {{3, 6, 8}}};

int main_arrays() {
    // Create a new array
    // CC_Array *ar;
    // cc_array_new(&ar);

    CC_Array *arWithCap;
    CC_ArrayConf const conf = {.capacity = 3, .exp_factor = (float)(3), .mem_alloc = malloc, .mem_calloc = calloc, .mem_free = free};
    enum cc_stat status = cc_array_new_conf(&conf, &arWithCap);
    if (status != CC_OK) {
        printf("!!!ERROR: %ud\n", status);
        exit(1);
    }
    printf("CAPACITY: %ld\n", cc_array_capacity(arWithCap));
    printf("SIZE: %ld\n", cc_array_size(arWithCap));

    int el = 228;
    cc_array_add(arWithCap, &el);
    int el2 = 329;
    cc_array_add(arWithCap, &el2);
    int el3 = 430;
    cc_array_add(arWithCap, &el3);
    int el4 = 531;
    cc_array_add(arWithCap, &el4);

    for (int i = 0; i < cc_array_size(arWithCap); i++) {
        int *el;
        cc_array_get_at(arWithCap, i, (void *)&el);
        printf("HELLO_DYNAMIC_ARRAY_DATA %d\n", *el);
        printf("CAPACITY: %ld\n", cc_array_capacity(arWithCap));
        printf("SIZE: %ld\n\n", cc_array_size(arWithCap));
    }

    int arr[] = {10, 20, 30, 40};
    int len = ARRAY_LENGTH(arr);

    matrix2D[0][1] = 99;
    matrix3D[0][2][3] = 990;

    printf("SUM_TOTAL: %d\n", *(arr) + arr[2]);

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
