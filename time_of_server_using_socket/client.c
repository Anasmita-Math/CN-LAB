#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <time.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int sockfd, len, result;
    struct sockaddr_in address;
    char msg1[100], msg2[100];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_port = 4006;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");

    len = sizeof(address);
    result = connect(sockfd, (struct sockaddr *)&address, len);

    if (result == -1) {
        perror("OOPS: client 1");
        exit(1);
    }

    printf("Enter :: ");
    // gets(msg2);
    
    scanf("%[^\n]s",msg2);
    getchar();
    
    write(sockfd, msg2, sizeof(msg2));
    
    read(sockfd, msg1, sizeof(msg1));
    printf("\n Time of server is :: ");
    puts(msg1);

    return 0;
}