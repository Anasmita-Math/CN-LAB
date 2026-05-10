#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include<stdlib.h>
#include <string.h>

int main() {

    int serv_sockfd, cli_sockfd;
    int serv_len, cli_len;

    struct sockaddr_in serv_addr, cli_addr;

    char a[100], b[100];

    serv_sockfd = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = 9001;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    serv_len = sizeof(serv_addr);

    bind(serv_sockfd,(struct sockaddr *)&serv_addr,serv_len);

    listen(serv_sockfd, 5);

    printf("server is waiting \n");

    cli_len = sizeof(cli_addr);

    cli_sockfd = accept(serv_sockfd,(struct sockaddr *)&cli_addr,&cli_len);

    while (1) {

        read(cli_sockfd, a, sizeof(a));

        printf("\nMessage from client : ");
        puts(a);

        printf("\nEnter message for client : ");
        gets(b);

        write(cli_sockfd, b, sizeof(b));
    }

    close(cli_sockfd);
    close(serv_sockfd);

    return 0;
}