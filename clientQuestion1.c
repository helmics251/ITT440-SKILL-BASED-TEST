#include <arpa/inet.h> 
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h> 
#include <sys/socket.h>
#include <unistd.h> 

#define SA struct sockaddr
void func(int socket_desc)
{
        char buff[80];
        int n;

        read(socket_desc, buff, sizeof(buff));
        printf("From Server : %s", buff);


}

int main()
{
        int socket_desc, connect_desc;
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
        server.sin_addr.s_addr = inet_addr("192.168.191.128");
        server.sin_port = htons(8080);

        
        if (connect(socket_desc, (SA*)&server, sizeof(server))
                != 0) {
                printf("connection with the server failed...\n");
                exit(0);
        }
        else
                printf("connected to the server..\n");

        
        func(socket_desc);

        
        close(socket_desc);
}
