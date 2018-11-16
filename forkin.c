#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
int myrand() {
  int randD = open("/dev/random", O_RDONLY);
  if(randD < 0)
    return 0;
  else {
    unsigned int *number = calloc(1, sizeof(int));
    int result = read(randD, number, sizeof number);
    if (result < 0)
      return 0;
    return *number;
  }
}
void forkexample() 
{ 
    // child process because return value zero 
    if (fork() == 0) 
        printf("Hello from Child!\n"); 
  
    // parent process because return value non-zero. 
    else
        printf("Hello from Parent!\n"); 
} 


int main(){
  int f1 = fork();
  if (f1 == -1) {
    printf("error");
  } else if(f1) { // if f1 is a pid
    f1 = fork();
    printf("Parent of %i. pid: %i ppid: %i\n", f1, getpid(), getppid());
    
  } else { // if f1 == 0
    printf("I am a child. pid: %i ppid: %i\n", getpid(), getppid());
    /* printf("sleeping...\n"); */
    /* sleep(5 + myrand() % 15); */
    /* printf("done sleeping\n"); */
  }
  return 0;
}
