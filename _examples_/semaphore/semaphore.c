#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/stat.h>

union semun {
  int val;
  struct semid_ds *buf;
  unsigned short *array;
  struct seminfo *__buf;
};

int main() {
  
  umask(113);
  
  int semd;
  semd = semget ( ftok("~/Desktop", 50), 1, IPC_CREAT | 0664 );
  
  union semun test;
  semctl(semd, 0, SETVAL, test);
  printf("Semaphore value: %d\n", test.val);
  return 1;
}
