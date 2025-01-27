/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:31:04 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/27 18:34:14 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

int	n_c(char **map)
{
	int	i;
	int	j;
	int	c;

	j = 0;
	c = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'C')
				c++;
			i++;
		}
		j++;
	}
	return (c);
}
char	**df(char *str)
{
	char	**df;
	
	df = ft_split(str, '\n');
	return (df);
}

char    *read_txt(char *file)
{
	int	fd;
	char	*line;
	char	*map;
	char	*temp;
	
	map = ft_calloc(1,1);
        fd =  open(file, O_RDONLY);
	if (fd == -1)
		return(perror("Error opening the file"), NULL);
	line = get_next_line(fd);
	while (line != NULL)
	{
		temp = ft_strjoin(map, line);
		(free(line), free(map));
		map = ft_strdup(temp);
		free(temp);
		line = get_next_line(fd);
	}
	free (line);
	close(fd);
	return (map);
}

int	str_len_2d(char **str)
{
	int	j;

	j = 0;
	while (str[j])
	{
		j++;
	}
	return (j);
}
