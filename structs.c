#include "./include/structs.h"
#include <stdio.h>

const char RELAY_API_KEY[10] = "2233123123";

int main_structs() {
    struct Person person = {
        45,
        "bimba",
        228.88,
    };

    Point point = {.x = 11, .y = 20};
    Point2 point2 = {.x = 11, .y = 20};
    struct Point2 _point2 = {.x = 11, .y = 20};

    person.age = 22;

    float ratio = person.salary / 10;

    printf("ratio %f\n", ratio);

    printf("END OF main_structs\n\n");

    return 0;
}
