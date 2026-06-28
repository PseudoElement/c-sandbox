// #include "./include/ariphmetic.h"
// #include "./include/memory.h"
// #include "./include/loops.h"
#include "./include/utils.h"
// #include "include/arrays.h"
// #include "include/files.h"
#include "include/functions.h"
// #include "include/pointers.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    main_funcs();
    // main_files("new_text_file.txt");
    // main_pointers();
    // terminal_inputs();
    // main_arrays();
    // main_arrays();
    // main_loops(-3);
    // main_ariphmetic();
    // main_memory();

    struct SliceRes res = SliceString("Hello, world!", 2, 100);
    // PrintSliceRes(res);

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
    // printf("symbol %c!\n", symbol);
    // printf("float %.1f!\n", floatCounter);

    return 0;
}
