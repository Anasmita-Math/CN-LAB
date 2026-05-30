#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int len, sd;
    char ch1[200], ch2[200];
    struct sockaddr_in sock_address;

    sd = socket(AF_INET, SOCK_DGRAM, 0);
    sock_address.sin_family = AF_INET;
    sock_address.sin_port = 8002;
    sock_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    len = sizeof(sock_address);
    // Note: Manual entry shows a bind call here, which is unconventional for a basic UDP client but included as per image
    bind(sd, (struct sockaddr *)&sock_address, len);

    while (1) {
        printf("\nEnter the message to server : \n");
        
        scanf("%[^\n]s", ch1);
        getchar();
        sendto(sd, &ch1, sizeof(ch1), 0, (struct sockaddr *)&sock_address, len);

        recvfrom(sd, &ch2, sizeof(ch2), 0, (struct sockaddr *)&sock_address, &len);
        printf("\nthe message from server : %s \n", ch2);
    }
    close(sd);
    return 0;
}