/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:37:03 by smendez-          #+#    #+#             */
/*   Updated: 2025/02/01 11:08:02 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup1(const char *s, int line)
{
	char	*t;
	size_t	i;
	size_t	nitems;

	i = 0;
	nitems = 0;
	while (s[nitems])
	{
		if (nitems > 0 && s[nitems - 1] == '\n' && line == 1)
			break ;
		nitems++;
	}
	t = malloc(nitems * sizeof(char) + 1);
	if (t == NULL)
		return (NULL);
	while (nitems > i)
	{
		t[i] = s[i];
		i++;
	}
	t[i] = '\0';
	return (t);
}

char	*ft_straddend(char *malloc1, char *toadd, int buffersize)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!toadd)
		return (malloc1);
	if (!malloc1)
		return (ft_strdup1(toadd, 0));
	str = ft_calloc(sl(malloc1) + sl(toadd) + 1, 1);
	if (!str)
		return (NULL);
	while (malloc1[i])
	{
		str[i] = malloc1[i];
		i++;
	}
	while (buffersize > j && toadd[j])
	{
		str[i + j] = toadd[j];
		j++;
	}
	free(malloc1);
	return (str);
}

char	*ft_resetsc(char *sc)
{
	int		i;
	char	*newlloc;

	i = 0;
	if (!sc)
		return (NULL);
	while (sc[i] && sc[i] != '\n')
		i++;
	if (!sc[i])
	{
		free(sc);
		return (ft_calloc(1, 1));
	}
	newlloc = ft_strdup1(sc + i + 1, 0);
	if (!newlloc)
	{
		free(sc);
		return (ft_calloc(1, 1));
	}
	free(sc);
	return (newlloc);
}

char	*freenull(char **sc)
{
	free(*sc);
	*sc = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*sc;
	char		*b1;
	char		*line;
	int			n;

	b1 = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!b1)
		return (NULL);
	if (!sc)
		sc = ft_calloc(1, sizeof(char));
	if (!sc)
		return (free(b1), NULL);
	n = 1;
	while (isin1(sc, '\n', sl(sc)) == 0 && n > 0)
	{
		n = read(fd, b1, BUFFER_SIZE);
		sc = ft_straddend(sc, b1, n);
		if (!sc)
			return (free(b1), freenull(&sc));
	}
	if (n < 0 || (!sc[0] && n == 0))
		return (free(b1), freenull(&sc));
	line = ft_strdup1(sc, 1);
	sc = ft_resetsc(sc);
	return (free(b1), line);
}
