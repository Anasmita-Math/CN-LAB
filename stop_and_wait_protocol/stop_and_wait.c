#include <stdio.h>
#include <stdlib.h>

int main() {

    int i, noframes, x;

    for(i = 0; i < 200; i++) {
        rand();
    }

    noframes = rand() % 200;

    noframes = noframes / 8;

    printf("\nNumber of frames : %d\n", noframes);

    for(i = 1; i <= noframes; i++) {

        printf("\nSending Frame %d", i);

        x = rand() % 2;

        if(x == 0) {

            printf("\nAcknowledgement Lost");

            printf("\nResending Frame %d", i);

            printf("\nWaiting for ACK...\n");
        }

        printf("\nAcknowledgement received for Frame %d\n", i);
    }

    printf("\nStop and Wait Protocol Completed\n");

    return 0;
}