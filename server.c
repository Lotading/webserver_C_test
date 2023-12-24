#include <winsock2.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

#define BUFFER 1024

unsigned long WSAAPI inet_addr(
  const char *cp    
);

int main(int argc, char** argv) {
    inet_addr("127.0.0.1");

    
}
