#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdbool.h>

/// @brief user data
typedef struct {
    char *username;
    char *passwd;
    bool state;
} User;

int userDef(User user) {
    
}