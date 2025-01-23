/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:41:53 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/23 15:40:10 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
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
}

// ./a.out test1.txt cat wc out.txt qui equivaut a
// < test1.txt cat | wc > out.txt
