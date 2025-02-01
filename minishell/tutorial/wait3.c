#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/resource.h>
#include <unistd.h>

int main(void) {
    pid_t pid;
    int status;
    struct rusage usage;

    pid = fork();
    if (pid == 0) {
        printf("Child (wait3 example): PID = %d\n", getpid());
        sleep(1);
        exit(42);
    } else {
        pid_t wpid = wait3(&status, 0, &usage);
        if (wpid == -1) {
            (perror("wait3"), exit(EXIT_FAILURE));
        }
        printf("Parent (wait3): Child %d exited with status %d\n", wpid, WEXITSTATUS(status));
        printf("User CPU time (wait3): %ld sec\n", usage.ru_utime.tv_sec);
    }
    return 0;
}
