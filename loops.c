#include <stdio.h>

void main_loops(int idx) {
    if (idx > 2) {
        return;
    }
    printf("main_loops_idx %d\n", idx);

    int count = 3;
    while (count > 0) {
        count--;
    }
    count = 1;

    do {
        count++;
    } while (count >= 2 && count < 10);
    printf("count %d\n", count);

    for (int i = 1; i <= 5; i++) {
        for (int j = 5; j > 0; j--) {
            if (j == 1) {
                printf("\n");
                continue;
            }
            printf("%d, ", i * j);
        }
        printf("\n");
    }

    printf("END OF main_loops\n\n");

    // main_loops(++idx);
}
