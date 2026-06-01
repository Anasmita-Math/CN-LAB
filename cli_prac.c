#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <arpa/inet.h>
int main() {
    int sockfd,len;
    char line[100],revline[100];
    struct sockaddr_in addr;
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    if(sockfd<0) {
        perror("Socket creation failed\n");
        exit(1);
    }
    len=sizeof(addr);
    bzero(&addr,len);
    addr.sin_family=AF_INET;
    addr.sin_port=9001;
    addr.sin_addr.s_addr=inet_addr("127.0.0.1");
    if(connect(sockfd,(struct sockaddr *)&addr,len)<0) {
        perror("Connection failed\n");
        exit(1);
    }
    while(1) {
        printf("Enter message for server:\n");
        scanf("%[^\n]",line);
        getchar();
        write(sockfd,line,strlen(line)+1);
        read(sockfd,revline,100);
        printf("The msg from server is:\n");
        puts(revline);
    }
    close(sockfd);
    return 0;
}