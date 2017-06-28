#define MESSAGE_BUFFER_SIZE 1024

#define WKP "wkp"
#define SERVER_MESSAGE "Welcome, client!" // Sent first
#define CLIENT_MESSAGE "Hi there, server!" // Sent second

int server_handshake(int * client_fd);
int client_handshake(int * server_fd);
