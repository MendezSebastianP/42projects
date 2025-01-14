/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:41:53 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/14 15:53:06 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


void	pid_pipe(int **fd1, char *argv[], char **paths, int i)
{
	char **temp2;
	int *fd;
	int *fd2;
	int k;

	k = 0;
	if (ft_isequalstr(argv[1], "here_doc"))
		k = 1;
	fd = fd1[i - 1 - k];
	fd2 = fd1[i - k];
	if (dup2(fd[0], STDIN_FILENO) == -1)
		(perror("pid_pipe out"), exit(EXIT_FAILURE));
	if (dup2(fd2[1], STDOUT_FILENO) == -1)
		(perror("pid_pipe out"), exit(EXIT_FAILURE));
	ft_close_all(fd1);
	temp2 = ft_split(argv[i + 2], ' ');
	execve(get_path_command(paths, no_args_cmd(argv[i + 2])), temp2, NULL);
	perror("execve");
	free(temp2);
	exit(EXIT_FAILURE);
}



int	main(int argc, char *argv[], char *envp[])
{
	int **fd;
	int pid[argc - 2];
	char **paths;
	int i;
	int j;

	i = 0;
	j = 0;
	if (ft_isequalstr(argv[1], "here_doc"))
		j = 1;
	fd = NULL;
	fd = ft_add_fd(fd, i);
	paths = get_path(envp);
	if (pipe(fd[i]) == -1)
		return (perror("pipe1"),1);
	pid[i] = fork();
	if (pid[i] == 0) 
		pid0(fd, argv, paths, i + j);
	while(i + j < argc - 5)
	{
		i++;
		fd = ft_add_fd(fd, i);
		if (pipe(fd[i]) == -1)
			return (perror("pipe1"),1);
		pid[i] = fork();
		if (pid[i] == 0) 
			pid_pipe(fd, argv, paths, i + j);
	}
	pid[i + 1] = fork();
	if (pid[i + 1] == 0) 
		pid1(fd, argv, paths, argc - 1);
	ft_close_all(fd);
	wait_all(pid, i + 1);
	cleanexit(paths);
	cleanexit2(fd);
	return (0);
}

// ./a.out test1.txt cat wc out.txt qui equivaut a
// < test1.txt cat | wc > out.txt




