//===----------------------------------------------------------------------===//
// A simple client code to communicate with the TCP server
//===----------------------------------------------------------------------===//

#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s <server_ip> <port>\n", argv[0]);
        exit(1);
    }
    
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[255];
    struct hostent *server;

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("Error opening socket");

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    // Resolve server name/ip from the user argument
    server = gethostbyname(argv[1]);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr_list[0], server->h_length);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("Connection failed");

    while (1)
    {
        memset(buffer, 0, 255);
        printf("You: ");
        fgets(buffer, 255, stdin);

        n = write(sockfd, buffer, strlen(buffer));
        if (n < 0)
            error("Error writing to socket");

        memset(buffer, 0, 255);
        n = read(sockfd, buffer, 255);
        if (n < 0)
            error("Error reading from socket");

        printf("Server: %s\n", buffer);

        if (strncmp("Bye", buffer, 3) == 0)
            break;
    }

    close(sockfd);
    return 0;
}
