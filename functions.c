#include "include/functions.h"
#include <math.h>
#include <stdio.h>

/**
 * INLINE function in assembly code instead of JUMP to it
 * but it's not compiling without `static` :(
 */
static inline float powAndDivide(int x) {
    x = pow((double)x, (double)2);
    float resp = (float)x / 3.3;
    return resp;
}

int addTwoNums(int a, int b) { return a + b; }

void greetMorning() { printf("Good morning!\n"); }
void greetEvening() { printf("Good evening!\n"); }

void greet(void(func)()) { func(); }

void main_funcs() {
    float (*funcPtr)(int) = powAndDivide;

    greet(greetMorning);
    greet(greetEvening);

    printf("powAndDivide res: %f\n", powAndDivide(12));
    printf("funcPtr: %f\n", funcPtr(10));
    printf("END OF main_funcs!\n\n");
}
