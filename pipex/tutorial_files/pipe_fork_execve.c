#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int fd[2];
     if (pipe(fd) == -1) {
        perror("pipe");
        return (1);

    if (fork() == 0) {
        // Enfant : redirige la sortie standard vers le pipe
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        execve(argv[1], argv + 2, NULL);
    } else {
        // Parent : lit le résultat de "ls"
        char buffer[1024];
        close(fd[1]);
        read(fd[0], buffer, sizeof(buffer));
        printf("Contenu du répertoire :\n%s", buffer);
    }

    return 0;
}
