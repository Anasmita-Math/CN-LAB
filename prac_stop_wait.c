#include<stdio.h>
#include<stdlib.h>
int main() {
    int i,noframe,x;
    for(int i=0;i<200;i++) {
        rand();
    }
    noframe=rand()%200;
    noframe=noframe/8;
    printf("Number of frames is:%d\n",noframe);
    for(int i=1;i<noframe;i++) {
        printf("Sending frame :%d\n",i);
        x=rand()%2;
        if(x==0) {
            printf("ACK lost:\n");
            printf("Resending frame :%d\n",i);
            printf("Waiting for ACK..\n");
        }
        printf("Acknowledgement recieved from frames:%d\n",i);
    }
    printf("Stop andf wait completed.\n");
    return 0;
}