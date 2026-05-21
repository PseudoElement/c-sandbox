#include "ariphmetic.h"
#include <stdio.h>

const char RELAY_API_KEY[10] = "2233123123";

int main_ariphmetic() {
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

    float subtrRes = (float)5 / 2.2;

    printf("subtrRes %.4f\n", subtrRes);

    my_int userScore = 100;
    int maxScore = 500;
    float percentage = (float)userScore / maxScore * 100.0;

    // Print the percentage
    printf("User's percentage is %.1f%c.\n", percentage, '%');

    printf("END OF main_ariphmetic\n\n");

    return 0;
}
