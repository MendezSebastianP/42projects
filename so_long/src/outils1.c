/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:31:04 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/18 17:07:11 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

char	*ft_strjoin(char const *s1, const char *s2)
{
	char	*t;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	t = malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (t == NULL)
		return (NULL);
	while (s1[i])
	{
		t[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		t[i + j] = s2[j];
		j++;
	}
	t[i + j] = '\0';
	return (t);
}

int	isin(const char *set, const char c)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*t;
	size_t	i;
	size_t	nitems;

	i = 0;
	nitems = ft_strlen(s);
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

void	*ft_calloc(size_t nitems, size_t size)
{
	unsigned char	*t;
	size_t			i;
	size_t			k;

	i = 0;
	k = nitems * size;
	t = malloc(k);
	if (t == NULL || (size != 0 && k / size != nitems))
		return (NULL);
	while (nitems * size > i)
	{
		t[i] = 0;
		i++;
	}
	return (t);
}
