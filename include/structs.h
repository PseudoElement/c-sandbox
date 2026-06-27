#ifndef STRUCTS_H
#define STRUCTS_H

// when create instance you need to write struct in the beginning
struct Person {
    short age;
    char name[50];
    float salary;
};

// no struct word needed on creation
typedef struct {
    int x;
    int y;
} Point;

// can use both with struct or without it
typedef struct Point2 {
    int x;
    int y;
} Point2;

int main_structs();

#endif
