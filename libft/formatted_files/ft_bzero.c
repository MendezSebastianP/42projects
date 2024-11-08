/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:39:16 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/08 12:07:28 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

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
/* 
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str1[50] = "Testons si ca marche ou pas";
	char	str2[50] = "Testons si ca marche ou pas";

	// int str1[10] = {1,2,3,4,5,6,7,8,9,0};
	// int str2[10] = {1,2,3,4,5,6,7,8,9,0};
	printf("Intended result before: %s \n", str1);
	printf("Our result	before: %s \n", str2);
	bzero(str1 + 8, 4);
	ft_bzero(str2 + 8, 4);
	printf("Intended result: %s \n", str1);
	printf("Our result		: %s", str2);
	return (0);
} */
