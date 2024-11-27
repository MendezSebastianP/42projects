/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlennull.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:42:02 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/27 10:48:28 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlennull(const char *c)
{
	size_t	i;

	i = 0;
	if (c == NULL)
		return (6);
	while (c[i] != '\0')
		i++;
	return (i);
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*a;

	a = "123456";
	printf("Intended result	: %ld \n", strlen(a));
	printf("Our result	: %d", ft_strlen(a));
	return (0);
} */
