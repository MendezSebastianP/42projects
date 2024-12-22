#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    const char *temp_file = "temp.txt";
    char buffer1[1000];
    char buffer2[1000];
    char buffer3[1000];

    int fd = open(temp_file, O_CREAT | O_RDWR, 0644);
    if (fd == -1) {
        perror("Erreur lors de la création du fichier");
        return 1;
    }
    if (unlink(temp_file) == 0) {
        printf("Fichier temporaire supprimé du système de fichiers.\n");
    } else {
        perror("Erreur lors de la suppression du fichier");
    }
    lseek(fd, 0, SEEK_SET); // remet le read au debut
    int a1 = read(fd, buffer1,1);
    printf("empty execution: %s\n", buffer1);
    write(fd, "Hello, world!\n", 14);
    lseek(fd, 0, SEEK_SET); // remet le read au debut
    int a2 = read(fd, buffer2,14);
    buffer2[14] = '\0';
    printf("first add: %s\n", buffer2);
    write(fd, "This is my writing still\n", 24);
    lseek(fd, 0, SEEK_SET); // remet le read au debut
    int a3 = read(fd, buffer3, 38);
    buffer3[38] = '\0';
    printf("second add: %s\n", buffer3);
    close(fd);
    printf("Fichier temporaire désormais inaccessible.\n");
    return 0;
}