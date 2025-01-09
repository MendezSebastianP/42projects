#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

void error_exit(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

/* int main(int argc, char *argv[]) {
    int pipe1[2];

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if (pipe(pipe1) == -1) {
        error_exit("pipe");
    }
    pid_t pid1 = fork();
    if (pid1 == -1) {
        error_exit("fork");
    }

    if (pid1 == 0) { 
        close(pipe1[0]); 
        dup2(pipe1[1], STDOUT_FILENO); 
        close(pipe1[1]); 
        char *cat_args[] = {"/bin/cat", argv[1], NULL};
        execve("/bin/cat", cat_args, NULL);
        error_exit("execve (cat)"); // If execve fails
    }

    pid_t pid2 = fork();
    if (pid2 == -1) {
        error_exit("fork");
    }

    if (pid2 == 0) { // Child process 2: `wc`
        close(pipe1[1]); // Close write end of the pipe
        dup2(pipe1[0], STDIN_FILENO); // Redirect stdin to pipe's read end
        close(pipe1[0]); // Close the read end after redirection

        // Execute `wc`
        char *wc_args[] = {"/usr/bin/wc", NULL};
        execve("/usr/bin/wc", wc_args, NULL);
        error_exit("execve (wc)"); // If execve fails
    }

    // Parent process: Close both ends of the pipe
    close(pipe1[0]);
    close(pipe1[1]);

    // Wait for both children to finish
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    return 0;
}
 */