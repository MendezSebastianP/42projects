#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == -1) {
        // Error
        perror("fork failed");
    } else if (pid == 0) {
        // Child process
        printf("Child process. PID: %d\n", pid);
    } else {
        // Parent process
        printf("Parent process. Child PID: %d\n", pid);
        int status;
        pid_t child_pid = wait(&status);
        printf("Child process %d exited.\n", child_pid);
    }
    return 0;
}
