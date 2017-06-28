#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(){
  char str[100];

  // Stores user input
  printf("Enter command: ");
  fgets(str, 100, stdin);
  // printf("%s\n",str);

  char *s = str;
  char *command[100];
  int i = 0;
  s = strsep(&s,"\n"); // removes newline

  // Parse command
  while (s) {
    command[i] = strsep(&s," ");
    i++;
  }
  command[i]=NULL;

  // Execute command
  execvp(command[0],command);
  if (errno) {
    printf("Error %d: %s\n", errno, strerror(errno));
  }

  return 0;
}
