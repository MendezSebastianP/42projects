/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:24:26 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/23 12:11:57 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pid0b(int **fd1, char *argv[], char **paths, int i)
{
	char	**temp2;
	int		open_fd;
	int		*fd;

	fd = fd1[0];
	if (access(argv[i + 1], R_OK) == -1)
	{
		(ft_close_all(fd1), cleanexit2(fd1), cleanexit(paths));
		write(2, "zsh: permission denied: test/no_read\n", 37);
		exit(EXIT_FAILURE);
	}
	open_fd = open(argv[i + 1], O_RDONLY);
	if (dup2(open_fd, STDIN_FILENO) == -1)
		(perror("dup2"), exit(EXIT_FAILURE));
	close(open_fd);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		(perror("dup2"), exit(EXIT_FAILURE));
	ft_close_all(fd1);
	temp2 = ft_split(argv[i + 2], ' ');
	execve(get_path_command(paths, no_args_cmd(argv[i + 2])), temp2, NULL);
	(ft_printf_fd(2, "zsh: command not found: %s\n", temp2[0]),
		cleanexit(temp2), exit(127));
}

void	pid1b(int **fd1, char *v[], char **paths, int out)
{
	char	**t;
	int		fd_out;
	int		*fd2;
	int		i;

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
	if (ft_isequalstr(v[1], "here_doc"))
		fd_out = open(v[out], O_APPEND | O_WRONLY | O_CREAT, 0644);
	else
		fd_out = open(v[out], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	(dup2(fd_out, STDOUT_FILENO), close(fd_out), ft_close_all(fd1));
	t = ft_split(v[out - 1], ' ');
	execve(get_path_command(paths, no_args_cmd(v[out - 1])), t, NULL);
	(cleanexit2(fd1), cleanexit(paths));
	(ft_printf_fd(2, "zsh: command not found: %s\n", t[0]),
		cleanexit(t), exit(127));
}
