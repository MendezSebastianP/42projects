/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:38:45 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/18 17:12:03 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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


int	isin1(const char *set, const char c, int buffersize)
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
