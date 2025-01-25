/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:05:00 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/25 11:59:32 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* void	pid0(int **fd1, char *argv[], char **envp, int i)
{
	char	**temp2;
	char	**paths;
	int		open_fd;
	int		*fd;

	fd = fd1[0];
	paths = ft_split("error env", ' ');
	if (envp[0] && envp[0][0] != 'V')
		(cleanexit(paths), paths = get_path(envp));
	if (access(argv[i + 1], R_OK) == -1)
	{
		(ft_close_all(fd1), cleanexit2(fd1), cleanexit(paths));
		write(2, "zsh: permission denied: test/no_read\n", 37);
		exit(EXIT_FAILURE);
	}
	open_fd = open(argv[i + 1], O_RDONLY);
	if (dup2(open_fd, STDIN_FILENO) == -1)
		(perror("dup2"), exit(EXIT_FAILURE));
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		(perror("dup2"), exit(EXIT_FAILURE));
	(ft_close_all(fd1), close(open_fd));
	temp2 = ft_split(argv[i + 2], ' ');
	execve(get_path_command(paths, no_args_cmd(argv[i + 2])), temp2, envp);
	(ft_printf_fd(2, "zsh: command not found: %s\n", temp2[0]),
		cleanexit(temp2), exit(127));
} */

void	pid0(t_pipex *pip, int i)
{
	char	**temp2;
	int		open_fd;
	char	*no_a;
	char	*get_p;

	if (access(pip->argv[i + 1], R_OK) == -1)
	{
		write(2, "zsh: permission denied: test/no_read\n", 37);
		(free_pip(pip), exit(EXIT_FAILURE));
	}
	open_fd = open(pip->argv[i + 1], O_RDONLY);
	if (dup2(open_fd, STDIN_FILENO) == -1)
		(perror("dup2"), exit(EXIT_FAILURE));
	if (dup2(pip->fd[0][1], STDOUT_FILENO) == -1)
		(perror("dup2"), exit(EXIT_FAILURE));
	(ft_close_all(pip->fd), close(open_fd));
	temp2 = ft_split(pip->argv[i + 2], ' ');
	no_a = no_args_cmd(pip->argv[i + 2]);
	get_p = get_path_command(pip->path, no_a);
	execve(get_p, temp2, pip->envp);
	ft_printf_fd(2, "zsh: command not found: %s\n", temp2[0]);
	(cleanexit(temp2), free_pip(pip), free(no_a), free(get_p), exit(127));
}

void	pid1(int **fd1, char *v[], char **envp, int out)
{
	char	**t;
	char	**paths;
	int		fd_out;
	int		*fd2;
	int		i;

	paths = ft_split("error env", ' ');
	if (envp[0] && envp[0][0] != 'V')
		(cleanexit(paths), paths = get_path(envp));
	if (access(v[out], F_OK) == 0 && access(v[out], W_OK) == -1)
	{
		(ft_close_all(fd1), cleanexit2(fd1), cleanexit(paths));
		write(2, "zsh: permission denied: test/no_write\n", 38);
		exit(EXIT_FAILURE);
	}
	i = lvl2_len(fd1);
	fd2 = fd1[i - 1];
	if (dup2(fd2[0], STDIN_FILENO) == -1)
		(perror("dup2"), exit(EXIT_FAILURE));
	fd_out = open(v[out], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	(dup2(fd_out, STDOUT_FILENO), close(fd_out), ft_close_all(fd1));
	t = ft_split(v[out - 1], ' ');
	execve(get_path_command(paths, no_args_cmd(v[out - 1])), t, envp);
	ft_printf_fd(2, "zsh: command not found: %s\n", t[0]);
	(cleanexit2(fd1), cleanexit(paths), cleanexit(t), exit(127));
}

char	*cleanexit2(int **a)
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
	int	**new_fd;
	int	i;

	i = 0;
	new_fd = malloc((len + 2) * sizeof(int *));
	if (!new_fd)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_fd[i] = fd[i];
		i++;
	}
	new_fd[i++] = malloc(2 * sizeof(int));
	new_fd[i] = NULL;
	return (free(fd), new_fd);
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
