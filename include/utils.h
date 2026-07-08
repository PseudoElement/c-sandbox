#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>

/**
 * MACRO
 */
#define ARRAY_LENGTH(x) ((int)(sizeof(x) / sizeof((x)[0])))

typedef struct SliceRes {
    bool success;
    char *sliced;
} SliceRes;

// Function prototype
SliceRes SliceString(char value[], int startIdx, int endIdx);

void PrintSliceRes(SliceRes res);

void main_utils();

typedef enum { INTEGER, STRING, BOOLEAN, CHARACTER } VarType;

typedef struct {
    bool success;
    int len;
    int cap;
    char *ptr;
} DynamicString;

typedef struct {
    VarType type;
    /**
     * initialized only value equals to providen `VarType`
     */
    union {
        int intValue;
        char charValue;
        bool boolValue;
        char *stringValue;
    } value;
} DynamicArrayItem;

typedef struct {
    int len;
    int cap;
    DynamicArrayItem *ptr;
} DynamicArray;

#endif
