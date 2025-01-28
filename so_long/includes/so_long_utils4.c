/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:43:45 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/28 14:59:59 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	foward(char **map, int j, int i)
{
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

int	if_wall(char **map)
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
		if (map[i][p] != '1' || map[i][j - 1] != '1')
			return (0);
		i++;
	}
	p = 0;
	while (j > 0)
	{
		if (map[i - 1][j - 1] != '1' || map[p][j - 1] != '1')
			return (0);
		j--;
	}
	return (1);
}
