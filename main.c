
/* Catch the following signals */
/* SIGINT */
/* Before exiting, append a message to a file noting that the program exited due to SIGINT */
/* To make your program quit, look up the exit function. */
/* SIGUSR1 */
/* Print out the PID of the parent process. */
/* Should not cause the program to exit. */


#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
static void sighandler(int signo) {
  if(signo == SIGINT) {
    printf("bye bye. exited due to SIGINT\n");
    exit(0);
  } 
  else if (signo == SIGUSR1) 
    printf("parent pid: %d\n", getppid());
}


int main() {
  
  signal(SIGUSR1, sighandler);
  signal(SIGINT, sighandler);
  while(1){
    printf("hello, I am: %d\n", getpid());
    sleep(1);
  }
  return 0;
}
