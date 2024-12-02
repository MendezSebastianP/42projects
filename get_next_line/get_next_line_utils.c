/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:38:45 by smendez-          #+#    #+#             */
/*   Updated: 2024/12/02 12:38:33 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	if (!c)
		return (0);
	while (c[i] != '\0')
		i++;
	return (i);
}
void	ft_bzero(void *str, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = str;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}
void	*ft_calloc(size_t nitems, size_t size)
{
	unsigned char	*t;
	size_t			i;
	size_t			k;

	i = 0;
	k = nitems * size;
	if ((size != 0 && k / size != 2147483647))
		return (NULL);
	t = malloc(k);
	if (t == NULL)
		return (NULL);
	while (nitems * size > i)
	{
		ft_bzero(t, k);
	}
	return (t);
}

int	isin(const char *set, const char c, int buffersize)
{
	int	i;

	i = 0;
	while (buffersize > i)
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

