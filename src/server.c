#include "server.h"

struct sockaddr_in server_addr;

int wSock() {
    // @Lotading: this is retarded what T_T
    socklen_t socket_desc, client_sock, client_size;
    struct sockaddr_in server_addr, client_addr;
    char server_message[BUFFER], client_message[BUFFER];

    memset(server_message, '\0', sizeof(server_message));
    memset(client_message, '\0', sizeof(client_message));

    socket_desc = socket(AF_INET,SOCK_STREAM,0);
 
    if (socket_desc <= 0) {
        perror("its so over\n");
        return -1;
    }
    printf("we are so back\n");

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(LOCALHOST);

    if (bind(socket_desc,(struct sockaddr*)&server_addr,sizeof(server_addr)) < 0)
    {
        perror("err bind failed\n");
        return -1;
    } printf("bind succeded\n");

    if (listen(socket_desc,1) <= 0) {
        perror("listen failed\n");
        return -1;
    } printf("where connection man\n");

    client_size = sizeof(client_addr);
    client_sock = accept(socket_desc,(struct sockaddr*)&client_addr,&client_size);
    if (client_sock <= 0) {
        perror("client failed? might be too much my guy");
        return -1;
    } printf("IP: %s & PORT: %i",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));

    if (recv(client_size,client_message,strlen(server_message),0) <= 0) {
        perror("message does not respect buffer boundaries >:( \n");
        return -1;
    }
    printf("Msg from client: %s\n", client_message);

    strcpy(server_message, "mesage from server\n");

    if (send(client_sock,server_message,strlen(server_message),0) <= 0)
    {
        perror("failed error thingy bleehhh\n");
        return -1;
    }
    
    close(socket_desc);
    close(client_sock);
    return 0;
}
