#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/types.h>

void check_error() {
  if (errno) {
    printf("Error #%d, %s\n", errno, strerror(errno));
  }
}

int print_dirinfo(DIR* current_dir, unsigned char file_type) {
  struct dirent* dir_info;
  struct stat metadata;
  int sum = 0;
  while (dir_info = readdir(current_dir)) {
    // Check if the file type matches the desired file type
    if (dir_info->d_type == file_type) {
      printf("File name: %s\n", dir_info->d_name);
      // Find the size of the file and add the size if it's a regular file
      if (dir_info->d_type == DT_REG) {
	stat(dir_info->d_name, &metadata);
	sum += metadata.st_size;
      }
    }
  }
  check_error();
  return sum;
}

int main() {
  // Open directory
  DIR *current_dir = opendir(".");
  check_error();

  // Print directories
  printf("\nDirectory files:\n");
  print_dirinfo(current_dir, DT_DIR);

  // Rewind pointer
  rewinddir(current_dir);

  // Print regular files
  printf("\nRegular files:\n");
  int total_size = 0;
  total_size += print_dirinfo(current_dir, DT_REG);

  // Print size of regular files
  printf("Total size of regular files: %d bytes\n", total_size);

  // Close directory
  closedir(current_dir);
  return 0;
}
