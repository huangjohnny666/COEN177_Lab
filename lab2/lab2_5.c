// Name: Johnny Xiaoming Huang
// Date: Jan 16, 2024
// Title: Lab2 - task 7
// Description: this program takes in an input as the time of delay in microsecond, and generate exactly 7 processes, and each process has 2 or no children. then the program will print the parent and child processes consequently.


#include <stdio.h>      /* printf, stderr */
#include <sys/types.h>  /* pid_t */
#include <unistd.h>     /* fork */
#include <stdlib.h>     /* atoi */
#include <errno.h>      /* errno */
#include <sys/wait.h>   /* wait */

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <delay in microseconds>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    pid_t pid1, pid2, pid1_1, pid1_2, pid2_1, pid2_2;

    printf("\n Before forking.\n");
    printf("Parent Process %d\n", getpid());

    pid1 = fork();
    if (pid1 == 0) {
        // First child process
        printf("First Child Process: %d from Parent Process: %d\n", getpid(), getppid());
        usleep(n);

        pid1_1 = fork();
        if (pid1_1 == 0) {
            printf("Grandchild 1: %d from First Child Process: %d\n", getpid(), getppid());
            exit(0);
        }

        pid1_2 = fork();
        if (pid1_2 == 0) {
            printf("Grandchild 2: %d from First Child Process: %d\n", getpid(), getppid());
            exit(0);
        }

        wait(NULL);
        wait(NULL);
        exit(0);
    } else {
        pid2 = fork();
        if (pid2 == 0) {
            // Second child process
            printf("Second Child Process: %d from Parent Process: %d\n", getpid(), getppid());
            usleep(n);

            pid2_1 = fork();
            if (pid2_1 == 0) {
                printf("Grandchild 3: %d from Second Child Process: %d\n", getpid(), getppid());
                exit(0);
            }

            pid2_2 = fork();
            if (pid2_2 == 0) {
                printf("Grandchild 4: %d from Second Child Process: %d\n", getpid(), getppid());
                exit(0);
            }

            wait(NULL);
            wait(NULL);
            exit(0);
        }

        // Parent process waits for the two child processes
        wait(NULL);
        wait(NULL);
    }
    return 0;
}