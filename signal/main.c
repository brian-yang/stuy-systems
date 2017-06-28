#include <stdlib.h>
#include <stdio.h>
/* ===================== */
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
/* ===================== */
#include <errno.h>
#include <string.h>

static void write_sigint() {
  int fd = open("pid.log", O_CREAT | O_WRONLY | O_APPEND, 0644);
  if (errno) {
    printf("Error #%d: %s\n", errno, strerror(errno));
  }
  char log_exit[] = "Program exited due to SIGINT.\n";
  write(fd, log_exit, sizeof(log_exit));
  close(fd);
}

static void sighandler(int signo) {
  if (signo == SIGINT) {
    printf("Received SIGINT signal. Writing to log file & exiting...\n");
    write_sigint();
    exit(0);
  } else if (signo == SIGUSR1) {
    printf("Parent PID: %d\n", getppid());
  }
}

int main() {
  umask(0122);

  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);

  raise(SIGUSR1);
  while (1) {
    printf("PID: %d\n", getpid());
    sleep(1);
  }
}
