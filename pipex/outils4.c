/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:05:00 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/15 13:55:34 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pid0(int **fd1, char *argv[], char **paths, int i)
{
	char	**temp2;
	int		open_fd;
	int		*fd;

	fd = fd1[0];
	open_fd = open(argv[i + 1], O_RDONLY);
	if (dup2(open_fd, STDIN_FILENO) == -1)
		(perror("dup2"), exit(EXIT_FAILURE));
	close(open_fd);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		(perror("dup2"), exit(EXIT_FAILURE));
	ft_close_all(fd1);
	temp2 = ft_split(argv[i + 2], ' ');
	execve(get_path_command(paths, no_args_cmd(argv[i + 2])), temp2, NULL);
	perror("execve");
	free(temp2);
	exit(EXIT_FAILURE);
}

void	pid1(int **fd1, char *argv[], char **paths, int out)
{
	char	**temp2;
	int		fd_out;
	int		*fd2;
	int		i;

	i = 0;
	while (fd1[i])
		i++;
	fd2 = fd1[i - 1];
	if (dup2(fd2[0], STDIN_FILENO) == -1)
		(perror("dup2"), exit(EXIT_FAILURE));
	if (ft_isequalstr(argv[1], "here_doc"))
		fd_out = open(argv[out], O_APPEND | O_WRONLY | O_CREAT, 0644);
	else
		fd_out = open(argv[out], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2(fd_out, STDOUT_FILENO);
	close(fd_out);
	ft_close_all(fd1);
	temp2 = ft_split(argv[out - 1], ' ');
	execve(get_path_command(paths, no_args_cmd(argv[out - 1])), temp2, NULL);
	perror("execve");
	free(temp2);
	exit(EXIT_FAILURE);
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

void	wait_all(int *pid, int len)
{
	int	i;

	i = 0;
	while (i <= len)
	{
		waitpid(pid[i], NULL, 0);
		i++;
	}
}
