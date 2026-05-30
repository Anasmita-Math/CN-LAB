#include<stdio.h>
#include<stdlib.h>
int main() {
    int i,x,noframes;
    for(i=0;i<200;i++) {
        rand();
    }
    noframes=rand()%200;
    noframes=noframes/8;
    printf("\nNumber of frames: %d\n",noframes);
    for(i=1;i<noframes;i++) {
        printf("\nSending frame: %d\n",i);
        x=rand()%2;
        if(x==0) {
            printf("\nAcknowledgement Lost..");
            printf("\nResending frame: %d\n",i);
            printf("\nWaiting for acknowledgement..");
        }
        printf("\nResending Frame: %d",i);
    }
    printf("Stop and wait protocol is completed.");
    return 0;
}