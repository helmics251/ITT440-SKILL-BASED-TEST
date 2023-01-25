#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h> 
#include <arpa/inet.h>
#define SA struct sockaddr


void func(int connect_desc)
{
        char buff[80];
        int randomNum = (rand() % 900) + 100;
        bzero(buff, sizeof(buff));
        memset(buff, '\0', 256);
        sprintf(buff, "%d", randomNum);
        write(connect_desc, buff, sizeof(buff));
}


int main()
{
        int socket_desc, connect_desc, length;
        struct sockaddr_in server, cli;

        
        socket_desc = socket(AF_INET, SOCK_STREAM, 0);
        if (socket_desc == -1) {
                printf("socket creation failed...\n");
                exit(0);
        }
        else
                printf("Socket successfully created..\n");
        bzero(&server, sizeof(server));

        
        server.sin_family = AF_INET;
        server.sin_addr.s_addr = htonl(INADDR_ANY);
        server.sin_port = htons(8080);

        
        if ((bind(socket_desc, (SA*)&server, sizeof(server))) != 0) {
                printf("socket bind failed...\n");
                exit(0);
        }
        else
                printf("Socket successfully binded..\n");

        
        if ((listen(socket_desc, 5)) != 0) {
                printf("Listen failed...\n");
                exit(0);
        }
        else
                printf("Server listening..\n");
        length = sizeof(cli);

        
        connect_desc = accept(socket_desc, (SA*)&cli, &length);
        if (connect_desc < 0) {
                printf("server accept failed...\n");
                exit(0);
        }
        else
                printf("server accept the client...\n");

        
        func(connect_desc);
        close(socket_desc);
}
