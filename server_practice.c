#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <time.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
int main() {
    int serv_sockfd,cli_sockfd;
    int serv_len,cli_len;
    time_t t;
    char a[100],b[100];
    struct sockaddr_in serv_addr,cli_addr;
    serv_sockfd=socket(AF_INET,SOCK_STREAM,0);
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_port=9001;
    serv_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
    serv_len=sizeof(serv_addr);
    bind(serv_sockfd,(struct sockaddr *)&serv_addr,serv_len);
    listen(serv_sockfd,5);
    cli_len=sizeof(cli_addr);
    cli_sockfd=accept(serv_sockfd,(struct sockaddr *)&cli_addr,&cli_len);
    while(1){
        read(cli_sockfd,a,sizeof(a));
        printf("\nmsg from client is ::%s",a);

        t=time(NULL);
        sprintf(b,"%s",ctime(&t));
        write(cli_sockfd,b,sizeof(b));
    }
    close(cli_sockfd);
}