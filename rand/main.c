#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

int get_random_int() {
  int randNum;

  // Open /dev/random
  int fd = open( "/dev/random", O_RDONLY );
  if (fd == -1) {
    printf( "error: %d - %s\n", errno, strerror(errno));
  }

  // Read bytes into integer
  int numBytes = read( fd, &randNum, sizeof(int) );
  // printf("Number of bytes read: %d\n", numBytes);

  // Close /dev/random
  close(fd);

  return randNum;
}

void main() {
  // Set umask
  umask( 0111 );

  // Generate random integers
  printf("Generating random integers...\n");
  int rand_int[10];
  int i;
  for (i = 0; i < 10; i++) {
    rand_int[i] = get_random_int();
    printf("Random number %d: %d\n", i, rand_int[i]);
  }

  // Create rand.txt
  int fd = open( "rand.txt", O_CREAT | O_WRONLY, 0644 );
  if ( fd == -1 ) {
    printf( "error: %d - %s\n", errno, strerror(errno) );
  }

  // Write to rand.txt
  printf("\nWriting numbers to rand.txt...\n");
  write(fd, rand_int, 10 * sizeof(int));

  // Close file
  close(fd);

  // Reopen file
  fd = open("rand.txt", O_RDONLY);
  if ( fd == -1 ) {
    printf( "error: %d - %s\n", errno, strerror(errno) );
  }

  // Read file bytes into array
  int rand_int_second[10];
  printf("\nReading from rand.txt...\n");
  read(fd, rand_int_second, 10 * sizeof(int));

  // Print array
  for (i = 0; i < 10; i++) {
    printf( "Random number recheck %d: %d\n", i, rand_int_second[i] );
  }

  // Close file descriptor
  close(fd);
}
