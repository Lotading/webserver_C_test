#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER 1024

struct sockaddr_in server_addr;

int main(int argc, char** argv) {
    
    int socket_desc, client_sock, client_size[BUFFER];
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
}
