/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:41:53 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/13 11:59:34 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	char *path;

	i = 0;
	j = -1;
	while(j != 0 && paths[i])
	{
		temp = ft_strjoin(paths[i++], "/"); // il rajoute a chaque fois...
		temp = ft_strjoin(temp, command);
		j = access(temp, F_OK);
		path = ft_strdup(temp);
		free(temp);
	}
	if (j == 0)
		return (path);
	return (NULL);
}

char *no_args_cmd(char *cmd)
{
	int	i;
	int j;
	char *first_cmd;

	i = 0;
	j = 0;
	while(cmd[i] && cmd[i] != ' ')
		i++;
	if (ft_strlen(cmd) == i)
		return (cmd);
	first_cmd = malloc((i + 1) * sizeof(char));
	if (!first_cmd)
		return (NULL);
	while (j < i)
	{
		first_cmd[j] = cmd[j];
		j++;
	}
	first_cmd[j] = '\0';
	return (first_cmd);
}

void	perror_exit(char *msg)
{
	perror("ft_strjoin");
        exit(EXIT_FAILURE);
}

// void	pid0(int fd0, int fd1, char *argv[], char **paths)
// {
// 	char *temp;
// 	char *space;
// 	char **temp2;
	
// 	close(fd0);
// 	if (dup2(fd1, STDOUT_FILENO) == -1)
// 		(perror("dup2"), exit(EXIT_FAILURE));
// 	close(fd1);
// 	space = ft_strjoin(" ", argv[1]);
// 	temp = ft_strjoin(argv[2], space);
// 	free(space);
// 	temp2 = ft_split(temp, ' ');
// 	free(temp);
// 	execve(get_path_command(paths, no_args_cmd(argv[2])), temp2, NULL);
// 	perror("execve");
// 	free(temp2);
// 	exit(EXIT_FAILURE);
// }

void	pid0(int *fd, char *argv[], char **paths)
{
	char **temp2;
	int open_fd;

	open_fd = open(argv[1], O_RDONLY);
	if (dup2(open_fd, STDIN_FILENO) == -1)
		(perror("dup2"), exit(EXIT_FAILURE));
	close(open_fd);
	close(fd[0]);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		(perror("dup2"), exit(EXIT_FAILURE));
	close(fd[1]);
	temp2 = ft_split(argv[2], ' ');
	execve(get_path_command(paths, no_args_cmd(argv[2])), temp2, NULL);
	perror("execve");
	free(temp2);
	exit(EXIT_FAILURE);
}

void	pid_pipe(int *fd, int *fd2, char *argv[], char **paths)
{
	char **temp2;

	if (dup2(fd[0], STDIN_FILENO) == -1)
		(perror("pid_pipe out"), exit(EXIT_FAILURE));
	if (dup2(fd2[1], STDOUT_FILENO) == -1)
		(perror("pid_pipe out"), exit(EXIT_FAILURE));
	close(fd[0]);
	close(fd[1]);
	close(fd2[0]);
	close(fd2[1]);
	temp2 = ft_split(argv[3], ' ');
	execve(get_path_command(paths, no_args_cmd(argv[3])), temp2, NULL);
	perror("execve");
	free(temp2);
	exit(EXIT_FAILURE);
}

void	pid1(int *fd2, int *fd, char *argv[], char **paths)
{
	char **temp2;
	int fd_out;

	close(fd[0]);
	close(fd[1]);
	if (dup2(fd2[0], STDIN_FILENO) == -1)
		(perror("dup2"), exit(EXIT_FAILURE));
	fd_out = open(argv[5],  O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2(fd_out, STDOUT_FILENO);
	close(fd_out);
	close(fd2[0]);
	close(fd2[1]);
	temp2 = ft_split(argv[4], ' ');
	execve(get_path_command(paths, no_args_cmd(argv[4])), temp2, NULL);
	perror("execve");
	free(temp2);
	exit(EXIT_FAILURE);
}

char	**cleanexit2(int **a)
{
	int	i;

	i = 0;
	while (a[i])
	{
		free(a[i]);
		i++;
	}
	free(a);
	return (NULL);
}

int	**ft_add_fd(int **fd, int len)
{
	int **new_fd;
	int *temp;
	int len_fd;
	int i;

	i = 0;
	new_fd = calloc(i + 2, sizeof(int*));
	if (!new_fd)
		return (NULL);
	
	if (!fd)
		fd = calloc(2, sizeof(int*));
	while(fd[i])
		i++;
	
	temp = malloc(2 * sizeof(int));
	if (!temp)
		return (NULL);
	temp[2] = 0;
	i = 0;
	while(fd[i])
	{
		new_fd[i] = fd[i];
		i++;
	}
	new_fd[i] = temp;
	return (free(fd),new_fd);
}

int	main(int argc, char *argv[], char *envp[])
{
	int **fd;
	int pid[3];
	char **paths;
	int i;

	i = 0;
	fd = NULL;
	fd = ft_add_fd(fd);
	paths = get_path(envp);
	if (pipe(fd[0]) == -1)
		return (perror("pipe1"),1);
	printf("fd0 %d | fd1 %d\n", fd[0][0], fd[0][1]);
	pid[0] = fork();
	if (pid[0] == 0) 
		pid0(fd[0], argv, paths);
	fd = ft_add_fd(fd);
	// i++;
	if (pipe(fd[1]) == -1)
		return (perror("pipe1"),1);
	printf("fd0 %d | fd1 %d\n", fd[1][0], fd[1][1]);
	pid[1] = fork();
	if (pid[1] == 0) 
		pid_pipe(fd[0], fd[1], argv, paths);
	pid[2] = fork();
	if (pid[2] == 0) 
		pid1(fd[1], fd[0], argv, paths);
	(close(fd[0][0]), close(fd[0][1]));
	(close(fd[1][0]), close(fd[1][1]));
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], NULL, 0);
	waitpid(pid[2], NULL, 0);
	cleanexit(paths);
	return (0);
}

// ./a.out test1.txt cat wc out.txt qui equivaut a
// < test1.txt cat | wc > out.txt




