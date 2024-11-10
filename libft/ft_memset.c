/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:41:39 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/10 11:07:46 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = str;
	while (i < n)
	{
		ptr[i] = c;
		i++;
	}
	return (str);
}
/* 
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str1[11] = "0123456789";
	char	str2[11] = "0123456789";

	memset(str1, '#', 4);
	str1[10] = '\0';
	ft_memset(str2, '#', 4);
	str2[10] = '\0';
	printf("Intended result	: %s \n", str1);
	printf("Our result	: %s", str2);
	return (0);
} */
