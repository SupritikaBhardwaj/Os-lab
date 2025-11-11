#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid > 0) {
        printf("Parent Process (PID: %d) sleeping...\n", getpid());
        sleep(10);  // Parent child ka wait nahi karega
        printf("Parent woke up.\n");
    } 
    else if (pid == 0) {
        printf("Child Process (PID: %d) exiting...\n", getpid());
        exit(0);  // Child turant exit
    } 
    else {
        printf("Fork failed!\n");
    }

    return 0;
}
