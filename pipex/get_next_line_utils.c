/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:38:45 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/14 15:27:43 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	sl(const char *c)
{
	size_t	i;

	i = 0;
	if (!c)
		return (0);
	while (c[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t nitems, size_t size)
{
	unsigned char	*t;
	size_t			i;
	size_t			k;

	i = 0;
	if (size != 0 && (nitems * size) / size != nitems)
		return (NULL);
	k = nitems * size;
	t = malloc(k);
	if (!t)
		return (NULL);
	while (nitems * size > i)
	{
		t[i] = 0;
		i++;
	}
	return (t);
}

int	isin(const char *set, const char c, int buffersize)
{
	int	i;

	i = 0;
	if (!set)
		return (0);
	while (buffersize > i)
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	j;
	int	lens1;
	int	lens2;

	i = 0;
	j = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	j = s1[i] - s2[i];
	return (j);
}


void	ft_until_limiter(char *argv[])
{
	char	*line;
	char	*delimiter;
	int	bomb;

	bomb = 0;
	delimiter = ft_strjoin(argv[2], "\n");
	while(bomb == 0)
	{
		line = get_next_line(0);
		if (ft_strcmp(delimiter, line) == 0)
			bomb = 1;
	}
}
