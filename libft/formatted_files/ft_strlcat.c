/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:41:55 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/10 13:59:18 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
		j++;
	if (i >= size)
		return (j + size);
	k = 0;
	while (k + i < size - 1 && src[k] != '\0')
	{
		dest[i + k] = src[k];
		k++;
	}
	dest[i + k] = '\0';
	while (k < size - 1 && src[k] != '\0')
		k++;
	return (k + i);
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	//char	stra[15] = "123";
	//char	stra1[] = "123";
	char	strb[15] = "123";
	char	strb1[] = "123";
	int		cat1;
	//int		cat2;

	//cat2 = strlcat(stra, stra1, 5);
	cat1 = ft_strlcat(strb, strb1, 5);
	//printf("intended result	: %d \n", cat2);
	printf("our result	: %d \n", cat1);
	printf("dest: %s", strb);
	return (0);
} */
