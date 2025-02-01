#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>

int main(void) {
    DIR *dir;
    struct dirent *entry;

    dir = opendir(".");
    if (dir == NULL) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    while ((entry = readdir(dir)) != NULL)
    {
        if (entry->d_type == DT_REG)
            printf("File: %s\n", entry->d_name);
        else if (entry->d_type == DT_DIR)
            printf("Directory: %s\n", entry->d_name);
    }

    closedir(dir);
    return EXIT_SUCCESS;
}
