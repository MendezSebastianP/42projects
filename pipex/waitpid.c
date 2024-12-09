#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Code du processus enfant
        printf("Enfant : Je m'endors 2 secondes...\n");
        sleep(2);
        printf("Enfant : Fin du processus enfant.\n");
        return 42;
    } else {
        // Code du processus parent
        int status;
        printf("Parent : En attente de l'enfant...\n");
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            printf("Parent : L'enfant a terminé avec le retour %d.\n",
	     WEXITSTATUS(status));
        }
    }

    return 0;
}
