#include "./includes/files.h"
#include "includes/arrays.h"
#include <stdbool.h>
#include <stdio.h>

void main_files(char fileName[]) {
    /* writeonly mode(w+ is read/write) */
    FILE *fptr = fopen(fileName, "w");
    fprintf(fptr, "sintol_borow");
    fprintf(fptr, "\n\nappended text");
    fclose(fptr);

    /* append+read mode */
    fptr = fopen(fileName, "r");

    char myString[5];
    char *hasContent;
    while (hasContent != NULL) {
        hasContent = fgets(myString, ARRAY_LENGTH(myString), fptr);
        printf("myString - %s\t", myString);
    }

    fclose(fptr);
}
