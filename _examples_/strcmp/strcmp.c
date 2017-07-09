#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*
 * int strcmp(const char *str1, const char *str2)
 * int strncmp(const char *str1, const char *str2, size_t n)
 * n is the maximum number of characters to compare
 * if str1 > str2, return a positive value
 * if str1 < str2, return a negative value
 * if str1 = str2, return 0
 */

int main() {
  // For unequal comparison

  char str1[] = "string";
  char str2[] = "String";
  int ret;

  ret = strcmp(str1, str2);
  printf("%d\nExpected to be greater than 0\n", ret);

  // For equal comparison

  char str3[] = "string";
  char str4[] = "string";
  
  ret = strcmp(str3, str4);
  printf("%d\nExpected to be 0\n", ret);

  // Using strncmp

  char str5[] = "arbitrary";
  char str6[] = "arceus";
  
  ret = strncmp(str5, str6, 6);
  printf("%d\nExpected to be 0\n", ret);

  return 0;
}
