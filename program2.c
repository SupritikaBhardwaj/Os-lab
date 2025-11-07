#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;
    pid = fork();

    if (pid < 0) {
        printf("Fork failed!\n");
    }
    else if (pid == 0) {
        printf("Child Process:\n");
        printf("   My PID is %d\n", getpid());
        printf("   My Parent's PID is %d\n", getppid());
    }
    else {
        printf("Parent Process:\n");
        printf("   My PID is %d\n", getpid());
        printf("   My Child's PID is %d\n", pid);
    }

    return 0;
}
