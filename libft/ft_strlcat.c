/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:41:55 by smendez-          #+#    #+#             */
/*   Updated: 2024/11/04 12:41:56 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
		size_t  i;
		size_t  j;
		size_t  k;

		i = 0;
		j = 0;
		while (i < size && dest[i] != '\0')
		i++;

	while (src[j] != '\0')
		j++;

	if (i == size)
		return (size + j);
	k = 0;
	while ((i + k + 1) < size && src[k] != '\0')
	{
		dest[i + k] = src[k];
		k++;
	}
	dest[i + i] = '\0';

	return (i + j);
}

#include <string.h>
#include <stdio.h>

int main() {
		char stra[6] = "123";
		char stra1[] = "123";
		char strb[6] = "123";
		char strb1[] = "123";
		int cat1;
		int cat2;

		cat2 = strlcat(stra, stra1, 6);
		cat1 = ft_strlcat(strb, strb1, 6);
		printf("intended result: %d \n", cat2);
		printf("our result	 : %d", cat1);
		printf("dest: %s", stra);
		return (0);
}

