#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int	main(int argc, char *argv[])
{
	execve(argv[1], argv + 2, NULL);
	perror("execve error");
	return (0);
}
