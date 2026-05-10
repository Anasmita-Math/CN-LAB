// Create Message Queue
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
int main()
{
    int msgid, len;
    key_t key;
    key = 131;
    msgid = msgget(key, IPC_CREAT | 0666);
    printf("\n q = %d", msgid);
}