/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:21:13 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/23 15:27:24 by smendez-         ###   ########.fr       */
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
	(ft_printf_fd(2, "zsh: command not found: %s\n", temp2[0]),
		c_all(fd1, paths, NULL), cleanexit(temp2), exit(127));
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
		pid0b(fd, argv, paths, i);
	while (i++ < argc - 5)
	{
		fd = ft_add_fd(fd, i);
		pipe_withcall(fd[i]);
		pid[i] = fork();
		if (pid[i] == 0)
			(free(pid), pid_pipe(fd, argv, paths, i));
	}
	pid[i] = fork();
	if (pid[i] == 0)
		pid1b(fd, argv, paths, argc - 1);
	(ft_close_all(fd), wait_all(pid, i), cleanexit(paths));
	return (cleanexit2(fd), free(pid), 0);
}

int	lvl2_len(int **fd)
{
	int	i;

	i = 0;
	while (fd[i])
		i++;
	return (i);
}

void	c_all(int **fd, char **paths, int *pid)
{
	if (fd)
	{
		ft_close_all(fd);
		cleanexit2(fd);
	}
	if (paths)
		cleanexit(paths);
	if (pid)
		free(pid);
}
