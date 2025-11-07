#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2;

    pid1 = fork();

    if (pid1 < 0) {
        printf("Fork failed!\n");
        exit(1);
    }
    else if (pid1 == 0) {
        printf("First Child: PID = %d, Parent PID = %d\n", getpid(), getppid());
        sleep(3);
        printf("First Child Finished.\n");
        exit(0);
    }
    else {
        wait(NULL);
        printf("Parent: First child completed.\n");

        pid2 = fork();
        if (pid2 < 0) {
            printf("Fork failed!\n");
            exit(1);
        }
        else if (pid2 == 0) {
            printf("Second Child: PID = %d, Parent PID = %d\n", getpid(), getppid());
            sleep(5);
            printf("Second Child Finished.\n");
            exit(0);
        }
        else {
            printf("Parent exiting before second child finishes.\n");
            exit(0);
        }
    }
}
