#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <arpa/inet.h>

#define MAXLINE 100
#define SERV_PORT 5777

int main() {

    char sendline[MAXLINE], revline[MAXLINE];

    int sockfd;

    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0){
        printf("Socket creation failed\n");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if(connect(sockfd,
              (struct sockaddr *)&servaddr,
              sizeof(servaddr)) < 0){

        printf("Connection failed\n");
        exit(1);
    }

    while(1){

        printf("\nEnter data : ");

        scanf("%[^\n]", sendline);

        getchar();

        write(sockfd, sendline, strlen(sendline) + 1);

        read(sockfd, revline, MAXLINE);

        printf("\nReverse string is : %s\n", revline);
    }

    close(sockfd);

    return 0;
}