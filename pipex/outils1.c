/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:03:26 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/15 12:03:33 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	isin(const char *set, const char c)
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

static int	ft_strlentrim(const char *c, const char *set)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (c[k])
		k++;
	while (isin(set, c[i]) == 1)
		i++;
	while (isin(set, c[k - 1]) == 1)
		k--;
	if (k < i)
		return (0);
	return (k - i);
}

char	*ft_strtrim(char const *s1, const char *set)
{
	unsigned char	*t;
	size_t			i;
	size_t			j;
	size_t			sizetrim;

	i = 0;
	j = 0;
	sizetrim = ft_strlentrim(s1, set);
	t = malloc(sizetrim * sizeof(char) + 1);
	if (t == NULL)
		return (NULL);
	while (isin(set, s1[i]) == 1)
		i++;
	while (j < sizetrim)
	{
		t[j] = s1[i + j];
		j++;
	}
	t[j] = '\0';
	return ((char *)t);
}

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
