/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:31:04 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/28 13:02:34 by smendez-         ###   ########.fr       */
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
