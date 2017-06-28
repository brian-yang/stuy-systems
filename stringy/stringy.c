#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int myStrlen(char *str);
char *myStrcpy(char *dest, char *src);
char *myStrcat(char *dest, char *src);
int myStrcmp(char *str1, char *str2);
char *myStrchr(char *str, int c);
char *myStrstr(char *haystack, char *needle);
char *myStrncpy(char *dest, char *src, int n);
char *myStrncat(char *dest, char *src, int n);


int main() {
  // =======================
  printf("strlen check:\n");

  char hello[] = "Hello! ABC\0";
  printf("strlen: length of 'Hello! ABC' = %lu\n", strlen(hello));
  printf("myStrlen: length of 'Hello! ABC' = %d\n", myStrlen(hello));

  char test[] = "Testing!\0";
  printf("strlen: length of 'Testing!' = %lu\n", strlen(test));
  printf("myStrlen: length of 'Testing!'= %d\n", myStrlen(test));
  // =======================
  printf("\nstrcpy check:\n");
  strcpy(hello, "Hi there!");

  char hello1[strlen(hello)];
  char hello2[myStrlen(hello)];

  strcpy(hello1, hello);
  printf("strcpy = %s\n", hello1);

  myStrcpy(hello2, hello);
  printf("myStrcpy = %s\n", hello2);

  // =======================
  printf("\nstrcat check:\n");

  char super[] = "super\0";
  char man[] = "man\0";
  char bat[] = "bat\0";

  strcat(super, man);
  printf("strcat = %s\n", super);

  myStrcat(bat, man);
  printf("myStrcat = %s\n", bat);

  // =======================
  printf("\nstrcmp check:\n");

  char dragon[] = "drAgoN\0";
  char dragon2[] = "dRAgOn\0";

  printf("strcmp: %d\n", strcmp(dragon, dragon2));
  printf("myStrcmp: %d\n", myStrcmp(dragon, dragon2));

  char abc[] = "abc\0";
  char abc2[] = "abc\0";

  printf("strcmp: %d\n", strcmp(abc, abc2));
  printf("myStrcmp: %d\n", myStrcmp(abc, abc2));

  char ok[] = "ok\0";
  char cat[] = "cat\0";

  printf("strcmp: %d\n", strcmp(ok, cat));
  printf("myStrcmp: %d\n", myStrcmp(ok, cat));

  // =======================
  printf("\nstrchr check:\n");

  printf("strchr: 'l' in 'ledlights' = %s\n", strchr("ledlights\0", 'l'));
  printf("myStrchr: 'l' in 'ledlights' = %s\n", myStrchr("ledlights\0", 'l'));
  // =======================
  printf("\nstrstr check:\n");

  printf("strstr: 'dli' in 'ledlights' = %s\n", strstr("ledlights\0", "dli"));
  printf("myStrstr: 'dli' in 'ledlights' = %s\n", myStrstr("ledlights\0", "dli"));

  printf("strstr: 'abc' in 'ajrgbajrfgbajabcajklsdfasndfaksjdfnk' = %s\n", strstr("ajrgbajrfgbajabcajklsdfasndfaksjdfnk\0", "abc"));
  printf("myStrstr: 'abc' in 'ajrgbajrfgbajabcajklsdfasndfaksjdfnk' = %s\n", myStrstr("ajrgbajrfgbajabcajklsdfasndfaksjdfnk\0", "abc"));

  printf("strstr: 'legend' in 'legendary' = %s\n", strstr("legendary\0", "legend"));
  printf("myStrstr: 'legend' in 'legendary' = %s\n", myStrstr("legendary\0", "legend"));
  // =======================
  printf("\nstrncpy check:\n");
  strcpy(hello, "Hi there!");

  char hellotest[strlen(hello)];
  char hellotest2[myStrlen(hello)];

  strncpy(hellotest, hello, 5);
  printf("strcpy = %s\n", hellotest);

  myStrncpy(hellotest2, hello, 5);
  printf("myStrcpy = %s\n", hellotest2);

  // =======================
  printf("\nstrncat check:\n");

  // variables defined in strcat check

  strncat(super, man, 0);
  printf("strcat = %s\n", super);

  myStrncat(bat, man, 0);
  printf("myStrcat = %s\n", bat);
  // =======================

  return 0;
}

int myStrlen(char *str) {
  char *tmp = str;
  int length = 0;
  while (*tmp != '\0') {
    length++;
    tmp++;
  }
  return length;
}

char *myStrcpy(char *dest, char *src) {
  char *tmp = dest;
  while (*src != '\0') {
    *dest = *src;
    dest++;
    src++;
  }
  *dest = '\0';
  return tmp;
}

char *myStrcat(char *dest, char *src) {
  char *tmp = dest;
  while (*dest != '\0') {
    dest++;
  }
  while (*src != '\0') {
    *dest = *src;
    dest++;
    src++;
  }
  *dest = '\0';
  return tmp;
}

int myStrcmp(char *str1, char *str2) {
  while (*str1 != '\0') {
    if (*str2 == '\0') {
      return *str1;
    } else if (*str1 > *str2) {
      return *str1 - *str2;
    } else if (*str2 > *str1) {
      return *str1 - *str2;
    }
    str1++;
    str2++;
  }
  if (*str2 != '\0') {
    return *str2 * -1;
  } else {
    return 0;
  }
}

char *myStrchr(char *str, int c) {
  while (*str != '\0') {
    if (*str == c) {
      return str;
    }
    str++;
  }
  return '\0';
}

char *myStrstr(char *haystack, char *needle) {
  int i = 0;
  char *tmp = haystack;
  char *tmp2 = needle;
  while (*tmp != '\0' || i != 0) {
    if (*tmp2 == '\0') {
      return tmp - i;
    }
    if (*tmp != *tmp2) {
      tmp = tmp - i + 1;
      tmp2 = needle;
      i = 0;
    } else {
      tmp++;
      tmp2++;
      i++;
    }
  }
  return '\0';
}

char *myStrncpy(char *dest, char *src, int n) {
  char *tmp = dest;
  int i = 0;
  while (*src != '\0' && i != n) {
    *dest = *src;
    dest++;
    src++;
    i++;
  }
  *dest = '\0';
  return tmp;
}

char *myStrncat(char *dest, char *src, int n) {
  char *tmp = dest;
  while (*dest != '\0') {
    dest++;
  }
  int i = 0;
  while (*src != '\0' && i != n) {
    *dest = *src;
    dest++;
    src++;
    i++;
  }
  *dest = '\0';
  return tmp;
}
