udp_server.c

  #include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    int sockfd;
    char buffer[100];

    struct sockaddr_in server, client;
    socklen_t len = sizeof(client);

    // Create UDP socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    // Server address configuration
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8080);

    // Bind socket to port 8080
    bind(sockfd, (struct sockaddr *)&server, sizeof(server));

    printf("Waiting for message...\n");

    // Receive message from client
    recvfrom(sockfd, buffer, sizeof(buffer), 0,
             (struct sockaddr *)&client, &len);

    printf("Received: %s\n", buffer);

    close(sockfd);

    return 0;
}


udp_client.c


  #include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    int sockfd;

    struct sockaddr_in server;

    // Create UDP socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    // Server details
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Send message to server
    sendto(sockfd, "Hello UDP", 10, 0,
           (struct sockaddr *)&server, sizeof(server));

    printf("Message Sent\n");

    close(sockfd);

    return 0;
}
