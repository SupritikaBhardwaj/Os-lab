#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    } 
    else if (pid == 0) {
        printf("Child (PID: %d) executing ls -l:\n", getpid());
        execlp("ls", "ls", "-l", NULL);
        perror("execlp failed");
        exit(1);
    } 
   else {
    printf("Parent (PID: %d) waiting for child...\n", getpid());
    int status;
    wait(&status);
    printf("Parent finished waiting.\n");
}

    return 0;
}
