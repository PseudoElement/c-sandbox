#include "./include/utils.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

SliceRes SliceString(char value[], int startIdx, int endIdx) {
    int len = strlen(value);

    if (startIdx < 0 || startIdx >= endIdx || startIdx >= len) {
        SliceRes res;
        res.success = false;
        res.sliced = malloc(1);
        res.sliced[0] = '\0';
        return res;
    }

    int slicedLen = fmin(len, endIdx - startIdx);
    struct SliceRes result = {.sliced = "", .success = true};
    result.sliced = (char *)malloc(slicedLen + 1);

    short changedCharIdx = 0;
    for (short i = 0; i < endIdx; i++) {
        if (i >= startIdx) {
            result.sliced[changedCharIdx] = value[i];
            changedCharIdx++;
        }
    }

    result.sliced[slicedLen] = '\0';

    printf("slicedLen: %d\n", slicedLen);
    printf("slicedLen size: %zu\n", sizeof(slicedLen));

    return result;
}

void PrintSliceRes(struct SliceRes res) {
    printf("SliceRes:\n");
    printf("Sliced: %s\n", res.sliced);
    printf("Success:  %s\n\n", res.success ? "true" : "false");
}
