#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>

int main() {

    int sockfd, len, res;

    struct sockaddr_in addr;

    char name[100], ser[100];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_family = AF_INET;
    addr.sin_port = 9001;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    len = sizeof(addr);

    res = connect(sockfd,(struct sockaddr *)&addr,len);

    if (res == -1) {

        perror("unable to connect");

        exit(1);
    }

    while (1) {

        printf("\nEnter message : ");
        gets(name);

        write(sockfd, name, sizeof(name));

        read(sockfd, ser, sizeof(ser));

        printf("\nMessage from server : ");
        puts(ser);
    }

    close(sockfd);
    return 0;
}