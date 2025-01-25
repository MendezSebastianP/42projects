/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:04:53 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/25 15:12:25 by smendez-         ###   ########.fr       */
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

// char	*get_path_command(char **paths, char *command)
// {
// 	int		i;
// 	int		j;
// 	char	*temp;
// 	char	*path;

// 	i = 0;
// 	j = -1;
// 	if ((command == NULL) | (paths[0] == NULL)
// 		| (ft_strcmp(command, "Error") == 0))
// 		return (ft_strdup("Error"));
// 	while (j != 0 && paths[i])
// 	{
// 		temp = ft_strjoin(paths[i++], "/");
// 		temp = ft_strjoin(temp, command);
// 		j = access(temp, F_OK);
// 		path = ft_strdup(temp);
// 		free(temp);
// 	}
// 	if (j == 0)
// 		return (path);
// 	return (NULL);
// }

char	*get_path_command(char **paths, char *command)
{
	int		i;
	int		j;
	char	*temp;
	char	*temp2;
	char	*path;

	i = 0;
	j = -1;
	if ((command == NULL) | (paths[0] == NULL))
		return (ft_calloc2(1, 1));
	while (j != 0 && paths[i])
	{
		temp = ft_strjoin(paths[i++], "/");
		temp2 = ft_strjoin(temp, command);
		j = access(temp2, F_OK);
		if(j == 0)
			path = ft_strdup(temp2);
		free(temp);
		free(temp2);
	}
	if (j == 0)
		return (path);
	return (ft_calloc2(1, 1));
}

char	*no_args_cmd(char *cmd)
{
	int		i;
	int		j;
	char	*first_cmd;

	i = 0;
	j = 0;
	if (cmd == NULL)
		return (ft_strdup("Error"));
	while (cmd[i] && cmd[i] != ' ')
		i++;
	if (ft_strlen(cmd) == (size_t)i)
		return (ft_strdup(cmd));
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
