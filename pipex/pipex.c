/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:41:53 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/14 15:49:13 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int **fd;
	int pid[argc - 2];
	char **paths;
	int i;

	i = 0;
	fd = NULL;
	fd = ft_add_fd(fd, i);
	paths = get_path(envp);
	if (pipe(fd[i]) == -1)
		return (perror("pipe1"),1);
	pid[i] = fork();
	if (pid[i] == 0) 
		pid0(fd, argv, paths, i);
	pid[i + 1] = fork();
	if (pid[i + 1] == 0) 
		pid1(fd, argv, paths, argc - 1);
	ft_close_all(fd);
	wait_all(pid, i + 1);
	cleanexit(paths);
	cleanexit2(fd);
	return (0);
}

// ./a.out test1.txt cat wc out.txt qui equivaut a
// < test1.txt cat | wc > out.txt




