#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <string.h>
#include <errno.h>

#ifndef WKP
#include "pipe_networking.h"
#endif

int server_handshake(int * client_fd) {
  umask(0133);

  // Step 1 - create Well Known Pipe
  mkfifo(WKP, 0644);
  printf("[SERVER] Starting server. Created Well Known Pipe.\n");

  // Step 2 - Wait for connection
  printf("[SERVER] Waiting for a client to connect...\n");
  *client_fd = open(WKP, O_RDONLY);

  // Step 6 - Receive client pipe and remove the Well Known Pipe
  char private_fifo_name[MESSAGE_BUFFER_SIZE] = {'\0'};

  read(*client_fd, private_fifo_name, MESSAGE_BUFFER_SIZE);
  printf("[SERVER] Received private FIFO name %s.\n", private_fifo_name);

  unlink(WKP);

  // Step 7 - Connect to client FIFO and send message
  int fd_private = open(private_fifo_name, O_WRONLY);
  printf("[SERVER] Connected to private FIFO %s.\n", private_fifo_name);

  char server_message[MESSAGE_BUFFER_SIZE] = {'\0'};
  strcpy(server_message, SERVER_MESSAGE);

  write(fd_private, server_message, strlen(server_message));
  printf("[SERVER] Sent message to client.\n");

  // Step 9 - Read from client
  char client_message[MESSAGE_BUFFER_SIZE] = {'\0'};
  *client_message = '\0';

  read(*client_fd, client_message, MESSAGE_BUFFER_SIZE);

  printf("[SERVER] Received client message: %s\n", client_message);

  return fd_private; // WRONLY
}

int client_handshake(int * server_fd) {
  umask(0133);

  // Step 3 - Create private FIFO
  char private_fifo[MESSAGE_BUFFER_SIZE] = {'\0'};
  sprintf(private_fifo, "%d", getpid());
  printf("[CLIENT] Created private FIFO %s.\n", private_fifo);

  mkfifo(private_fifo, 0644);

  // Step 4 - Connect to Well Known Pipe and send name of private FIFO
  *server_fd = open(WKP, O_WRONLY);
  write(*server_fd, private_fifo, strlen(private_fifo));

  printf("[CLIENT] Connected to WKP. Sent private FIFO name %s!\n", private_fifo);

  // Step 5 - Wait for connection from server
  int fd_private = open(private_fifo, O_RDONLY);
  printf("[CLIENT] Waiting for server to respond...\n");

  // Step 8 - Receive server's message and removes private FIFO
  char server_message[MESSAGE_BUFFER_SIZE] = {'\0'};
  *server_message = '\0';

  read(fd_private, server_message, MESSAGE_BUFFER_SIZE);

  printf("[CLIENT] Received server message: %s\n", server_message);

  unlink(private_fifo);

  // Step 9 - Send message to server
  char client_message[MESSAGE_BUFFER_SIZE] = {'\0'};
  strcpy(client_message, CLIENT_MESSAGE);
  write(*server_fd, client_message, strlen(client_message));

  printf("[CLIENT] Sent message to server.\n");

  printf("[CLIENT] Connection established with server.\n");

  return fd_private; // RDONLY
}
