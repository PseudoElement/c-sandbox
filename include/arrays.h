#ifndef ARRAYS_H
#define ARRAYS_H

/**
 * MACRO
 */
#define ARRAY_LENGTH(x) ((int)(sizeof(x) / sizeof((x)[0])))

int main_arrays();
int terminal_inputs();

#endif
