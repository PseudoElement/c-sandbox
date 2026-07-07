#include "./include/files.h"
#include "include/arrays.h"
#include <stdbool.h>
#include <stdio.h>

void main_files(char fileName[]) {
    /* writeonly mode(w+ is read/write) */
    FILE *fptr = fopen(fileName, "w+");
    fprintf(fptr, "appended text\n\n");
    fprintf(fptr, "more added text");

    /* change opened file mode from writing to reading without reopening  */
    // rewind(fptr);
    fseek(fptr, 0, SEEK_SET);
    // fseek(fptr, 100, SEEK_END);

    char myString[10];
    while (fgets(myString, ARRAY_LENGTH(myString), fptr)) {
        printf("myString - %s\n", myString);
    }

    fclose(fptr);
}
