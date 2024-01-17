// Name: Johnny Xiaoming Huang
// Date: Jan 16, 2024
// Title: Lab2 - task 6
// Description: this program takes in an input as the time of delay in microsecond. The program also prints one parent thread and one child thread for 100 times.

/*Sample C program for Lab assignment 1*/
#include <stdio.h>      /* printf, stderr */
#include <sys/types.h>  /* pid_t */
#include <unistd.h>     /* fork */
#include <stdlib.h>     /* atoi */
#include <errno.h>      /* errno */
#include <pthread.h>
// int pthread_create(pthread_t *thread, pthread_attr_t *attr, void *(*start_routine) (void *arg), void *arg);

void *parent(void *i){
    int j;
    int n = *((int *) i);
    for(j=0; j<100; j++){
        printf("\t \t \t Parent thread%d \n", j);
        usleep(n);
    }
    pthread_exit(NULL);

}

void *child(void *i){
    int j;
    int n = *((int *) i);;
    for(j=0; j<100; j++){
        printf("Child thread%d \n", j);
        usleep(n);
    }
    pthread_exit(NULL);
}


/* main function with command-line arguments to pass */
int main(int argc, char *argv[]) {
    int n = atoi(argv[1]); // n microseconds to input from keyboard for delay
    pthread_t parentThread, childThread;

    if (pthread_create(&parentThread, NULL, parent, &n) != 0) {
        perror("Failed to create parent thread");
        return 1;
    }
    if (pthread_create(&childThread, NULL, child, &n) != 0) {
        perror("Failed to create child thread");
        return 1;
    }   

    pthread_join(parentThread, NULL);
    pthread_join(childThread, NULL);
    return 0;
}