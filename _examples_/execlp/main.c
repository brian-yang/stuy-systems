#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  printf("Executing file test...\n");
  execlp("./echo.sh", "echo.sh", NULL);
  return 0;
}
