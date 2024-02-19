#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER 1024

struct sockaddr_in server_addr;

int main(int argc, char** argv) {
    
    int socket_desc, client_sock, client_size;
    struct sockaddr_in server_addr, client_addr;

    socket_desc = socket(AF_INET,SOCK_STREAM,0);
 
    if (socket_desc < 0) {
        perror("its so over");
        return -1;
    }
    printf("we are so back");

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8000);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (bind(socket_desc,(struct sockaddr*)&server_addr,sizeof(server_addr)) < 0)
    {
        perror("err bind failed");
        return -1;
    }
    printf("bind succeded");

    if (listen(socket_desc,1) < 0) {
        perror("listen failed");
        return -1;
    }

    client_size = sizeof(client_addr);
    client_sock = accept(socket_desc,(struct sockaddr*)&client_addr,&client_size);

    if (client_sock < 0) {
        perror("client failed? might be too much my guy");
        return -1;
    }
    printf("IP: %s & PORT: %i",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));


}
