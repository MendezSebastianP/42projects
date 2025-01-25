/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:24:26 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/25 17:31:35 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pid0b(t_pipex *pip, int i)
{
	char	**temp2;
	int		open_fd;
	char	*no_a;
	char	*get_p;

	if (access(pip->v[i + 1], R_OK) == -1)
	{
		write(2, "zsh: permission denied: test/no_read\n", 37);
		(free_pip(pip), exit(EXIT_FAILURE));
	}
	open_fd = open(pip->v[i + 1], O_RDONLY);
	if (dup2(open_fd, STDIN_FILENO) == -1)
		(perror("dup2"), exit(EXIT_FAILURE));
	close(open_fd);
	if (dup2(pip->fd[0][1], STDOUT_FILENO) == -1)
		(perror("dup2"), exit(EXIT_FAILURE));
	ft_close_all(pip->fd);
	temp2 = ft_split(pip->v[i + 2], ' ');
	no_a = no_args_cmd(pip->v[i + 2]);
	get_p = get_path_command(pip->path, no_a);
	execve(get_p, temp2, pip->envp);
	(ft_printf_fd(2, "zsh: command not found: %s\n", temp2[0]), free(no_a));
	(free(get_p), cleanexit(temp2), free_pip(pip), exit(127));
}

t_pipex	*init_pipex(char **envp, char **argv, int argc)
{
	t_pipex	*pipex;

	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		return (NULL);
	pipex->envp = envp;
	pipex->v = argv;
	pipex->fd = NULL;
	pipex->fd = ft_add_fd(pipex->fd, 0);
	if (!pipex->fd)
	{
		free(pipex);
		return (NULL);
	}
	pipex->path = NULL;
	pipex->pid = malloc((argc - 2) * sizeof(int));
	if (!pipex->pid)
		return (free(pipex), NULL);
	pipex->path = ft_split("error env", ' ');
	if (pipex->envp[0] && pipex->envp[0][0] != 'V')
	{
		cleanexit(pipex->path);
		pipex->path = get_path(pipex->envp);
	}
	return (pipex);
}

void	free_pip(t_pipex *pip)
{
	ft_close_all(pip->fd);
	cleanexit2(pip->fd);
	cleanexit(pip->path);
	free(pip->pid);
	free(pip);
}

int	wait_all(int *pid, int len)
{
	int	i;
	int	k;
	int	rn;

	i = 0;
	k = 0;
	rn = 0;
	while (i <= len)
	{
		waitpid(pid[i], &k, 0);
		i++;
	}
	rn = k >> 8;
	return (rn);
}
