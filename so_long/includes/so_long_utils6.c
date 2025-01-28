/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils6.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:10:35 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/28 15:28:40 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	is_map_error(char *path)
{
	int	test;
	char	**map2;
	char 	**map;
	char *str;

	test = 0;
	str = read_txt(path);
	map = df(str);
	if (ft_strlen(str) < 17 | is_missletter(map) == 1)
		return (free(str), cleanexit(map), 1);
	free(str);
	if (if_wall(map) == 0)
		return (cleanexit(map), 1);
	if (at_least_one(map) == 0)
		return (cleanexit(map), 1);
	map2 = strdup_2d(map);
	step(map2);
	step2(map2);
	if (is_c(map2) == 1)
		test = 1;
	if (is_exit(map2, 0, 0) == 0)
		test = 1;
	(cleanexit(map2), cleanexit(map));
	return (test);
}

/* int     main(void)
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
} */
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
