#include "header/main.h"
#include "header/server.h"

#include <stdlib.h>
#include <stdio.h>

int main() {
    printf("hello world!\n");
    int _sock = wSock();
    while (_sock)
    {
       if (_sock = -1)
       {
            perror("something went wrong");
            exit(EXIT_FAILURE);
       }
    }
}