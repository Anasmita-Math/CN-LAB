#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <time.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
int main() {
    int len,sockfd,res;
    time_t t;
    char a[100],b[100];
    struct sockaddr_in addr;
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    addr.sin_family=AF_INET;
    addr.sin_port=9001;
    addr.sin_addr.s_addr=inet_addr("127.0.0.1");
    len=sizeof(addr);
    res=connect(sockfd,(struct sockaddr *)&addr,len);
    if(res==-1){
        perror("Message failed..");
        exit(1);
    }
    printf("Enter msg:: ");
    scanf("%[^\n]s",a);
    getchar();
    write(sockfd,a,sizeof(a));
    read(sockfd,b,sizeof(b));
    printf("\nTime is:: ");
    puts(b);
    close(sockfd);
    return 0;
}
