#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
int myrand() {
  int random;
  int randD = open("/dev/random", O_RDONLY);
  if (randD < 0) {
    printf("error\n");
    return 0;
  }
  else {
    int *number = malloc(sizeof(int));
    int result = read(randD, number, sizeof(number));
    if (result < 0) {
      printf("error\n");;
      return 0;
    }
    random = abs(*number);
    free(number);
  }
  int clo = close(randD);
  if (clo < 0) {
    printf("error\n");
    return 0;
  }
  return random%16 + 5;
}

int main(){
  printf("Parent info-> pid: %i ppid: %i\n",  getpid(), getppid());
  int f = fork();
  if (f == -1) {
    printf("error");
  }
  if (f != 0) { // if f returns a pid, parent
    f = fork(); 
  }
  if (f == 0) { // child
    printf("Child info-> pid: %i ppid: %i\n", getpid(), getppid());
    int time = myrand();
    printf("sleeping for %i sec...\n", time);
    sleep(time);
    printf("done sleeping\n");
    printf("Child %i exit\n", getpid());
    return time;
  }
  int childInfo;
  int pid = wait(&childInfo);
  int sec = WEXITSTATUS(childInfo);
  printf("Child %i slept for %i sec\n", pid, sec);
  printf("Parent %i exit\n", getpid());
  return 0;
}
