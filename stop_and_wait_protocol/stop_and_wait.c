#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, noframes, x, x1 = 10, x2;
    for (i = 0; i < 200; i++) {
        rand();
    }
    noframes = rand() % 200;
    i = 1;
    j = 1;
    noframes = noframes / 8;

    printf("\n number of frames is %d \n", noframes);
    while (noframes > 0) {
        printf("\n sending frame %d \n", i);
        srand(x1++);
        x = rand() % 10;
        if (x % 2 == 0) {
            for (x2 = 1; x2 < 2; x2++) {
                printf("\n waiting for %d second \n", x2);
            }
            printf("\n sending frame %d \n", i);
            srand(x1++);
            x = rand() % 10;
        }
        printf("\n Ack for frames %d ", j);
        noframes -= 1;
        i++;
        j++;
    }
    printf("\n end of stop and wait protocall \n");
    return 0;
}