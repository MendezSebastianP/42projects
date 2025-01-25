/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:41:53 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/25 17:11:23 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pid_here_doc(t_pipex *pip)
{
	char	**temp2;

	if (dup2(pip->fd[0][0], STDIN_FILENO) == -1)
		(perror("dup2"), exit(EXIT_FAILURE));
	if (dup2(pip->fd[1][1], STDOUT_FILENO) == -1)
		(perror("pid_pipe out"), exit(EXIT_FAILURE));
	ft_close_all(pip->fd);
	temp2 = ft_split(pip->v[3], ' ');
	execve(get_path_command(pip->path, no_args_cmd(pip->v[3])), temp2, NULL);
	(ft_printf_fd(2, "zsh: command not found: %s\n", temp2[0]));
	(free_pip(pip), exit(127));
}

void	pre_heredoc(t_pipex *pip)
{
	if (dup2(pip->fd[0][1], STDOUT_FILENO) == -1)
		(perror("dup2"), exit(EXIT_FAILURE));
	ft_close_all(pip->fd);
	ft_until_limiter(pip->v[2]);
	free_pip(pip);
	exit(0);
}

int	heredoc(int argc, t_pipex *pip)
{
	int	ret;

	if (pipe(pip->fd[0]) == -1)
		return (perror("pipe1"), 1);
	pip->pid[0] = fork();
	if (pip->pid[0] == 0)
		(pre_heredoc(pip));
	pip->fd = ft_add_fd(pip->fd, 1);
	waitpid(pip->pid[0], NULL, 0);
	if (pipe(pip->fd[1]) == -1)
		return (perror("pipe1"), 1);
	pip->pid[1] = fork();
	if (pip->pid[1] == 0)
		(pid_here_doc(pip));
	pip->pid[2] = fork();
	if (pip->pid[2] == 0)
		(pid1a(pip, argc - 1));
	(ft_close_all(pip->fd), ret = wait_all(pip->pid, 2));
	return (ret);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	*pip;
	int ret;

	if (argc < 5)
		return(0);
	pip = init_pipex(envp, argv, argc);
	if (ft_isequalstr(argv[1], "here_doc"))
	{
		ret = heredoc(argc, pip);
		free_pip(pip);
		return (ret);
	}
	ret = multi_pipex(pip, argc);
	return (ret);
}

// ./a.out test1.txt cat wc out.txt qui equivaut a
// < test1.txt cat | wc > out.txt
