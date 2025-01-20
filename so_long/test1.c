/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:10:35 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/20 16:00:43 by smendez-         ###   ########.fr       */
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

void	step(char **map)
{
	int	i;
	int	j;
	
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'P')
				map[j][i] = 'X';
			i++;
		}
		j++;
	}
}

int	equalto_one(char base, char a, char b)
{
	int	k;

	k = 0;
	if (base == a || base == b)
		k = 1;
	return (k);
}

void foward(char **map, int j, int i)
{
	char *a = map[j];
	if (map[j][i - 1] && equalto_one(map[j][i - 1], '0', 'C'))
		map[j][i - 1] = 'X';
	if (map[j][i + 1] && equalto_one(map[j][i + 1], '0', 'C'))
		map[j][i + 1] = 'X';
	if (map[j - 1] && map[j - 1][i] && equalto_one(map[j - 1][i], '0', 'C'))
		map[j - 1][i] = 'X';
	if (map[j + 1] && map[j + 1][i] && equalto_one(map[j + 1][i], '0', 'C'))
		map[j + 1][i] = 'X';
}

int	if_foward(char **map, int j, int i)
{
	int	k;

	k = 0;
	if (map[j][i - 1] && equalto_one(map[j][i - 1], '0', 'C'))
		k = 1;
	if (map[j][i + 1] && equalto_one(map[j][i + 1], '0', 'C'))
		k = 1;
	if (map[j - 1] && map[j - 1][i] && equalto_one(map[j - 1][i], '0', 'C'))
		k = 1;
	if (map[j + 1] && map[j + 1][i] && equalto_one(map[j + 1][i], '0', 'C'))
		k = 1;
	return (k);
}

int if_rectangle(char **map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 1;
	while (map[i])
		i++;
	while (map[0][j])
		j++;
	if (i == j)
		k = 0;
	return (k);
}

int if_wall(char **map)
{
	int	i;
	int	j;
	int	p;
	int	k;

	i = 0;
	j = 0;
	p = 0;
	k = 1;
	while (map[0][j])
		j++;
	while (map[i])
	{
		if(map[i][p] != '1' || map[i][j - 1] != '1')
			return(0);
		i++;
	}
	p = 0;
	while (j > 0)
	{
		if(map[i - 1][j - 1] != '1' || map[p][j - 1] != '1')
			return(0);
		j--;
	}
	return (1);
}
	


void	step2(char **map)
{
	int	i;
	int	j;
	int	bomb;
	char	*o;
	
	bomb = 0;
	while (bomb == 0)
	{
		bomb = 1;
		j = 0;
		while (map[j])
		{
			i = 0;
			o = map[j];
			while (map[j][i])
			{
				if (map[j][i] == 'X' && if_foward(map, j, i))
				{
					foward(map, j, i);
					bomb = 0;
				}
				i++;
			}
			j++;
		}
	}
}

int     main(void)
{
	char *str;
	char **df1;
	int	i;
	
	i = 0;
	str = read_txt("map7.ber");
	df1 = df(str);
	printf("test map1: %d\n", if_wall(df1));
	while(df1[i])
		ft_printf_fd(1, "%s\n", df1[i++]);
	printf("\n\n");
	step(df1);
	step2(df1);
	i = 0;
	printf("test map2: %d\n", if_wall(df1));
	while(df1[i])
		ft_printf_fd(1, "%s\n", df1[i++]);
	
	cleanexit(df1);
	free(str);
        return (0);
}