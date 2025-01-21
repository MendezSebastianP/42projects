/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:10:35 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/21 15:20:21 by smendez-         ###   ########.fr       */
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
int	is_c(char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'C')
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}
int	at_least_one(char **map)
{
	int	j;
	int	p;
	int	c;
	int	e;

	j = 0;
	p = 0;
	c = 0;
	e = 0;
	while (map[j])
	{
		if (isin(map[j], 'P'))
			p = 1;
		if (isin(map[j], 'C'))
			c = 1;
		if (isin(map[j], 'E'))
			e = 1;	
		j++;
	}
	if (p + c + e == 3)
		return (1);
	return (0);
}

int	is_missletter(char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (isin("01PCE", map[j][i]) == 0)
				return (1);
			i++;
		}
		j++;
	}
	return (0);
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

char	**strdup_2d(char **s)
{
	char	**t;
	int	i;
	int	j;
	int	nitems;

	i = 0;
	j = 0;
	nitems = str_len_2d(s);
	t = malloc((nitems + 1) * sizeof(char *));
	if (t == NULL)
		return (NULL);
	while (nitems > i)
	{
		t[i] = ft_strdup(s[i]);
		i++;
	}
	t[i] = NULL;
	return (t);
}

int	is_exit(char **map, int i, int j)
{
	int	k;

	k = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'E')
			{
				if (map[j][i - 1] == 'X')
					k = 1;
				if (map[j][i + 1] == 'X')
					k = 1;
				if (map[j - 1][i] == 'X')
					k = 1;
				if (map[j + 1][i] == 'X')
					k = 1;
			}
			i++;
		}
		j++;
	}
	return (k);
}

int	is_map_error(char **map)
{
	int	test;
	char	**map2;

	test = 0;
	if (is_missletter(map) == 1)
		return (0);
	if (if_wall(map) == 0)
		return (0);
	if (if_rectangle(map) == 0)
		return (0);
	if (at_least_one(map) == 0)
		return (0);
	map2 = strdup_2d(map);
	step(map2);
	step2(map2);
	if (is_c(map2) == 1)
		test = 1;
	if (is_exit(map2, 0, 0) == 0)
		test = 1;
	cleanexit(map2);
	return (test);
}

int     main(void)
{
	char *str;
	char **df1;
	int	i;
	
	i = 0;
	str = read_txt("map8.ber");
	df1 = df(str);
	printf("test: %d\n", is_map_error(df1));
	while(df1[i])
		ft_printf_fd(1, "%s\n", df1[i++]);
	printf("\n\n");
	step(df1);
	step2(df1);
	i = 0;
	printf("test: %d\n", is_exit(df1, 0, 0));
	while(df1[i])
		ft_printf_fd(1, "%s\n", df1[i++]);
	cleanexit(df1);
	free(str);
        return (0);
}
/* int main(int argc, char **argv)
{
	char **t = ft_split(argv[1], ' ');
	char **k = strdup_2d(t);
	int i = 0;
	while(k[i])
		printf("%s\n", k[i++]);
	cleanexit(t);
	cleanexit(k);
	return (0);
} */
