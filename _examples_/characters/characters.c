#include <stdio.h>
#include <stdlib.h>

int main() {
  char arr[100];
  int i = 0;
  for (; i < 100; i++) {
    arr[i] = 'a';
    printf("%d\n", i);
  }
  printf("%s\n", arr);
}
