#include <stdio.h>
#include <unistd.h>
#include <string.h>
#define lenstring 12

int main() {
    int fd[2];
    char buffer[20];

    if (pipe(fd) == -1) { // ici on execute pipe
        perror("pipe");
        return (1);
    }
    write(fd[1], "Hello, Pipe!", lenstring);
    read(fd[0], buffer, lenstring);
    buffer[lenstring] = '\0';
    printf("Message lu : %s\n", buffer);
    return 0;
}
