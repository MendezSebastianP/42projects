/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:42:02 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/04 12:42:03 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int ft_strlen(const char *c)
{
	size_t i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

// another code option proposed at memcpy
#include <string.h>
#include <stdio.h>

int main(void)
{
	char *a = "Vamos a contar";
	printf("Intended result: %ld \n", strlen(a));
	printf("Our result	 : %d", ft_strlen(a));
	return (0);
}
