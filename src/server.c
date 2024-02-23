#include "header/server.h"
#include "header/routes.h"

int wSock() {
    int socket_desc, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_size = sizeof(client_addr);
    char server_message[BUFFER], client_message[BUFFER];

    memset(server_message, '\0', sizeof(server_message));
    memset(client_message, '\0', sizeof(client_message));

    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        perror("Socket creation failed");
        return -1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(socket_desc, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        return -1;
    }

    if (listen(socket_desc, SOMAXCONN) < 0) {
        perror("Listen failed");
        return -1;
    }

    while (1) {
        client_sock = accept(socket_desc, (struct sockaddr *)&client_addr, &client_size);
        if (client_sock < 0) {
            perror("shit feila på accept tror æ");
            continue;
        }

        printf("awdjaipfjeifjwjg\n");

        handle_req(client_sock);

        if (strcmp(WEB_ROOT, "/") == 0) {
            handle_req(client_sock);
        } else {
            perror("shit gone");
        }

        s_res(client_sock, "Response Data", "text/html");

        close(client_sock);
        printf("Connection closed.\n");
    }

    // Close server socket
    close(socket_desc);
    return 0;
}
