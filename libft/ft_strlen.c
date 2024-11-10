/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:42:02 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/10 14:07:22 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
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
