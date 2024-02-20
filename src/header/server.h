// server.h
#ifndef SERVER_H
#define SERVER_H

#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

#define BUFFER 1024
#define PORT 8080
#define LOCALHOST "127.0.0.1"

int wSock();

#endif /* SERVER_H */
