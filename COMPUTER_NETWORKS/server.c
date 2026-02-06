//===----------------------------------------------------------------------===//
// A simple TCP server
//===----------------------------------------------------------------------===//

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
    if (argc < 2)
    {
        fprintf(stderr, "Port No not provided. Program terminated\n");
        exit(1);
    }

    int sockfd, newsockfd, portno, n;
    char buffer[255];

    // sockaddr_in stores sin_family(address family), sin_addr(IP address), sin_port(port number).
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;

    // New socket is created : socket(domain, type, protocol).
    // Protocol 0 specifys defaults for the domain+type.
    // Socket returns either -1(fail) or non-negative file descriptor(success).
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        error("Error opening socket.");
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    portno = atoi(argv[1]);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    // htons() converts port number to network byte order.
    serv_addr.sin_port = htons(portno);

    // C does not support polymorphism and hence the generic pointer casting O_o.
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        error("Binding failed.");
    }

    // Prepare the socket to accept and queue up to n incoming connections
    listen(sockfd, /*n*/ 5);

    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
    if (newsockfd < 0)
    {
        error("Error on accept.");
    }
    while (1)
    {
        memset(buffer, 0, 255);
        n = read(newsockfd, buffer, 255);
        if (n < 0)
        {
            error("Error on reading.");
        }

        printf("Client: %s\n", buffer);
        memset(buffer, 0, 255);
        fgets(buffer, 255, stdin);

        n = write(newsockfd, buffer, strlen(buffer));
        if (n < 0)
        {
            error("Error on writing.");
        }

        if (strncmp("Bye", buffer, 3) == 0)
        {
            break;
        }
    }
    close(newsockfd);
    close(sockfd);

    return 0;
}
