// Name: Johnny Xiaoming Huang
// Date: Jan 16, 2024
// Title: Lab2 - task 7
// Description: this program takes in an input as the time of delay in microsecond. The program also prints one parent process and one child process for 100 times, and call the ls command when the iteration finish.


#include <stdio.h>      /* printf, stderr */
#include <sys/types.h>  /* pid_t */
#include <unistd.h>     /* fork */
#include <stdlib.h>     /* atoi */
#include <errno.h>      /* errno */

/* main function with command-line arguments to pass */
int main(int argc, char *argv[]) {
    pid_t pid;
    int i, n = atoi(argv[1]); // n microseconds to input from keyboard for delay
    printf("\n Before forking.\n");
    pid = fork();
    if (pid == -1) {
        fprintf(stderr, "can't fork, error %d\n", errno);
    }

    if (pid){
        // Parent process
        for (i=0;i<100;i++) {
            printf("\t \t \t Parent Process %d \n",i);
            usleep(n);
        }
        wait(NULL);
        printf("Child Complete");
        exit(0);
    } else{
        // Child process
        for (i=0;i<100;i++) {
            printf("Child process %d\n",i);
            usleep(n);
        }
        execlp("/bin/ls", "ls", NULL);
    }
    return 0;
}