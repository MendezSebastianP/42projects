#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]) {
    struct stat fileStat;

    if (stat(argv[1], &fileStat) == -1)
        (perror("stat"), exit(EXIT_FAILURE));
    printf("File: %s\n", argv[1]);
    printf("Size: %lld bytes\n", (long long)fileStat.st_size);
    printf("Number of Blocks: %lld\n", (long long)fileStat.st_blocks);
    printf("Permissions: %o\n", fileStat.st_mode & 0777);
    printf("Last Access: %s", ctime(&fileStat.st_atime));
    printf("Last Modification: %s", ctime(&fileStat.st_mtime));
    printf("Last Status Change: %s", ctime(&fileStat.st_ctime));

    return 0;
}