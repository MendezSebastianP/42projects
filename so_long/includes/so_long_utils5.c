/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:43:45 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/28 17:47:16 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	step2(char **map)
{
	int		i;
	int		j;
	int		bomb;
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
					(foward(map, j, i), bomb = 0);
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
			p++;
		if (isin(map[j], 'C'))
			c = 1;
		if (isin(map[j], 'E'))
			e++;
		j++;
	}
	if (p == 1 && c == 1 && e == 1)
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

char	**strdup_2d(char **s)
{
	char	**t;
	int		i;
	int		j;
	int		nitems;

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
