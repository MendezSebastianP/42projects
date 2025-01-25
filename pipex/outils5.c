/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:21:13 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/25 17:30:29 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pid_pipe(t_pipex *pip, int i)
{
	char	**temp2;
	int		k;
	char	*no_a;
	char	*get_p;

	k = 0;
	if (ft_isequalstr(pip->v[1], "here_doc"))
		k = 1;
	if (dup2(pip->fd[i - 1 - k][0], STDIN_FILENO) == -1)
		(perror("pid_pipe out"), exit(EXIT_FAILURE));
	if (dup2(pip->fd[i - k][1], STDOUT_FILENO) == -1)
		(perror("pid_pipe out"), exit(EXIT_FAILURE));
	ft_close_all(pip->fd);
	temp2 = ft_split(pip->v[i + 2], ' ');
	no_a = no_args_cmd(pip->v[i + 2]);
	get_p = get_path_command(pip->path, no_a);
	execve(get_p, temp2, pip->envp);
	(ft_printf_fd(2, "zsh: command not found: %s\n", temp2[0]));
	(cleanexit(temp2), free_pip(pip), free(no_a), free(get_p), exit(127));
}

void	pipe_withcall(int *fd)
{
	if (pipe(fd) == -1)
		perror("pipe1");
}

int	multi_pipex(t_pipex *pip, int argc)
{
	int	i;

	i = 0;
	pipe_withcall(pip->fd[i]);
	pip->pid[i] = fork();
	if (pip->pid[i] == 0)
		pid0b(pip, i);
	while (i++ < argc - 5)
	{
		pip->fd = ft_add_fd(pip->fd, i);
		pipe_withcall(pip->fd[i]);
		pip->pid[i] = fork();
		if (pip->pid[i] == 0)
			(pid_pipe(pip, i));
	}
	pip->pid[i] = fork();
	if (pip->pid[i] == 0)
		pid1(pip, argc - 1);
	(ft_close_all(pip->fd), i = wait_all(pip->pid, i), cleanexit(pip->path));
	return (cleanexit2(pip->fd), free(pip->pid), free(pip), i);
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
