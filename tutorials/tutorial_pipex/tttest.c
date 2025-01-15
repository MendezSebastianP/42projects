#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
    int fd[2];
    if (pipe(fd) == -1) {
        perror("pipe");
        return 1;
    }

    if (fork() == 0) {
        // Child: redirect standard output to the pipe
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        execve(argv[1], argv + 2, NULL);
        perror("execve"); // In case execve fails
        return 1;
    } else {
        // Parent: read the result from the pipe
        char buffer[1024];
        int nread;
        close(fd[1]);
        
        printf("Contenu du répertoire :\n");
        while ((nread = read(fd[0], buffer, sizeof(buffer) - 1)) > 0) {
            buffer[nread] = '\0'; // Null-terminate the string
            printf("%s", buffer); // Print the content
        }
        if (nread < 0) {
            perror("read"); // Handle read errors
        }
        
        close(fd[0]);
        wait(NULL); // Wait for the child process to finish
    }
    return 0;
}
