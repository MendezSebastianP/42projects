/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:21:13 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/15 13:25:11 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pid_pipe(int **fd1, char *argv[], char **paths, int i)
{
	char	**temp2;
	int		*fd;
	int		*fd2;
	int		k;

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

void	pipe_withcall(int *fd)
{
	if (pipe(fd) == -1)
		perror("pipe1");
}

int	multi_pipex(int argc, char *argv[], char **paths, int **fd)
{
	int	*pid;
	int	i;

	i = 0;
	pid = malloc((argc - 2) * sizeof(int));
	if (!pid)
		return (0);
	fd = ft_add_fd(fd, i);
	pipe_withcall(fd[i]);
	pid[i] = fork();
	if (pid[i] == 0)
		pid0(fd, argv, paths, i);
	while (i++ < argc - 5)
	{
		fd = ft_add_fd(fd, i);
		pipe_withcall(fd[i]);
		pid[i] = fork();
		if (pid[i] == 0)
			pid_pipe(fd, argv, paths, i);
	}
	pid[i] = fork();
	if (pid[i] == 0)
		pid1(fd, argv, paths, argc - 1);
	(ft_close_all(fd), wait_all(pid, i), cleanexit(paths));
	return (cleanexit2(fd), free(pid), 0);
}
