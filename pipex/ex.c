#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Code exécuté par l'enfant
        char *args[] = {"/usr/bin/env", NULL};  // Affiche les variables d'environnement
        char *envp[] = {"MY_VAR=Hello", "ANOTHER_VAR=World", NULL};  // Variables d'environnement
        execve(args[0], args, envp);
        perror("execve échoué");
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        wait(NULL);  // Attend la fin de l'enfant
    } else {
        perror("Erreur lors de fork");
    }

    return 0;
}
