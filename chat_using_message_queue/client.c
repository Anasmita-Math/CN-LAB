#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
#include<stdlib.h>

int main(){
    struct msgbuf{
        long mtype;
        char mtext[100];
    }send,recv;

    int qid = msgget((key_t)125 , IPC_CREAT | 0666);

    if(qid < 0){
        printf("Message craetion failed");
        return 0;
    }

    while(1){
        printf("Enter message for server :: ");
        scanf("%[^\n]s", send.mtext);
        getchar();
        send.mtype = 2;
        msgsnd(qid , &send, sizeof(send.mtext), 0);

        printf("Message from server :: ");
        msgrcv(qid, &recv,sizeof(recv.mtext) , 1 , 0);
        puts(recv.mtext);
    }

    return 0;
}