#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>


int	main(int argc, char *argv[])
{
	int p = fork();
	if (p == 0)
	{
		execve(argv[1], argv + 2, NULL);
	perror("execve error");
	}
	else
	{
		wait(NULL);
		printf("number of arguments of our execve: %d\n", argc - 2);
	}
	printf("END\n");
	
	return (0);
} // ./a.out "/bin/ls" "/bin/ls" "-a"

/* int	main(int argc, char *argv[])
{
	execve(argv[1], argv + 2, NULL);
	perror("execve error");
	return (0);
} */
