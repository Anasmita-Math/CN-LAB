#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
int main() {
    int serv_sockfd,cli_sockfd,i,len;
    int serv_len,cli_len;
    char line[100],revline[100];
    ssize_t n;
    struct sockaddr_in serv_addr,cli_addr;
    serv_len=sizeof(serv_addr);
    serv_sockfd=socket(AF_INET,SOCK_STREAM,0);
    if(serv_sockfd<0) {
        perror("Message creation is failed");
        exit(1);
    }
    bzero(&serv_addr,serv_len);
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_port=9001;
    serv_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
    bind(serv_sockfd,(struct sockaddr *)&serv_addr,serv_len);
    listen(serv_sockfd,5);
    while(1) {
        cli_len=sizeof(cli_addr);
        cli_sockfd=accept(serv_sockfd,(struct sockaddr *)&cli_addr,&cli_len);
        printf("\nConnecting with client");
        while((n=read(cli_sockfd,line,100))>0){
            line[n]='\0';
            len=strlen(line);
            for(i=0;i<n;i++){
                revline[i]=line[len-1-i];
            }
            revline[len]='\0';
            write(cli_sockfd,revline,strlen(revline)+1);
        }
        close(cli_sockfd);
    }
    close(serv_sockfd);
    return 0;
}