/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:41:53 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/15 13:35:57 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pid_here_doc(int **fd1, char *argv[], char **paths)
{
	char	**temp2;

	if (dup2(fd1[0][0], STDIN_FILENO) == -1)
		(perror("dup2"), exit(EXIT_FAILURE));
	if (dup2(fd1[1][1], STDOUT_FILENO) == -1)
		(perror("pid_pipe out"), exit(EXIT_FAILURE));
	ft_close_all(fd1);
	temp2 = ft_split(argv[3], ' ');
	execve(get_path_command(paths, no_args_cmd(argv[3])), temp2, NULL);
	perror("execve");
	free(temp2);
	exit(EXIT_FAILURE);
}

void	pre_heredoc(int **fd, char *argv[], char **paths)
{
	if (dup2(fd[0][1], STDOUT_FILENO) == -1)
		(perror("dup2"), exit(EXIT_FAILURE));
	ft_close_all(fd);
	ft_until_limiter(argv[2]);
	cleanexit(paths);
	cleanexit2(fd);
	exit(0);
}

int	heredoc(int argc, char *argv[], char *envp[], int **fd)
{
	int		*pid;
	char	**paths;

	fd = ft_add_fd(fd, 0);
	paths = get_path(envp);
	pid = malloc((argc - 2) * sizeof(int));
	if (!pid)
		return (0);
	if (pipe(fd[0]) == -1)
		return (perror("pipe1"), 1);
	pid[0] = fork();
	if (pid[0] == 0)
		(free(pid), pre_heredoc(fd, argv, paths));
	fd = ft_add_fd(fd, 1);
	if (pipe(fd[1]) == -1)
		return (perror("pipe1"), 1);
	pid[1] = fork();
	if (pid[1] == 0)
		pid_here_doc(fd, argv, paths);
	pid[2] = fork();
	if (pid[2] == 0)
		pid1(fd, argv, paths, argc - 1);
	(ft_close_all(fd), wait_all(pid, 2), cleanexit(paths));
	return (cleanexit2(fd), free(pid), 0);
}

int	main(int argc, char *argv[], char *envp[])
{
	char	**paths;
	int		**fd;

	fd = NULL;
	if (ft_isequalstr(argv[1], "here_doc"))
	{
		heredoc(argc, argv, envp, fd);
		return (0);
	}
	paths = get_path(envp);
	multi_pipex(argc, argv, paths, fd);
	return (0);
}

// ./a.out test1.txt cat wc out.txt qui equivaut a
// < test1.txt cat | wc > out.txt
