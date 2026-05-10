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

    int i, len;

    ssize_t n;

    char line[MAXLINE], revline[MAXLINE];

    int listenfd, connfd;

    int clilen;

    struct sockaddr_in servaddr, cliaddr;

    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    if(listenfd < 0){
        printf("Socket creation failed\n");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    bind(listenfd,
           (struct sockaddr *)&servaddr,
           sizeof(servaddr));

    listen(listenfd, 5);

    while(1){

        clilen = sizeof(cliaddr);

        connfd = accept(listenfd,
                        (struct sockaddr *)&cliaddr,
                        &clilen);

        printf("\nClient connected\n");

        while((n = read(connfd, line, MAXLINE)) > 0){

            line[n] = '\0';

            len = strlen(line);

            for(i = 0; i < len; i++){
                revline[i] = line[len - 1 - i];
            }

            revline[len] = '\0';

            write(connfd, revline, strlen(revline) + 1);
        }

        close(connfd);
    }

    close(listenfd);

    return 0;
}