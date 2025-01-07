/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:41:53 by smendez-          #+#    #+#             */
/*   Updated: 2024/12/23 18:13:22 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"



/* int	main(int argc, char *argv[]) 
{
	int fd[2];
	int pid[2];
	int fd_out;
	char	*cmd1;
	
	if (pipe(fd) == -1)
	{
		perror("pipe");
		return (1);
	}
	pid[0] = fork();
	if (pid[0] == 0) 
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		char *cat_args[] = {argv[1], argv[3], NULL};
		execve(argv[1], cat_args, NULL);
		perror("execve (cat)");
        exit(1);
	} 
	pid[1] = fork();
	if (pid[1] == 0) 
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		fd_out = open(argv[4], O_RDWR);
		dup2(fd_out, STDOUT_FILENO);
		char *wc_args[] = {argv[2], NULL}; // e.g., {"wc", NULL}

		// Execute `wc`
		execve(argv[2], wc_args, NULL);
		perror("execve (wc)");
        exit(1);
	} 
	close(fd[0]);
	close(fd[1]);
	close(fd_out);
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], NULL, 0);
	return (0);
} */

char	*get_home(char *envp[])
{
	int i;
	int j;
	char *env_variable;
	char *p1;

	i = 0;
	p1 = "HOME=";
	while(envp[i])
	{
		j = 0;
		while(envp[i][j] == p1[j])
			j++;
		if (j == 5)
			return (envp[i] + j);
		i++;
	}
	return(NULL);
}

char	**get_path(char *envp[])
{
	int i;
	int j;
	char *env_variable;
	char *p1;
	char **path1;

	i = 0;
	p1 = "PATH=";
	while(envp[i])
	{
		j = 0;
		while(envp[i][j] == p1[j])
			j++;
		if (j == 5)
		{
			path1 = ft_split(envp[i] + j, ':');
			return(path1);
		}
		i++;
	}
	return(NULL);
}

char *get_path_command(char **paths, char *command)
{
	int i;
	int j;
	char *temp;

	i = 0;
	j = 0;
	while(j == 0 && paths[i])
	{
		temp = ft_strjoin(paths[i++], "\\"); // il rajoute a chaque fois...
		temp = ft_strjoin(temp, command);
		j = access(temp, F_OK);
	}
	if (j == 0)
		return (temp);
	free(temp);
	return (NULL);
}

/* int main(int argc, char *argv[], char *envp[])
{
	char **test;
	int i = 0;

	test = get_path(envp);
	while(test[i])
	{
		printf("%s\n", test[i++]);
	}
	i = 0;
	while(test[i])
		free(test[i++]);
	free(test);
	return (0);
} */
int main(int argc, char *argv[], char *envp[])
{
	char **test;
	int i = 0;

	test = get_path(envp);
	printf("%s\n", get_path_command(test, argv[1]));
	return (0);
}

// ./a.out /bin/cat /usr/bin/wc test1.txt out.txt qui equivaut a
// < test1.txt cat | wc > out.txt
