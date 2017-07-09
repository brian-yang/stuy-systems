#include <stdio.h>
#include <stdlib.h>

int length(char str[]) {
  int sum = 0;
  while (str[sum] != '\0') {
    sum += 1;
  }
  return sum;
}

int main() {
  char str[] = "Hello!";
  printf("Length of 'Hello!': %d\n", length(str));
  return 0;
}
