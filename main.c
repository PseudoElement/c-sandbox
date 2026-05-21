// #include "ariphmetic.h"
// #include "memory.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    struct SliceRes res = SliceString("Hello, world!", 2, 100);
    PrintSliceRes(res);

    // main_ariphmetic();
    // main_memory();

    int counter = 111;
    float floatCounter = 1.22;
    char symbol = "Z272323"[0];
    int myNum = 25;
    char email[] = "new-user@gmail.com";

    double doubleNum = 19.99;

    myNum++;

    floatCounter += 1.66;
    counter++;

    int x = 5, y = 6, z = 50;
    printf("symbol %c!\n", symbol);
    printf("float %.1f!\n", floatCounter);

    return 0;
}
