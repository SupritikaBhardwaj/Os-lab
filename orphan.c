#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid > 0) {
        printf("Parent Process (PID: %d) exiting...\n", getpid());
        exit(0);  // Parent turant exit kar gaya
    } 
    else if (pid == 0) {
        sleep(3);  // Child thoda late chalega
        printf("Child Process (PID: %d), New Parent PID: %d\n", getpid(), getppid());
    } 
    else {
        printf("Fork failed!\n");
    }

    return 0;
}
