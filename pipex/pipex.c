/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:41:53 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/25 12:02:07 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* int	main(int argc, char *argv[], char *envp[])
{
	int		**fd;
	int		*pid;
	int		i;

	if (argc < 5)
		return(0);
	i = 0;
	fd = NULL;
	fd = ft_add_fd(fd, i);
	pid = malloc((argc - 2) * sizeof(int));
	if (!pid)
		return (0);
	if (pipe(fd[i]) == -1)
		return (perror("pipe1"), 1);
	pid[i] = fork();
	if (pid[i] == 0)
		(free(pid), pid0(fd, argv, envp, i));
	pid[i + 1] = fork();
	if (pid[i + 1] == 0)
		(free(pid), pid1(fd, argv, envp, argc - 1));
	ft_close_all(fd);
	i = wait_all(pid, i + 1);
	return (cleanexit2(fd), free(pid), i);
} */

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex		*pip;
	int		i;

	if (argc < 5)
		return(0);
	i = 0;
	pip = init_pipex(envp, argv, argc);
	if (pipe(pip->fd[0]) == -1)
		return (perror("pipe1"), 1);
	pip->pid[i] = fork();
	if (pip->pid[0] == 0)
		(pid0(pip, i));
	pip->pid[i + 1] = fork();
	if (pip->pid[1] == 0)
		(free(pip->pid), pid1(pip->fd, argv, envp, argc - 1));
	ft_close_all(pip->fd);
	i = wait_all(pip->pid, 1);
	return (free_pip(pip), i);
}

// ./a.out test1.txt cat wc out.txt qui equivaut a
// < test1.txt cat | wc > out.txt
