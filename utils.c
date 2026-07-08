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

/*------------------------------------------STRINGS----------------------------------------------*/

DynamicString dynamic_string(char initialValue[]) {
    DynamicString res;
    res.len = strlen(initialValue);
    res.cap = strlen(initialValue) * 2;
    res.ptr = (char *)malloc(res.cap * sizeof(char));
    if (res.ptr == NULL) {
        printf("[ERROR:dynamic_string] malloc failed.\n");
        exit(1);
    }

    strcpy(res.ptr, initialValue);
    res.success = true;

    return res;
}

/**
 * @HINT
 * (*dynamicString).len == dynamicString->len
 */
void append_to_string(DynamicString *dynamicString, char *appendedValue) {
    int appendedSize = 0;
    for (int i = 0; appendedValue[i] != '\0'; i++) {
        char ch = appendedValue[i];
        appendedSize++;
    }
    if (appendedSize + dynamicString->len <= dynamicString->cap) {
        strcat(dynamicString->ptr, appendedValue);
        dynamicString->len += appendedSize;
    } else {
        int newLen = (dynamicString->len + appendedSize);
        int newCap = newLen * 2;
        char *newPtr = realloc(dynamicString->ptr, newCap * sizeof(char));
        if (newPtr == NULL) {
            printf("[ERROR:append_to_string] realloc failed.\n");
            exit(1);
        }
        dynamicString->ptr = newPtr;
        dynamicString->cap = newCap;
        dynamicString->len = newLen;
        strcat(dynamicString->ptr, appendedValue);
    }
}

void prepend_to_string(DynamicString *dynamicString, char *prependedValue) {
    int prependedSize = 0;
    for (int i = 0; prependedValue[i] != '\0'; i++) {
        char ch = prependedValue[i];
        prependedSize++;
    }

    char *newPtr;
    if (prependedSize + dynamicString->len <= dynamicString->cap) {
        newPtr = malloc(dynamicString->cap * sizeof(char));
    } else {
        int newLen = prependedSize + dynamicString->len;
        int newCap = (prependedSize + dynamicString->len) * 2;
        newPtr = malloc(newCap * sizeof(char));
        dynamicString->cap = newCap;
        dynamicString->len = newLen;
    }
    if (newPtr == NULL) {
        printf("[ERROR:prepend_to_string] malloc failed.\n");
        exit(1);
    }
    strcpy(newPtr, prependedValue);
    strcat(newPtr, dynamicString->ptr);
    free(dynamicString->ptr);
    dynamicString->ptr = newPtr;
}

/*------------------------------------------ARRAYS----------------------------------------------*/

DynamicArray dynamic_array(DynamicArrayItem initialArr[], int len) {
    DynamicArray arr = {0};
    arr.len = len;
    arr.cap = len * 2;
    arr.ptr = malloc(arr.cap * sizeof(DynamicArrayItem));
    for (int i = 0; i < len; i++) {
        arr.ptr[i] = initialArr[i];
    }
    return arr;
}

void print_array(DynamicArray *dynamicArr) {
    for (int i = 0; i < dynamicArr->len; i++) {
        DynamicArrayItem item = dynamicArr->ptr[i];
        switch (item.type) {
        case INTEGER:
            printf("%d_print_array_int: %d\n", i, item.value.intValue);
            break;
        case STRING:
            printf("%d_print_array_string: %s\n", i, item.value.stringValue);
            break;
        case CHARACTER:
            printf("%d_print_array_char: %c\n", i, item.value.charValue);
            break;
        case BOOLEAN:
            printf("%d_print_array_bool: %ud\n", i, item.value.boolValue);
            break;
        default:
            printf("[ERROR:print_array] unknown data type %c.\n", item.type);
        }
    }

    printf("print_array: size - %d\n", dynamicArr->len);
    printf("print_array: cap - %d\n", dynamicArr->cap);
}

void push_to_array(DynamicArray *dynamicArr, DynamicArrayItem newItem) {
    if (dynamicArr->cap >= dynamicArr->len + 1) {
        dynamicArr->ptr[dynamicArr->len] = newItem;
        dynamicArr->len++;
    } else {
        int newLen = dynamicArr->len + 1;
        int newCap = newLen * 2;
        DynamicArrayItem *newArrPtr = realloc(dynamicArr->ptr, newCap * sizeof(DynamicArrayItem));
        if (newArrPtr == NULL) {
            printf("[ERROR:push_to_array] realloc failed.\n");
            exit(1);
        }
        newArrPtr[newLen - 1] = newItem;
        dynamicArr->ptr = newArrPtr;
        dynamicArr->len = newLen;
        dynamicArr->cap = newCap;
    }
}

void main_utils() {
    // DynamicString str = dynamic_string("Hello"); // hello
    // append_to_string(&str, " 1st");
    // append_to_string(&str, " 2nd");
    // prepend_to_string(&str, "3th ");

    // char newValue[str.len];
    // strcpy(newValue, str.ptr);

    // printf("DynamicString_size: %d\n", str.len);
    // printf("DynamicString_cap: %d\n", str.cap);
    // printf("DynamicString_ptr: %p\n", str.ptr);
    // printf("DynamicString_value: %s\n", newValue);

    // free(str.ptr);

    DynamicArrayItem initialArr[] = {
        {.value = {.intValue = 15}, .type = INTEGER},
        {.value = {.intValue = 20}, .type = INTEGER},
    };
    DynamicArray arr = dynamic_array(initialArr, ARRAY_LENGTH(initialArr));

    DynamicArrayItem newValues[] = {
        {.value = {.intValue = 90},  .type = INTEGER},
        {.value = {.intValue = 100}, .type = INTEGER},
        {.value = {.intValue = 110}, .type = INTEGER},
        {.value = {.intValue = 120}, .type = INTEGER},
        {.value = {.intValue = 130}, .type = INTEGER},
        {.value = {.intValue = 140}, .type = INTEGER},
        {.value = {.intValue = 150}, .type = INTEGER},
    };
    for (int i = 0; i < ARRAY_LENGTH(newValues); i++) {
        DynamicArrayItem item = newValues[i];
        push_to_array(&arr, item);
    }

    print_array(&arr);
}
