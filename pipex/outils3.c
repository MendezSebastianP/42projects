/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:04:53 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/15 13:54:49 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_home(char *envp[])
{
	int		i;
	int		j;
	char	*p1;

	i = 0;
	p1 = "HOME=";
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] == p1[j])
			j++;
		if (j == 5)
			return (envp[i] + j);
		i++;
	}
	return (NULL);
}

char	**get_path(char *envp[])
{
	int		i;
	int		j;
	char	*p1;
	char	**path1;

	i = 0;
	p1 = "PATH=";
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] == p1[j])
			j++;
		if (j == 5)
		{
			path1 = ft_split(envp[i] + j, ':');
			return (path1);
		}
		i++;
	}
	return (NULL);
}

char	*get_path_command(char **paths, char *command)
{
	int		i;
	int		j;
	char	*temp;
	char	*path;

	i = 0;
	j = -1;
	while (j != 0 && paths[i])
	{
		temp = ft_strjoin(paths[i++], "/");
		temp = ft_strjoin(temp, command);
		j = access(temp, F_OK);
		path = ft_strdup(temp);
		free(temp);
	}
	if (j == 0)
		return (path);
	return (NULL);
}

char	*no_args_cmd(char *cmd)
{
	int		i;
	int		j;
	char	*first_cmd;

	i = 0;
	j = 0;
	while (cmd[i] && cmd[i] != ' ')
		i++;
	if (ft_strlen(cmd) == (size_t)i)
		return (cmd);
	first_cmd = malloc((i + 1) * sizeof(char));
	if (!first_cmd)
		return (NULL);
	while (j < i)
	{
		first_cmd[j] = cmd[j];
		j++;
	}
	first_cmd[j] = '\0';
	return (first_cmd);
}

void	perror_exit(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}
