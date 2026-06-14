#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
int main()
{
    int sockfd;
    struct sockaddr_in server_addr;
    int num = 5;
    int square;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(5000);
    inet_pton(AF_INET,
              "127.0.0.1",
              &server_addr.sin_addr);
    connect(sockfd,
            (struct sockaddr *)&server_addr,
            sizeof(server_addr));
    send(sockfd, &num, sizeof(num), 0);
    recv(sockfd, &square, sizeof(square), 0);
    printf("Square Received = %d\n", square);
    close(sockfd);
    return 0;
}
