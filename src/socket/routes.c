#include "server.h"
#include "header/routes.h"

void s_res(int client_sock, const char *message, const char *message_type) {
    char response[BUFFER];
    sprintf(response,"HTTP/1.1 200 OK\r\nContent-Type: %s\r\n\r\n%s",
        message_type,
        message);
    send(client_sock,response,strlen(response),0);
}

void handle_req(int client_sock) {
    char buf[BUFFER] = {0};
    read(client_sock, buf, sizeof(BUFFER));

    char template_path[256];
    sscanf(buf, "GET %255s", template_path);

    if (template_path[strlen(template_path) - 1] == '/')
        strcat(template_path, "index.html");
    
    char full_path[512];
    snprintf(full_path, sizeof(full_path),"%s%s",WEB_ROOT,template_path);

    int fd = open(full_path, O_RDONLY);
    if (fd == -1)
    {
        s_res(client_sock, "418 i'm a teapot","text/plain");
    } else {
        char file_buf[8192];
        ssize_t bytes_read;

        while ((bytes_read = read(fd, file_buf, sizeof(file_buf))) > 0)
        {
            send(client_sock, file_buf, bytes_read, 0);
        }
        close(fd);
    }
}