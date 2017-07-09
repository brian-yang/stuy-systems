#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
  int status;
  int pid = fork();
  int test = 5;
  
  if (pid > 0) {
    wait(&status);
  } else if (pid == 0) {
    test = 10;
  }

  printf("Test: %d\n", test);
  return 0;
}
