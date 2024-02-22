#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <fcntl.h>

#define WEB_ROOT "../../todo/src/"

void s_res(int client_sock, const char *message, const char *message_type);
void handle_req(int client_sock);