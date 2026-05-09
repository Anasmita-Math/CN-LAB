#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

int main() {
    int sockfd, len, result;
    struct sockaddr_in address;
    char name[100], ser[100];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_port = 9001;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");

    len = sizeof(address);
    result = connect(sockfd, (struct sockaddr *)&address, len);

    if (result == -1) {
        perror("unable to connect");
        exit(1);
    }

    printf("Enter message: ");
    gets(name);
    write(sockfd, name, sizeof(ser)); 

    close(sockfd);
    return 0;
}
