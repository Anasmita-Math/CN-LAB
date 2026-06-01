#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

int main()
{
    int serv_sockfd, cli_sockfd;
    int serv_len, cli_len;
    struct sockaddr_in serv_address, cli_addr;

    int num[2];
    int sum;

    serv_sockfd = socket(AF_INET, SOCK_STREAM, 0);

    serv_address.sin_family = AF_INET;
    serv_address.sin_port = 9001;
    serv_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    serv_len = sizeof(serv_address);

    bind(serv_sockfd, (struct sockaddr *)&serv_address, serv_len);

    listen(serv_sockfd, 5);

    while (1)
    {
        printf("Server is waiting...\n");

        cli_len = sizeof(cli_addr);

        cli_sockfd = accept(serv_sockfd,
                           (struct sockaddr *)&cli_addr,
                           &cli_len);

        read(cli_sockfd, num, sizeof(num));

        printf("Received Numbers : %d %d\n", num[0], num[1]);

        sum = num[0] + num[1];

        printf("Sum = %d\n", sum);

        write(cli_sockfd, &sum, sizeof(sum));

        close(cli_sockfd);
    }
}