#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <arpa/inet.h>


int main() {

    char sendline[100], revline[100];

    int sockfd;

    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0){
        printf("Socket creation failed\n");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = 5777;
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

        read(sockfd, revline, 100);

        printf("\nReverse string is : %s\n", revline);
    }

    close(sockfd);

    return 0;
}