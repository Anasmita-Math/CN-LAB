#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/msg.h>
#include<sys/types.h>
#include<sys/ipc.h>

int main(){
    struct msgbuf{
        long mtype;
        char mtext[100];
    }send,recv;

    int qid = msgget((key_t)125,IPC_CREAT|0666);
    if(qid < 0){
        printf("Message creation failed");
        return 0;
    }

    while(1){
        msgrcv(qid,&recv,sizeof(recv.mtext),2,0);
        printf("Message from client :: ");
        puts(recv.mtext);

        printf("Enter message for client :: ");
        scanf("%[^\n]s",send.mtext);
        getchar();
        send.mtype = 1; 
        msgsnd(qid , &send,sizeof(send.mtext),0);
    }
    return 0;
}