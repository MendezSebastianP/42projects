/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:10:35 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/18 18:39:49 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

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

char	**df(char *str)
{
	char	**df;
	
	df = ft_split(str, '\n');
	return (df);
}

int     main(void)
{
	char *str;
	char **df1;
	int	i;
	
	i = 0;
	str = read_txt("map.ber");
	df1 = df(str);
	while(df1[i])
		ft_printf_fd(1, "%s\n", df1[i++]);
	cleanexit(df1);
	free(str);
        return (0);
}