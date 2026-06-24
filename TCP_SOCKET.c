11. Create a TCP server that receives and displays a message sent by a client.
    
server.c

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    int server_fd, client_fd;
    char buffer[100];

    struct sockaddr_in server;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8080);

    bind(server_fd, (struct sockaddr *)&server, sizeof(server));

    listen(server_fd, 1);

    printf("Waiting for client...\n");

    client_fd = accept(server_fd, NULL, NULL);

    recv(client_fd, buffer, sizeof(buffer), 0);

    printf("Received: %s\n", buffer);

    close(client_fd);
    close(server_fd);

    return 0;
}

client.c

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    int sockfd;

    struct sockaddr_in server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(sockfd, (struct sockaddr *)&server, sizeof(server));

    char msg[] = "Hello TCP";

    send(sockfd, msg, strlen(msg) + 1, 0);

    printf("Message Sent\n");

    close(sockfd);

    return 0;
}
