#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int s_sd, serv_len;
    char sour[200], dest[200];
    struct sockaddr_in serv;

    s_sd = socket(AF_INET, SOCK_DGRAM, 0);
    serv_len = sizeof(serv);
    serv.sin_family = AF_INET;
    serv.sin_port = 8002;
    serv.sin_addr.s_addr = inet_addr("127.0.0.1");

    bind(s_sd, (struct sockaddr *)&serv, serv_len);
    printf("the server is waiting .... \n");

    while (1) {
        recvfrom(s_sd, &sour, sizeof(sour), 0, (struct sockaddr *)&serv, &serv_len);
        printf("\nthe message from client is :%s \n", sour);

        printf("\nEnter the message for client : \n");
        
        scanf("%[^\n]s", dest);
        getchar();
        
        sendto(s_sd, &dest, sizeof(dest), 0, (struct sockaddr *)&serv, serv_len);
    }
    close(s_sd);
    return 0;
}