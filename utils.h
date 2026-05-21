#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>

typedef struct SliceRes {
  bool success;
  char *sliced;
} SliceRes;

// Function prototype
SliceRes SliceString(char value[], int startIdx, int endIdx);

void PrintSliceRes(SliceRes res);

#endif
